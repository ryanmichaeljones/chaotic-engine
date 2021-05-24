#include "Resource.h"

namespace engine
{
	Resource::~Resource() { }
	void Resource::onLoad() { }

	std::string Resource::getPath()
	{
		return path;
	}

	std::shared_ptr<Core> Resource::getCore()
	{
		return core.lock();
	}
}