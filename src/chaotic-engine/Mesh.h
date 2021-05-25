#include "Resource.h"

#include <rend/rend.h>

#include <memory>
#include <fstream>

namespace engine
{
	struct Mesh : public Resource
	{
	public:
		void onLoad();
		std::shared_ptr<rend::Mesh> getMesh();

	private:
		std::shared_ptr<rend::Mesh> mesh;

	};
}