#include "Component.h"

#include <rend/rend.h>

namespace engine
{
	struct Transform : public Component
	{
	public:
		void onInitialize();
		rend::mat4 getModel();
		void setPosition(rend::vec3 position);
		void setRotation(rend::vec3 rotation);
		void setScale(rend::vec3 scale);

	//private:
		rend::vec3 position;
		rend::vec3 rotation;
		rend::vec3 scale;
	};
}
