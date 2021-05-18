#include <string>
#include <list>

namespace engine
{
	struct Resource;

	struct ResourceManager
	{
	public:
		//template <typename T>
		//std::shared_ptr<T> load(std::string path);
		//template <typename T>
		//std::shared_ptr<T> create();



	private:
		std::list<std::shared_ptr<Resource>> resources;
	};
}