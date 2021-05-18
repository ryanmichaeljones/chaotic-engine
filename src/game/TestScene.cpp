#include "TestScene.h"
#include "Engine.h"

using namespace engine;

void TestScene::Scene()
{
	std::shared_ptr<Core> core = Core::initialize(800, 600);

	std::shared_ptr<Entity> e1 = core->addEntity();
	std::shared_ptr<Renderer> r1 = e1->addComponent<Renderer>();
	r1->getTransform()->setPosition(rend::vec3(0.5f, -1.0f, 0.0f));

	std::shared_ptr<Entity> e2 = core->addEntity();
	std::shared_ptr<Renderer> r2 = e2->addComponent<Renderer>();
	r2->setColor(rend::vec4(1, 0.54f, 0, 1));
	r2->getTransform()->setPosition(rend::vec3(0.2f, 0.5f, 0.0f));

	std::shared_ptr<Entity> e3 = core->addEntity();
	std::string path = "../src/textures/Goku3.jpg";
	std::shared_ptr<Texture> r3 = e3->addComponent<Texture>(path);
	r3->getTransform()->setPosition(rend::vec3(-0.8f, -0.6f, 0.0f));
	r3->getTransform()->setRotation(glm::vec3(glm::radians(-55.0f), 0.0f, 0.0f));

	core->start();
}
