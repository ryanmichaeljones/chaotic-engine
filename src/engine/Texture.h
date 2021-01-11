#include "Component.h"

#include <rend/rend.h>
#include <memory>

namespace engine
{
	struct Texture : public Component
	{
	public:
		void onInitialize();
		void onRender();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> shape;
		std::shared_ptr<rend::Buffer> texCoords;
		std::shared_ptr<rend::Buffer> positions;
	};
}
