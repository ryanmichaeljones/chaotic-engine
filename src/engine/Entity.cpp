#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace engine
{
	///<summary>
	/// Calls the tick function for each component.
	///</summary>
	void Entity::tick()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->tick();
		}
	}

	///<summary>
	/// Calls the render function for each component.
	///</summary>
	void Entity::render()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->render();
		}
	}

	///<summary>
	/// Returns a pointer to the core structure of the entity.
	///</summary>
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	///<summary>
	/// Returns a pointer to the transform structure of the entity.
	///</summary>
	std::shared_ptr<Transform> Entity::getTransform()
	{
		return getComponent<Transform>();
	}
}