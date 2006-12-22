//
// AsyncChannel.h
//
// $Id: //poco/Main/Foundation/include/Poco/AsyncChannel.h#2 $
//
// Library: Foundation
// Package: Logging
// Module:  AsyncChannel
//
// Definition of the AsyncChannel class.
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


#ifndef Foundation_AsyncChannel_INCLUDED
#define Foundation_AsyncChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"
#include "Poco/Thread.h"
#include "Poco/Mutex.h"
#include "Poco/Runnable.h"
#include "Poco/NotificationQueue.h"


namespace Poco {


class Foundation_API AsyncChannel: public Channel, public Runnable
	/// A channel uses a separate thread for logging.
	///
	/// Using this channel can help to improve the performance of
	/// applications that produce huge amounts of log messages or
	/// that write log messages to multiple channels simultaneously.
	///
	/// All log messages are put into a queue and this queue is
	/// then processed by a separate thread.
{
public:
	AsyncChannel(Channel* pChannel = 0);
		/// Creates the AsyncChannel and connects it to
		/// the given channel.

	void setChannel(Channel* pChannel);
		/// Connects the AsyncChannel to the given target channel.
		/// All messages will be forwarded to this channel.
		
	Channel* getChannel() const;
		/// Returns the target channel.

	void open();
		/// Opens the channel and creates the 
		/// background ;ogging thread.
		
	void close();
		/// Closes the channel and stops the background
		/// logging thread.

	void log(const Message& msg);
		/// Queues the message for processing by the
		/// background thread.

	void setProperty(const std::string& name, const std::string& value);
		/// Sets or changes a configuration property.
		///
		/// Only the "channel" property is supported, which allows
		/// setting the target channel via the LoggingRegistry.
		/// The "channel" property is set-only.
	
protected:
	~AsyncChannel();
	void run();
		
private:
	Channel*  _pChannel;
	Thread    _thread;
	FastMutex _mutex;
	NotificationQueue _queue;
};


} // namespace Poco


#endif // Foundation_AsyncChannel_INCLUDED
