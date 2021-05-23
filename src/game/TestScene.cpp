#include "TestScene.h"
//#include "Engine.h"
#include "CameraController.h"

#include <iostream>

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
	c_camera->getTransform()->setPosition(rend::vec3(2.4f, 2.0f, 5.0f));

	// load a texture and render
	std::shared_ptr<Entity> e_texture = core->addEntity();
	std::shared_ptr<Texture> c_texture = e_texture->addComponent<Texture>();
	c_texture->loadTexture("../src/textures/diamondblock.png");
	
	std::shared_ptr<Entity> e_renderer = core->addEntity();
	std::shared_ptr<MeshRenderer> c_renderer = e_renderer->addComponent<MeshRenderer>();
	c_renderer->setTexture(c_texture->texture);

	std::shared_ptr<Entity> e_cameraController = core->addEntity();
	std::shared_ptr<CameraController> c_cameraController = e_cameraController->addComponent<CameraController>();

	core->start();
}
