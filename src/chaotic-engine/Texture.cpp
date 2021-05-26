#include "Texture.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace engine
{
	void Texture::onLoad()
	{
		texture = getCore()->getContext()->createTexture();

		int w = 0, h = 0, channels = 0;

		unsigned char *data = stbi_load(getPath().c_str(), &w, &h, &channels, 3);

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
	}

	std::shared_ptr<rend::Texture> Texture::getTexture()
	{
		return texture;
	}
}