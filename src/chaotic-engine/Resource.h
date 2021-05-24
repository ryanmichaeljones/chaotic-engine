#ifndef ENGINE_RESOURCE_H
#define ENGINE_RESOURCE_H

#include <string>
#include <memory>

namespace engine
{
	struct Core;
	struct Resources;

	struct Resource
	{
	public:
		virtual ~Resource();
		virtual void onLoad();

		std::string getPath();
		std::shared_ptr<Core> getCore();

	private:
		friend struct engine::Resources;

		std::string path;
		std::weak_ptr<Core> core;

	};
}
#endif