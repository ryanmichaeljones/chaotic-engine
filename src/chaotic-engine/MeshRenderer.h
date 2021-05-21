#include "Component.h"

#include <rend/rend.h>

namespace engine
{
	struct MeshRenderer : public Component
	{
	public:
		void onInitialize();
		void onRender();

		void setTexture(std::shared_ptr<rend::Texture> _texture);

	private:
		std::shared_ptr<rend::Texture> texture;
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::Buffer> shape;
		std::shared_ptr<rend::Buffer> texCoord;

	};
}