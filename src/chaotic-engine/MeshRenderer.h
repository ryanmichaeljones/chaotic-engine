#ifndef ENGINE_MESHRENDERER_H
#define ENGINE_MESHRENDERER_H

#include "Component.h"

#include <rend/rend.h>

namespace engine
{
	struct Texture;

	struct MeshRenderer : public Component
	{
	public:
		void onInitialize(std::string path);
		void onRender();

		void setTexture(std::shared_ptr<Texture> _texture);
		void setShader(std::string vertex, std::string fragment);

	private:
		std::string vertexShader;
		std::string fragmentShader;

		std::shared_ptr<engine::Texture> texture;
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::Buffer> shape;
		std::shared_ptr<rend::Buffer> texCoord;

	};
}
#endif