//
// ActiveRunnable.h
//
// $Id: //poco/Main/Foundation/include/Poco/ActiveRunnable.h#3 $
//
// Library: Foundation
// Package: Threading
// Module:  ActiveObjects
//
// Definition of the ActiveRunnable class.
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


#ifndef Foundation_ActiveRunnable_INCLUDED
#define Foundation_ActiveRunnable_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/ActiveResult.h"
#include "Poco/Runnable.h"
#include "Poco/Exception.h"


namespace Poco {


template <class ResultType, class ArgType, class OwnerType>
class ActiveRunnable: public Runnable
	/// This class is used by ActiveMethod.
	/// See the ActiveMethod class for more information.
{
public:
	typedef ResultType (OwnerType::*Callback)(const ArgType&);
	typedef ActiveResult<ResultType> ActiveResultType;

	ActiveRunnable(OwnerType* pOwner, Callback method, const ArgType& arg, const ActiveResultType& result):
		_pOwner(pOwner),
		_method(method),
		_arg(arg),
		_result(result)
	{
		poco_check_ptr (pOwner);
	}

	void run()
	{
		try
		{
			_result.data(new ResultType((_pOwner->*_method)(_arg)));
		}
		catch (Exception& e)
		{
			_result.error(e);
		}
		catch (std::exception& e)
		{
			_result.error(e.what());
		}
		catch (...)
		{
			_result.error("unknown exception");
		}
		_result.notify();
		delete this;
	}

private:
	OwnerType* _pOwner;
	Callback   _method;
	ArgType    _arg;
	ActiveResultType _result;
};


} // namespace Poco


#endif // Foundation_ActiveRunnable_INCLUDED
