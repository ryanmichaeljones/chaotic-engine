#include "TestScene.h"
#include "Engine.h"

using namespace engine;

void TestScene::Scene()
{
	// initialize engine
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Screen> screen = core->createScreen("chaotic-engine", 800, 600);

	// add camera to scene
	std::shared_ptr<Entity> e_camera = core->addEntity();
	std::shared_ptr<Camera> c_camera = e_camera->addComponent<Camera>();
	core->setCurrentCamera(c_camera);
	c_camera->getTransform()->setRotation(rend::vec3(rend::radians(-19.0f), rend::radians(25.0f), rend::radians(10.0f)));
	c_camera->getTransform()->setPosition(rend::vec3(2.4f, 2, 5));

	// load a texture and render
	//std::shared_ptr<engine::Texture> texture = std::make_shared<engine::Texture>();
	//texture->loadTexture("../src/textures/Goku3.jpg");
	std::shared_ptr<Entity> e_texture = core->addEntity();
	std::shared_ptr<Texture> c_texture = e_texture->addComponent<Texture>();
	c_texture->loadTexture("../src/textures/diamondblock.png");
	
	std::shared_ptr<Entity> e_renderer = core->addEntity();
	std::shared_ptr<MeshRenderer> c_renderer = e_renderer->addComponent<MeshRenderer>();
	c_renderer->setTexture(c_texture->texture);

	

	/*std::shared_ptr<Entity> e1 = core->addEntity();
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
	r3->getTransform()->setRotation(glm::vec3(glm::radians(-55.0f), 0.0f, 0.0f));*/

	core->start();
}
