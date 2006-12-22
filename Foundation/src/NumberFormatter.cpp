//
// NumberFormatter.cpp
//
// $Id: //poco/Main/Foundation/src/NumberFormatter.cpp#10 $
//
// Library: Foundation
// Package: Core
// Module:  NumberFormatter
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


#include "Poco/NumberFormatter.h"
#include <stdio.h>
#include <ctype.h>


#if defined(_MSC_VER)
	#define I64_FMT "I64"
#elif defined(__APPLE__) 
	#define I64_FMT "q"
#else
	#define I64_FMT "ll"
#endif


namespace Poco {


std::string NumberFormatter::format(int value)
{
	char buffer[64];
	sprintf(buffer, "%d", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*d", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*d", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(int value)
{
	char buffer[64];
	sprintf(buffer, "%X", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*X", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(unsigned value)
{
	char buffer[64];
	sprintf(buffer, "%u", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*u", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(unsigned int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*u", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(unsigned value)
{
	char buffer[64];
	sprintf(buffer, "%X", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*X", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(long value)
{
	char buffer[64];
	sprintf(buffer, "%ld", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*ld", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*ld", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(long value)
{
	char buffer[64];
	sprintf(buffer, "%lX", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*lX", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(unsigned long value)
{
	char buffer[64];
	sprintf(buffer, "%lu", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*lu", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*lu", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(unsigned long value)
{
	char buffer[64];
	sprintf(buffer, "%lX", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*lX", width, value);
	return std::string(buffer);
}


#if defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


std::string NumberFormatter::format(Int64 value)
{
	char buffer[64];
	sprintf(buffer, "%"I64_FMT"d", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*"I64_FMT"d", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*"I64_FMT"d", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(Int64 value)
{
	char buffer[64];
	sprintf(buffer, "%"I64_FMT"X", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*"I64_FMT"X", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(UInt64 value)
{
	char buffer[64];
	sprintf(buffer, "%"I64_FMT"u", value);
	return std::string(buffer);
}


std::string NumberFormatter::format(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%*"I64_FMT"u", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::format0(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*"I64_FMT"u", width, value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(UInt64 value)
{
	char buffer[64];
	sprintf(buffer, "%"I64_FMT"X", value);
	return std::string(buffer);
}


std::string NumberFormatter::formatHex(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	sprintf(buffer, "%0*"I64_FMT"X", width, value);
	return std::string(buffer);
}


#endif // defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


std::string NumberFormatter::format(float value)
{
	char buffer[64];
	sprintf(buffer, "%.*g", 10, (double) value);
	return std::string(buffer);
}


std::string NumberFormatter::format(double value)
{
	char buffer[64];
	sprintf(buffer, "%.*g", 20, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(double value, int precision)
{
	poco_assert (precision >= 0 && precision < 32);

	char buffer[64];
	sprintf(buffer, "%.*f", precision, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(double value, int width, int precision)
{
	poco_assert (width > 0 && width < 64 && precision >= 0 && precision < width);

	char buffer[64];
	sprintf(buffer, "%*.*f", width, precision, value);
	return std::string(buffer);
}


std::string NumberFormatter::format(const void* ptr)
{
	char buffer[24];
#if defined(POCO_PTR_IS_64_BIT)
	sprintf(buffer, "%016"I64_FMT"X", (UIntPtr) ptr);
#else
	sprintf(buffer, "%08lX", (UIntPtr) ptr);
#endif
	return std::string(buffer);
}


} // namespace Poco
