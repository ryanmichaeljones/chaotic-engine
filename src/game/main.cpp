#include "engine/Core.h"
#include "engine/Entity.h"
#include "engine/Component.h"
#include "engine/Renderer.h"
#include "engine/Texture.h"
#include "engine/Transform.h"
#include "game/Player.h"

#include <memory>

using namespace engine;							

int main(int argc, char* args[])
{
	std::shared_ptr<Core> core = Core::initialize();
	//std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent<Component>();
	//std::shared_ptr<Renderer> renderer = entity->addComponent<Renderer>();

	std::shared_ptr<Entity> e1 = core->addEntity();
	std::shared_ptr<Renderer> r1 = e1->addComponent<Renderer>();
	r1->getTransform()->setPosition(rend::vec3(0.6, 0, 0));
	r1->getTransform()->setScale(rend::vec3(0.375, 0.5, 1));

	/*std::shared_ptr<Entity> e2 = core->addEntity();
	std::shared_ptr<Texture> t2 = e2->addComponent<Texture>();
	t2->getTransform()->setPosition(rend::vec3(-0.34, 0, 0));*/

	std::shared_ptr<Entity> p = core->addEntity();
	std::shared_ptr<Renderer> pr = p->addComponent<Renderer>();
	p->addComponent<Player>();

	core->start();

	return 0;
}