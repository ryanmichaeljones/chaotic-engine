#include "Component.h"

#include <rend/rend.h>
#include <memory>

namespace engine
{
	struct Texture : public Component
	{
	public:
		void onInitialize(std::string path);
		void setPath(std::string path);
		void onRender();

	private:
		std::string path;
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::Buffer> shape;
		std::shared_ptr<rend::Buffer> texCoord;
		std::shared_ptr<rend::Texture> texture;

	};
}