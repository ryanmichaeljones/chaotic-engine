#include "Environment.h"

namespace engine
{
	float Environment::getDeltaTime()
	{
		return deltaTime;
	}

	void Environment::setDeltaTime(float time)
	{
		this->deltaTime = time;
	}
}