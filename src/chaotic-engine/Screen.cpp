#include "Screen.h"

namespace engine
{
	rend::mat4 Screen::getPerspective()
	{
		return rend::perspective(rend::radians(45.0f), (float)screenHeight / (float)screenWidth, 0.1f, 100.0f);
	}

	rend::mat4 Screen::getOrthographic()
	{
		return rend::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	}
}