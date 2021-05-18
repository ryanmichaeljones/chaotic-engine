#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Screen.h"
#include "Camera.h"
#include "Environment.h"

#include <iostream>

namespace engine
{
	std::shared_ptr<Core> Core::initialize(int screenWidth, int screenHeight)
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->screen = std::make_shared<Screen>(screenWidth, screenHeight);

		rtn->window = SDL_CreateWindow("chaotic-engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->getScreen()->screenWidth, rtn->getScreen()->screenHeight,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		if (!rtn->window)
		{
			throw std::exception("Failed to create Window");
		}

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw std::exception("Failed to create OpenGL context");
		}

		rtn->context = rend::Context::initialize();	

		rtn->environment = std::make_shared<Environment>();

		return rtn;
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

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
	}

	/*std::shared_ptr<Camera> Core::getCamera()
	{
		return camera;
	}*/

	void Core::start()
	{
		// return exception if camera is nullptr

		float idealTime = 1.0f / 60.0f;
		float lastTime = (float)SDL_GetTicks();
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

				float time = (float)SDL_GetTicks();
				float diff = time - lastTime;
				environment->setDeltaTime(diff / 1000.0f);
				lastTime = time;

				if (idealTime > environment->getDeltaTime())
				{
					SDL_Delay(fabsf((idealTime - environment->getDeltaTime() * 1000.0f)));
				}

				SDL_GetWindowSize(window, &getScreen()->screenWidth, &getScreen()->screenHeight);
				SDL_GL_SwapWindow(window);
			}
		}
	}
}