#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <memory>

namespace engine
{
	struct Entity;
	struct Core;
	struct Transform;
	struct Screen;

	struct Component
	{
	public:
		friend struct engine::Entity;

		void tick();
		void render();
		void onInitialize();
		virtual void onTick();
		virtual void onRender();
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();
		std::shared_ptr<Screen> getScreen();

	private:
		std::weak_ptr<Entity> entity;

	};
}

#endif