#include "Component.h"

#include <rend/rend.h>
#include <memory>

namespace engine
{
	struct Renderer : public Component
	{
	public:
		void onInitialize();
		void setColor(rend::vec4 color);
		void onRender();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Buffer> shape;
		rend::vec4 color;
	};
}
