#include "Texture.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

namespace engine
{
	void Texture::onInitialize()
	{
		const char* src =
			"\n#ifdef VERTEX\n						" \
			"uniform mat4 in_Projection; " \
			"uniform mat4 in_Model; " \
			"attribute vec3 in_Position; " \
			"attribute vec2 in_TexCoord; " \
			"varying vec2 ex_TexCoord; " \
			" " \
			"void main() " \
			"{ " \
			"gl_Position = in_Model * vec4(in_Position, 1.0); " \
			"ex_TexCoord = in_TexCoord; " \
			"} " \
			"\n#endif\n								" \
			"\n#ifdef FRAGMENT\n					" \
			"										" \
			"uniform sampler2D in_Texture; " \
			"varying vec2 ex_TexCoord; " \
			"void main() " \
			"{ " \
			"vec4 tex = texture2D(in_Texture, ex_TexCoord); " \
			"gl_FragColor = tex; " \
			"} " \
			"										" \
			"\n#endif\n								";

		shader = getCore()->context->createShader();		shader->parse(src);		shape = getCore()->context->createMesh();		texCoords = getCore()->context->createBuffer();		positions = getCore()->context->createBuffer();

		positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
		positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

		texCoords->add(glm::vec2(0.5f, 0.0f));
		texCoords->add(glm::vec2(0.0f, 1.0f));
		texCoords->add(glm::vec2(1.0f, 1.0f));
	
		shape->setBuffer("in_Position", positions);
		shape->setBuffer("in_TexCoord", texCoords);
	}

	void Texture::onRender()
	{
		int w = 0;
		int h = 0;
		int channels = 0;

		std::string path = "../src/textures/boris.jpg";
		unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);
		if (!data)
		{
			throw Exception("Failed to load texture file");
		}

		unsigned int texture = 0;
		glGenTextures(1, &texture);

		if (!texture)
		{
			throw Exception("Failed to get texture id");
		}

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//shader->setUniform("in_Texture", );

		//glActiveTexture(GL_TEXTURE0);
		//GLint uniformId = glGetUniformLocation(texture, "in_Texture");
		//glUniform1i(uniformId, 0);

		//glActiveTexture(GL_TEXTURE0);
		//glUseProgram(texture);
		//glUniform1i(uniformId, 1);

		//glUseProgram(0);

		shader->setMesh(shape);
		shader->setUniform("in_Model", getEntity()->getTransform()->getModel());
		shader->render();
	}
}