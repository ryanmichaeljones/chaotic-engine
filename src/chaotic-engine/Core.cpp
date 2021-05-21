#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Screen.h"
#include "Camera.h"
#include "Resources.h"
#include "Environment.h"

#include <iostream>

namespace engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->environment = std::make_shared<Environment>();

		return rtn;
	}

	std::shared_ptr<Screen> Core::createScreen(std::string name, int width, int height)
	{
		screen = std::make_shared<Screen>(name, width, height);

		glContext = SDL_GL_CreateContext(screen->getWindow());

		if (!glContext)
		{
			throw std::exception("Failed to create OpenGL context");
		}
		
		context = rend::Context::initialize();

		return screen;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->core = self;
		rtn->self = rtn;

		rtn->addComponent<Transform>();

		entities.push_back(rtn);

		return rtn;
	}

	std::shared_ptr<rend::Context> Core::getContext()
	{
		return context;
	}

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
	}

	std::shared_ptr<Camera> Core::getCurrentCamera()
	{
		return currentCamera;
	}

	void Core::start()
	{
		double idealTime = 1.00 / 60.00;
		double lastTime = SDL_GetTicks();
		bool running = true;
		SDL_Event event;

		while (running)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}

				for (size_t ei = 0; ei < entities.size(); ei++)
				{
					entities.at(ei)->tick();
				}

				glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				for (size_t ei = 0; ei < entities.size(); ei++)
				{
					entities.at(ei)->render();
				}

				double time = SDL_GetTicks();
				double diff = time - lastTime;
				environment->setDeltaTime(diff / 1000.00);
				lastTime = time;

				if (idealTime > environment->getDeltaTime())
				{
					SDL_Delay(fabs((idealTime - environment->getDeltaTime() * 1000.00)));
				}

				getComponents<Camera>(&cameras);
				if (cameras.size() == 0)
				{
					throw std::exception("Failed to find a camera instance");
				}
				else
				{
					setCurrentCamera(cameras.at(0));
				}

				//SDL_GetWindowSize(window, &getScreen()->screenWidth, &getScreen()->screenHeight);
				SDL_GL_SwapWindow(screen->getWindow());
			}
		}

	}

	void Core::setCurrentCamera(std::shared_ptr<Camera> camera)
	{
		currentCamera = camera;
	}
}