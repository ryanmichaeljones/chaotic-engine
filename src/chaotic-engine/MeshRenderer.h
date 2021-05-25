#ifndef ENGINE_MESHRENDERER_H
#define ENGINE_MESHRENDERER_H

#include "Component.h"

#include <rend/rend.h>

namespace engine
{
	struct Texture;
	struct Shader;
	struct Mesh;

	struct MeshRenderer : public Component
	{
	public:
		void onInitialize(std::shared_ptr<Texture> _texture, std::shared_ptr<Shader> _shader, std::shared_ptr<Mesh> _mesh);
		void onInitialize(std::string path);
		void onInitialize();
		void onRender();

		void setTexture(std::shared_ptr<Texture> _texture);
		void setShader(std::shared_ptr<Shader> _shader);
		void setMesh(std::shared_ptr<Mesh> _mesh);

	private:
		std::shared_ptr<engine::Texture> texture;
		std::shared_ptr<engine::Shader> shader;
		std::shared_ptr<engine::Mesh> mesh;

	};
}
#endif