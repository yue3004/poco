//
// Token.cpp
//
// $Id: //poco/Main/Foundation/src/Token.cpp#11 $
//
// Library: Foundation
// Package: Streams
// Module:  StringTokenizer
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


#include "Poco/Token.h"
#include "Poco/NumberParser.h"
#include <ctype.h>


namespace Poco {


Token::Token()
{
}


Token::~Token()
{
}


bool Token::start(char c, std::istream& istr)
{
	_value = c;
	return false;
}


void Token::finish(std::istream& istr)
{
}


Token::Class Token::tokenClass() const
{
	return INVALID_TOKEN;
}

		
std::string Token::asString() const
{
	return _value;
}


int Token::asInteger() const
{
	return NumberParser::parse(_value);
}


double Token::asFloat() const
{
	return NumberParser::parseFloat(_value);
}


char Token::asChar() const
{
	return _value.empty() ? 0 : _value[0];
}


InvalidToken::InvalidToken()
{
}


InvalidToken::~InvalidToken()
{
}


Token::Class InvalidToken::tokenClass() const
{
	return INVALID_TOKEN;
}


EOFToken::EOFToken()
{
}


EOFToken::~EOFToken()
{
}


Token::Class EOFToken::tokenClass() const
{
	return EOF_TOKEN;
}


WhitespaceToken::WhitespaceToken()
{
}


WhitespaceToken::~WhitespaceToken()
{
}


Token::Class WhitespaceToken::tokenClass() const
{
	return WHITESPACE_TOKEN;
}


bool WhitespaceToken::start(char c, std::istream& istr)
{
	if (isspace(c))
	{
		_value = c;
		return true;
	}
	return false;
}


void WhitespaceToken::finish(std::istream& istr)
{
	int c = istr.peek();
	while (isspace(c))
	{
		istr.get();
		_value += (char) c;
		c = istr.peek();
	}
}


} // namespace Poco
