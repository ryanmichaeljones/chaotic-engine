#include "Engine.h"
#include "Player.h"

namespace engine
{
	void Player::onInitialize()
	{
		pt = getEntity()->getComponent<Renderer>()->getTransform();

		pt->setPosition(rend::vec3(0, -0.9, 0));
		pt->setScale(rend::vec3(0.4, 0.1, 1));
		
		getEntity()->getComponent<Renderer>()->setColor(rend::vec4(0.7f, 0.1f, 0.5f, 1));
	}

	void Player::onTick()
	{
		if (getCore()->getKeyboard()->getKey('d'))
		{
			// Move right
			if (pt->getPosition().x < 0.8)
			{
				pt->translate(rend::vec3(0.01f, 0, 0));
			}
		}

		if (getCore()->getKeyboard()->getKey('a'))
		{
			// Move left
			if (pt->getPosition().x > -0.8)
			{
				pt->translate(rend::vec3(-0.01f, 0, 0));
			}
		}


	}
}