#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Keyboard.h"

namespace engine 
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->window = SDL_CreateWindow("engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		if (!rtn->window)
		{
			throw Exception("Failed to create Window");
		}

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw Exception("Failed to create OpenGL context");
		}

		rtn->context = rend::Context::initialize();
		rtn->keyboard = std::make_shared<Keyboard>();

		/*rtn->alcDevice = alcOpenDevice(NULL);

		if (!rtn->alcDevice)
		{
			throw Exception("Failed to open default device");
		}

		rtn->alcContext = alcCreateContext(rtn->alcDevice, NULL);

		if (!rtn->alcContext)
		{
			alcCloseDevice(rtn->alcDevice);
			throw Exception("Failed to create OpenAL context");
		}

		if (!alcMakeContextCurrent(rtn->alcContext))
		{
			alcDestroyContext(rtn->alcContext);
			alcCloseDevice(rtn->alcDevice);
			throw Exception("Failed to make OpenAL context current");
		}*/

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

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}

	void Core::start()
	{
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
				else if (event.type == SDL_KEYDOWN)
				{
					keyboard->keys.push_back(event.key.keysym.sym);
					keyboard->downKeys.push_back(event.key.keysym.sym);
				}
				else if (event.type == SDL_KEYUP)
				{
					for (std::vector<int>::iterator it = keyboard->keys.begin();
						it != keyboard->keys.end();)
					{
						if (*it == event.key.keysym.sym)
						{
							it = keyboard->keys.erase(it);
						}
						else it++;
					}
					keyboard->upKeys.push_back(event.key.keysym.sym);
				}
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

			SDL_GL_SwapWindow(window);

			keyboard->downKeys.clear();
			keyboard->upKeys.clear();
		}


		/*alcMakeContextCurrent(NULL);
        alcDestroyContext(alcContext);
		alcCloseDevice(alcDevice);*/

		/*SDL_GL_DeleteContext(glContext);
		SDL_DestroyWindow(window);
		SDL_Quit();*/
	}
}