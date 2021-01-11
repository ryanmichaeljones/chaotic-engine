#include "Player.h"
#include "engine/Core.h"
#include "engine/Entity.h"
#include "engine/Component.h"
#include "engine/Renderer.h"
#include "engine/Texture.h"
#include "engine/Transform.h"

namespace engine
{
	void Player::onInitialize()
	{
		pt = getEntity()->getComponent<Renderer>()->getTransform();
		pt->setPosition(rend::vec3(0, -0.9, 0));
		pt->setScale(rend::vec3(0.375, 0.1, 1));
		
		getEntity()->getComponent<Renderer>()->setColor(rend::vec4(0.7f, 0.1f, 0.5f, 1));
	}

	void Player::onTick()
	{
		if (getCore()->getKeyboard()->getKey('d'))
		{
			//move right
			/*if (pt->position.x < getCore()->)
			{

			}*/
			pt->setPosition(rend::vec3(pt->position.x + 0.01f, pt->position.y, pt->position.z));
		}

		if (getCore()->getKeyboard()->getKey('a'))
		{
			//move left
			pt->setPosition(rend::vec3(pt->position.x - 0.01f, pt->position.y, pt->position.z));
		}
	}
}