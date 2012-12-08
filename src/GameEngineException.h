#pragma once
#include <exception>
#include <string>

class GameEngineException : public std::exception
{
	public:
		GameEngineException(std::string msg)
			:message(msg)
		{}

		virtual const char* what() const throw() { return message.c_str(); }

		virtual ~GameEngineException() throw(){}

	
	protected:
		GameEngineException(){}
		std::string message;
};
