#include "Component.h"

#include <rend/rend.h>

namespace engine
{
	struct Transform : public Component
	{
	public:
		void onInitialize();
		rend::mat4 getModel();
		void translate(rend::vec3 translation);
		void rotate(rend::vec3 rotation);
		void scale(rend::vec3 scale);
		rend::vec3 getPosition();
		rend::vec3 getRotation();
		rend::vec3 getScale();
		void setPosition(rend::vec3 position);
		void setRotation(rend::vec3 rotation);
		void setScale(rend::vec3 scale);

	private:
		rend::vec3 localPosition;
		rend::vec3 localRotation;
		rend::vec3 localScale;
	};
}
