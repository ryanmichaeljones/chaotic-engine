#include "Resource.h"

#include <rend/rend.h>
#include <memory>

namespace engine
{
	struct Texture : public Resource
	{
	public:
		void onInitialize(); // default texture is loaded
		//Texture(std::string path);
		void onLoad();
		std::shared_ptr<rend::Texture> getTexture();

	private:
		std::shared_ptr<rend::Texture> texture;

	};
}