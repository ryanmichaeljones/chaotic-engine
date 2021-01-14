#include "Texture.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace engine
{
	///<summary>
	/// Initializes vertex shader and fragment shader for a triangle texture.
	///</summary>
	void Texture::onInitialize(std::string texturePath)
	{
		setTexturePath(texturePath);

		const char* src =
			"\n#ifdef VERTEX\n									" \
			"uniform mat4 in_Projection;						" \
			"uniform mat4 in_Model;								" \
			"attribute vec3 in_Position;						" \
			"attribute vec2 in_TexCoord;						" \
			"varying vec2 ex_TexCoord;							" \
			"													" \
			"void main()										" \
			"{													" \
			"gl_Position = in_Model * vec4(in_Position, 1.0);	" \
			"ex_TexCoord = in_TexCoord;							" \
			"}													" \
			"\n#endif\n											" \
			"\n#ifdef FRAGMENT\n								" \
			"													" \
			"uniform sampler2D in_Texture;						" \
			"varying vec2 ex_TexCoord;							" \
			"void main()										" \
			"{													" \
			"vec4 tex = texture2D(in_Texture, ex_TexCoord);		" \
			"gl_FragColor = tex;								" \
			"}													" \
			"													" \
			"\n#endif\n											";

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

	///<summary>
	/// Sets the path of the texture file.
	///</summary>
	void Texture::setTexturePath(std::string texturePath)
	{
		this->texturePath = texturePath;
	}

	///<summary>
	/// Renders a triangle texture to the window.
	///</summary>
	void Texture::onRender()
	{
		int w = 0;
		int h = 0;
		int channels = 0;

		unsigned char *data = stbi_load(texturePath.c_str(), &w, &h, &channels, 4);
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

		shader->setMesh(shape);
		shader->setUniform("in_Model", getEntity()->getTransform()->getModel());
		shader->render();
	}
}