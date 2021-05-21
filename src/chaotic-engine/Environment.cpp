#include "Environment.h"

namespace engine
{
	double Environment::getDeltaTime()
	{
		return deltaTime;
	}

	void Environment::setDeltaTime(double time)
	{
		this->deltaTime = time;
	}
}