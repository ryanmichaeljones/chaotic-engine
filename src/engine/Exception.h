#ifndef ENGINE_EXCEPTION_H
#define ENGINE_EXCEPTION_H
#include <exception>
#include <string>

namespace engine
{
	struct Exception
	{
	public:
		Exception(const std::string& message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();

	private:
		std::string message;
	};
}

#endif