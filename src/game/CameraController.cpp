#include "CameraController.h"

#include <iostream>

void CameraController::onTick()
{
	speed = 0.04f;
	cameraTransform = getCore()->getCurrentCamera()->getTransform();

	if (getKeyboard()->getKey('s'))
	{
		cameraTransform->translate(rend::vec3(0.0f, speed, 0.0f));
	}
	if (getKeyboard()->getKey('w'))
	{
		cameraTransform->translate(rend::vec3(0.0f, -speed, 0.0f));
	}
	if (getKeyboard()->getKey('a'))
	{
		cameraTransform->translate(rend::vec3(speed, 0.0f, 0.0f));
	}
	if (getKeyboard()->getKey('d'))
	{
		cameraTransform->translate(rend::vec3(-speed, 0.0f, 0.0f));
	}
}