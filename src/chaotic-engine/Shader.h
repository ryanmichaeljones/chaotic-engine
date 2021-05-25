#include "Resource.h"

#include <rend/rend.h>

#include <memory>
#include <fstream>

namespace engine
{
	struct Shader : public Resource
	{
	public:
		void onLoad();
		std::shared_ptr<rend::Shader> getShader();

	private:
		std::shared_ptr<rend::Shader> shader;

	};
}
