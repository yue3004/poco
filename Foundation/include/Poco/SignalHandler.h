//
// SignalHandler.h
//
// $Id: //poco/Main/Foundation/include/Poco/SignalHandler.h#2 $
//
// Library: Foundation
// Package: Threading
// Module:  SignalHandler
//
// Definition of the SignalHandler class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_SignalHandler_INCLUDED
#define Foundation_SignalHandler_INCLUDED


#include "Poco/Foundation.h"


#if defined(POCO_OS_FAMILY_UNIX)


#include <vector>
#include <setjmp.h>


namespace Poco {


class Foundation_API SignalHandler
	/// This helper class simplifies the handling of POSIX signals.
	///
	/// The class provides a signal handler (installed with
	/// installHandlers()) that translates certain POSIX
	/// signals (SIGILL, SIGBUS, SIGSEGV, SIGSYS) into 
	/// C++ exceptions.
	///
	/// Internally, a stack of sigjmp_buf structs is maintained for
	/// each thread. The constructor pushes a new sigjmp_buf onto
	/// the current thread's stack. The destructor pops the sigjmp_buf
	/// from the stack.
	///
	/// The poco_throw_on_signal macro creates an instance of SignalHandler
	/// on the stack, which results in a new sigjmp_buf being created.
	/// The sigjmp_buf is then set-up with sigsetjmp().
	///
	/// The handleSignal() method, which is invoked when a signal arrives,
	/// checks if a sigjmp_buf is available for the current thread.
	/// If so, siglongjmp() is used to jump out of the signal handler.
	///
	/// Typical usage is as follows:
	///
	///     try
	///     {
	///          poco_throw_on_signal;
	///          ...
	///     }
	///     catch (Poco::SignalException&)
	///     {
	///         ...
	///     }
	///
	/// The best way to deal with a SignalException is to log as much context
	/// information as possible, to aid in debugging, and then to exit.
{
public:
	SignalHandler();
		/// Creates the SignalHandler.

	~SignalHandler();
		/// Destroys the SignalHandler.

	sigjmp_buf& jumpBuffer();
		/// Returns the top-most sigjmp_buf for the current thread.

	static void throwSignalException(int sig);
		/// Throws a SignalException with a textual description  
		/// of the given signal as argument. 
	
	static void install();
		/// Installs signal handlers for SIGILL, SIGBUS, SIGSEGV
		/// and SIGSYS.

protected:
	static void handleSignal(int sig);
		/// The actual signal handler.

	struct JumpBuffer
		/// sigjmp_buf cannot be used to instantiate a std::vector,
		/// so we provide a wrapper struct.
	{
		sigjmp_buf buf;
	};
	typedef std::vector<JumpBuffer> JumpBufferVec;

	static JumpBufferVec& jumpBufferVec();
		/// Returns the JumpBufferVec for the current thread.

private:
	static JumpBufferVec _jumpBufferVec;
	
	friend class ThreadImpl;
};


#define poco_throw_on_signal \
	Poco::SignalHandler _poco_signalHandler; \
	int _poco_signal = sigsetjmp(_poco_signalHandler.jumpBuffer(), 1); \
	if (_poco_signal) _poco_signalHandler.throwSignalException(_poco_signal);


} // namespace Poco


#endif // POCO_OS_FAMILY_UNIX


#endif // Foundation_SignalHandler_INCLUDED
