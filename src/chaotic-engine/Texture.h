#include "Component.h"

#include <rend/rend.h>
#include <memory>

namespace engine
{
	struct Texture : public Component
	{
	public:
		void onInitialize(); // default texture is loaded
		//Texture(std::string path);
		void loadTexture(std::string path);

		std::shared_ptr<rend::Texture> texture;

	private:
		std::string path;

	};
}