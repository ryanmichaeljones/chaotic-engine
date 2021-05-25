#include "MeshRenderer.h"
#include "Core.h"
#include "Resources.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Screen.h"
#include "Transform.h"
#include "Camera.h"

#include <fstream>

namespace engine
{
	void MeshRenderer::onInitialize(std::shared_ptr<Texture> _texture, std::shared_ptr<Shader> _shader, std::shared_ptr<Mesh> _mesh)
	{
		setTexture(_texture);
		setShader(_shader);
		setMesh(_mesh);
	}

	void MeshRenderer::onInitialize(std::string path)
	{
		setTexture(getCore()->getResources()->load<Texture>("../src/textures/" + path));

		// change to inputs
		setShader(getCore()->getResources()->load<Shader>("../src/shaders/texture.shader"));
		setMesh(getCore()->getResources()->load<Mesh>("../src/models/cube.obj"));
	}

	void MeshRenderer::onInitialize()
	{
		// Default
		setTexture(getCore()->getResources()->load<Texture>("../src/textures/missingtexture.jpg"));
		setShader(getCore()->getResources()->load<Shader>("../src/shaders/texture.shader")); // add a missingshader.shader
		setMesh(getCore()->getResources()->load<Mesh>("../src/models/cube.obj")); //add a missingobj.obj
	}

	void MeshRenderer::onRender()
	{
		shader->getShader()->setUniform("u_Model", getTransform()->getModel());
		shader->getShader()->setUniform("u_Projection", getScreen()->getPerspective());
		shader->getShader()->setSampler("u_Texture", texture->getTexture());
		shader->getShader()->setUniform("u_View", rend::inverse(getCore()->getCurrentCamera()->getTransform()->getModel()));
		shader->getShader()->setMesh(mesh->getMesh());

		shader->getShader()->render();
	}

	void MeshRenderer::setTexture(std::shared_ptr<Texture> _texture)
	{
		this->texture = _texture;
	}

	void MeshRenderer::setShader(std::shared_ptr<Shader> _shader)
	{
		this->shader = _shader;
	}

	void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
	{
		this->mesh = _mesh;
	}
}