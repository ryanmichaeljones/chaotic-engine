#include "MeshRenderer.h"
#include "Core.h"
#include "Screen.h"
#include "Transform.h"
#include "Camera.h"

#include <fstream>

namespace engine
{
	void MeshRenderer::onInitialize()
	{
	
	}

	void MeshRenderer::onRender()
	{
		const char* src =
			"\n#ifdef VERTEX\n															" \
			"attribute vec3 a_Position;													" \
			"attribute vec2 a_TexCoord;													" \
			"attribute vec3 a_Normal;													" \
			"uniform mat4 u_Projection;													" \
			"uniform mat4 u_View;														" \
			"uniform mat4 u_Model;														" \
			"varying vec2 ex_TexCoord;													" \
			"varying vec3 ex_Normal;													" \
			"void main()																" \
			"{																			" \
			"gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1);		" \
			"ex_TexCoord = a_TexCoord;													" \
			"ex_Normal = a_Normal;														" \
			"}																			" \
			"\n#endif\n																	" \
			"\n#ifdef FRAGMENT\n														" \
			"uniform sampler2D u_Texture;												" \
			"varying vec2 ex_TexCoord;													" \
			"varying vec3 ex_Normal;													" \
			"void main()																" \
			"{																			" \
			"gl_FragColor = texture2D(u_Texture, ex_TexCoord);							" \
			"if(gl_FragColor.x == 9) gl_FragColor.x = ex_Normal.x;						" \
			"}																			" \
			"\n#endif\n																	";

		shader = getCore()->context->createShader();
		shader->parse(src);

		shape = getCore()->context->createBuffer();
		mesh = getCore()->context->createMesh();
		texCoord = getCore()->context->createBuffer();

		/*shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, 0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));
		texCoord->add(rend::vec2(0.0f, 0.0f));
		texCoord->add(rend::vec2(1.0f, 1.0f));
		texCoord->add(rend::vec2(0.0f, 1.0f));
		texCoord->add(rend::vec2(1.0f, 1.0f));
		texCoord->add(rend::vec2(0.0f, 0.0f));
		texCoord->add(rend::vec2(1.0f, 0.0f));

		mesh->setBuffer("a_Position", shape);
		mesh->setBuffer("a_TexCoord", texCoord);*/

		std::ifstream f("../src/textures/cube.obj");
		if (!f.is_open())
		{
			throw std::exception("Failed to open model");
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		mesh->parse(obj);


		shader->setUniform("u_Model", getTransform()->getModel());
		shader->setUniform("u_Projection", getScreen()->getPerspective());
		shader->setSampler("u_Texture", texture);
		shader->setUniform("u_View", rend::inverse(getCore()->getCurrentCamera()->getTransform()->getModel()));
		shader->setMesh(mesh);

		shader->render();
	}

	void MeshRenderer::setTexture(std::shared_ptr<rend::Texture> _texture)
	{
		texture = _texture;
	}

	//setMesh
	//setShaders(vertex, fragment)
}