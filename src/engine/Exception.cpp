#include "Exception.h"

namespace engine
{
	///<summary>
	/// Constructor which stores the exception message.
	///</summary>
	Exception::Exception(const std::string& message)
	{
		this->message = message;
	}

	///<summary>
	/// Throws an exception with no message.
	///</summary>
	Exception::~Exception() throw(){ }

	///<summary>
	/// Throws an exception with a message.
	///</summary>
	const char* Exception::what() const throw()
	{
		return message.c_str();
	}
}