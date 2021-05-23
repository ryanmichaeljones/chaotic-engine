#include <SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace engine 
{
	struct Entity;
	struct Renderer;
	struct Camera;
	struct Screen;
	struct Resources;
	struct Environment;
	struct Keyboard;

	struct Core
	{
	public:
		friend struct engine::Screen;
		friend struct engine::Renderer;

		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Screen> createScreen(std::string name, int width, int height);
		void start();
		void setCurrentCamera(std::shared_ptr<Camera> camera);
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<rend::Context> getContext();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Screen> getScreen();
		std::shared_ptr<Camera> getCurrentCamera();

		std::shared_ptr<rend::Context> context;

		template<typename T>
		void getComponents(std::vector<std::shared_ptr<T>> *list)
		{
			for (size_t i = 0; i < entities.size(); i++)
			{
				try
				{
					list->push_back(entities.at(i)->getComponent<T>());
				}
				catch(...)
				{
					// entity doesn't have component attached
				}
			}
		}

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::vector<std::shared_ptr<Camera>> cameras;
		std::shared_ptr<Camera> currentCamera;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Resources> resources;
		std::shared_ptr<Environment> environment;	
		std::shared_ptr<Keyboard> keyboard;
		std::weak_ptr<Core> self;
		SDL_GLContext glContext;

	};
}
