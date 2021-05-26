#include "TestScene.h"
#include "CameraController.h"
//#include "Engine.h"

#include <iostream>

using namespace engine;

void TestScene::Scene()
{
	// Initialize engine
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Screen> screen = core->createScreen("chaotic-engine", 800, 600);

	// Add camera to scene
	std::shared_ptr<Entity> e_camera = core->addEntity();
	std::shared_ptr<Camera> c_camera = e_camera->addComponent<Camera>();
	core->setCurrentCamera(c_camera);
	c_camera->getTransform()->setRotation(rend::vec3(rend::radians(-20.0f), rend::radians(25.0f), rend::radians(10.0f)));
	c_camera->getTransform()->setPosition(rend::vec3(2.5f, 2.0f, 5.0f));

	// Load a texture, shader and mesh
	std::shared_ptr<Texture> texture = core->getResources()->load<Texture>("../src/textures/diamondblock.png");
	std::shared_ptr<Shader> shader = core->getResources()->load<Shader>("../src/shaders/texture.shader");
	std::shared_ptr<Mesh> mesh = core->getResources()->load<Mesh>("../src/models/cube.obj");
	
	// Render cube using a texture
	std::shared_ptr<Entity> e_renderer = core->addEntity();
	std::shared_ptr<MeshRenderer> c_renderer = e_renderer->addComponent<MeshRenderer>(texture, shader, mesh);

	// Translate the cube through keyboard input
	std::shared_ptr<Entity> e_cameracontroller = core->addEntity();
	std::shared_ptr<CameraController> c_cameracontroller = e_cameracontroller->addComponent<CameraController>();

	core->start();
}
