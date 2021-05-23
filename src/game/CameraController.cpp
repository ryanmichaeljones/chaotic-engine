#include "CameraController.h"

#include <iostream>

void CameraController::onTick()
{
	if (getCore()->getKeyboard()->getKey('s'))
	{
		getCore()->getCurrentCamera()->getTransform()->translate(rend::vec3(0.0f, 0.01f, 0.0f));
	}
	if (getCore()->getKeyboard()->getKey('w'))
	{
		getCore()->getCurrentCamera()->getTransform()->translate(rend::vec3(0.0f, -0.01f, 0.0f));
	}
	if (getCore()->getKeyboard()->getKey('a'))
	{
		getCore()->getCurrentCamera()->getTransform()->translate(rend::vec3(0.01f, 0.0f, 0.0f));
	}
	if (getCore()->getKeyboard()->getKey('d'))
	{
		getCore()->getCurrentCamera()->getTransform()->translate(rend::vec3(-0.01f, 0.0f, 0.0f));
	}
}