#include "Texture.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Screen.h"
#include "Camera.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace engine
{
	void Texture::onInitialize(std::string path)
	{
		setPath(path);

		const char* src =
			"\n#ifdef VERTEX\n															" \
			"attribute vec2 a_Position;													" \
			"attribute vec2 a_TexCoord;													" \
			"uniform mat4 u_Projection;													" \
			"uniform mat4 u_View;														" \
			"uniform mat4 u_Model;														" \
			"varying vec2 ex_TexCoord;													" \
			"void main()																" \
			"{																			" \
			"gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 0, 1);	" \
			"ex_TexCoord = a_TexCoord;													" \
			"}																			" \
			"\n#endif\n																	" \
			"\n#ifdef FRAGMENT\n														" \
			"uniform sampler2D u_Texture;												" \
			"varying vec2 ex_TexCoord;													" \
			"void main()																" \
			"{																			" \
			"gl_FragColor = texture2D(u_Texture, ex_TexCoord);							" \
			"}																			" \
			"\n#endif\n																	";

		shader = getCore()->context->createShader();
		shader->parse(src);

		shape = getCore()->context->createBuffer();
		texture = getCore()->context->createTexture();
		mesh = getCore()->context->createMesh();
		texCoord = getCore()->context->createBuffer();

		// Triangle Mesh
		/*shape->add(glm::vec2(0.0f, 0.5f));
		shape->add(glm::vec2(-0.5f, -0.5f));
		shape->add(glm::vec2(0.5f, -0.5f));
		texCoord->add(glm::vec2(0.0f, 0.0f));
		texCoord->add(glm::vec2(1.0f, 0.0f));
		texCoord->add(glm::vec2(0.5f, 1.0f));*/

		// Rectangle Mesh
		shape->add(rend::vec2(-0.5f, -0.5f)); 
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
		mesh->setBuffer("a_TexCoord", texCoord);
	}

	void Texture::setPath(std::string path)
	{
		this->path = path;
	}

	void Texture::onRender()
	{
		int w = 0, h = 0, channels = 0;

		unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 3);
		if (!data)
		{
			throw std::exception("Failed to load texture file");
		}

		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				texture->setPixel(x, y, rend::vec3(data[r] / 255.0f, 
					data[r + 1] / 255.0f, data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);

		shader->setUniform("u_Model", getTransform()->getModel());
		shader->setUniform("u_Projection", getScreen()->getPerspective());
		shader->setSampler("u_Texture", texture);
		//shader->setUniform("u_View", rend::inverse(getCore()->getCamera()->getTransform()->getModel()));
		shader->setUniform("u_View", rend::inverse(getCore()->camera->getTransform()->getModel()));
		shader->setMesh(mesh);

		shader->render();
	}
}