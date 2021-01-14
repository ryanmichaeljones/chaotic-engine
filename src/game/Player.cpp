#include "Engine.h"
#include "Player.h"

namespace engine
{
	void Player::onInitialize()
	{
		pt = getEntity()->getComponent<Renderer>()->getTransform();
<<<<<<< HEAD

=======
		//pr = getEntity()->getComponent<Renderer>();
>>>>>>> 7cf6edf6ec6392d1292fe67401ea0a278e9bb5a6
		pt->setPosition(rend::vec3(0, -0.9, 0));
		pt->setScale(rend::vec3(0.4, 0.1, 1));
		
		getEntity()->getComponent<Renderer>()->setColor(rend::vec4(0.7f, 0.1f, 0.5f, 1));
	}

	void Player::onTick()
	{
		if (getCore()->getKeyboard()->getKey('d'))
		{
<<<<<<< HEAD
			// Move right
=======
			//move right
>>>>>>> 7cf6edf6ec6392d1292fe67401ea0a278e9bb5a6
			if (pt->getPosition().x < 0.8)
			{
				pt->translate(rend::vec3(0.01f, 0, 0));
			}
		}

		if (getCore()->getKeyboard()->getKey('a'))
		{
<<<<<<< HEAD
			// Move left
=======
			//move left
>>>>>>> 7cf6edf6ec6392d1292fe67401ea0a278e9bb5a6
			if (pt->getPosition().x > -0.8)
			{
				pt->translate(rend::vec3(-0.01f, 0, 0));
			}
		}


	}
}