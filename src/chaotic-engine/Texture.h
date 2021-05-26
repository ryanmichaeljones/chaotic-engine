#include "Resource.h"

#include <rend/rend.h>

#include <memory>

namespace engine
{
	struct Texture : public Resource
	{
	public:
		void onLoad();
		std::shared_ptr<rend::Texture> getTexture();

	private:
		std::shared_ptr<rend::Texture> texture;

	};
}