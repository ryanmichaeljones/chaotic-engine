#include "Component.h"
#include "Core.h"
#include "Entity.h"

namespace engine
{
	void Component::tick()
	{
		onTick();
	}

	void Component::render()
	{
		onRender();
	}

	void Component::onInitialize() { }

	void Component::onTick() { }

	void Component::onRender() { }

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

	std::shared_ptr<Transform> Component::getTransform()
	{
		return getEntity()->getTransform();
	}

	std::shared_ptr<Screen> Component::getScreen()
	{
		return getEntity()->getCore()->getScreen();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return getCore()->getKeyboard();
	}
}