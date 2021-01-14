#include "Component.h"
#include "Entity.h"

namespace engine
{
	///<summary>
	/// Calls the tick function for the component.
	///</summary>
	void Component::tick()
	{
		onTick();
	}

	///<summary>
	/// Calls the render function for the component.
	///</summary>
	void Component::render()
	{
		onRender();
	}

	///<summary>
	/// Calls function when initializing.
	///</summary>
	void Component::onInitialize()
	{
	
	}

	///<summary>
	/// Calls function for each tick.
	///</summary>
	void Component::onTick()
	{
	
	}

	///<summary>
	/// Calls function when rendering.
	///</summary>
	void Component::onRender()
	{
	
	}

	///<summary>
	/// Returns a pointer to the entity structure that component is attached to.
	///</summary>
	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	///<summary>
	/// Returns a pointer to the core structure.
	///</summary>
	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

	///<summary>
	/// Returns a pointer to the transform structure of the entity structure that the component is attached to.
	///</summary>
	std::shared_ptr<Transform> Component::getTransform()
	{
		return getEntity()->getTransform();
	}
}