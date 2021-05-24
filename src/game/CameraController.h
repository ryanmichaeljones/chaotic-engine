#include "Engine.h"

struct CameraController : public Component
{
public:
	void onTick();

private:
	float speed;
	std::shared_ptr<Transform> cameraTransform;

};