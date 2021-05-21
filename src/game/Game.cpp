#include "Game.h"

#include <iostream>

using namespace engine;

void Game::initialize()
{
	//core = Core::initialize(600, 600);

	//core->camera = core->addEntity()->addComponent<Camera>();
	//camera = core->camera;

	//camera->getTransform()->setPosition(rend::vec3(0.0f, 0.0f, 12.0f));

	//for (int x = 0; x < 5; x++)
	//{
	//	for (int y = 0; y < 5; y++)
	//	{
	//		std::shared_ptr<Entity> cellEntity = core->addEntity();
	//		cellEntity->addComponent<Renderer>();
	//		cellEntity->getTransform()->setPosition(rend::vec3(x, y, 0.0f));
	//		cellEntity->getTransform()->setScale(rend::vec3(1.0f, 1.0f, 1.0f));
	//		cells.push_back(cellEntity);
	//	}
	//}
	//
	//for (int x = 0; x < 5; x++)
	//{
	//	for (int z = 0; z <= 5; z++)
	//	{
	//		std::shared_ptr<Entity> wallEntity = core->addEntity();
	//		/*wallEntity->addComponent<Renderer>();
	//		wallEntity->getTransform()->setPosition(rend::vec3(x*0.9f + 0.2f, z*0.86f - 0.15f, 1.0f));
	//		wallEntity->getTransform()->setScale(rend::vec3(0.2f, 0.9f, 1.0f));
	//		wallEntity->getTransform()->setRotation(rend::vec3(0.0f, 0.0f, rend::radians(90.0f)));
	//		wallEntity->getComponent<Renderer>()->setColor(rend::vec4(0.1f, 0.0f, 0.3f, 0.8f));*/
	//		wallEntity->addComponent<Renderer>();
	//		wallEntity->getTransform()->setPosition(rend::vec3(x + 0.05f, z - 0.45f, 1.0f));
	//		wallEntity->getTransform()->setScale(rend::vec3(1.0f, 0.15f, 1.0f));
	//		//wallEntity->getTransform()->setRotation(rend::vec3(0.0f, 0.0f, rend::radians(90.0f)));
	//		wallEntity->getComponent<Renderer>()->setColor(rend::vec4(0.1f, 0.0f, 0.3f, 0.8f));
	//	}
	//}

	//for (int x = 0; x <= 5; x++)
	//{
	//	for (int z = 0; z < 5; z++)
	//	{
	//		std::shared_ptr<Entity> wallEntity = core->addEntity();
	//		/*wallEntity->addComponent<Renderer>();
	//		wallEntity->getTransform()->setPosition(rend::vec3(x*0.86f - 0.15f, z*0.9f + 0.2f, 1.0f));
	//		wallEntity->getTransform()->setScale(rend::vec3(0.2f, 0.9f, 1.0f));
	//		wallEntity->getComponent<Renderer>()->setColor(rend::vec4(0.1f, 0.0f, 0.3f, 0.8f));*/
	//		wallEntity->addComponent<Renderer>();
	//		wallEntity->getTransform()->setPosition(rend::vec3(x - 0.45f, z + 0.05f, 1.0f));
	//		wallEntity->getTransform()->setScale(rend::vec3(0.15f, 1.0f, 1.0f));
	//		wallEntity->getComponent<Renderer>()->setColor(rend::vec4(0.1f, 0.0f, 0.3f, 0.8f));
	//	}
	//}

	////create a component for MazeCell


	//core->start();
}