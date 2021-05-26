#include "Shader.h"
#include "Core.h"

namespace engine
{
	void Shader::onLoad()
	{
		shader = getCore()->getContext()->createShader();

		std::ifstream shaderFile(getPath());
		std::string sourceString(
			(std::istreambuf_iterator<char>(shaderFile)),
			(std::istreambuf_iterator<char>())
		);

		shader->parse(sourceString.c_str());
	}

	std::shared_ptr<rend::Shader> Shader::getShader()
	{
		return shader;
	}
}