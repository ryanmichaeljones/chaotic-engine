#include "Camera.h"
#include "Transform.h"

namespace engine
{
	void Camera::onInitialize()
	{
		getTransform()->setPosition(rend::vec3(0.0f, 0.0f, 5.0f));
	}
}