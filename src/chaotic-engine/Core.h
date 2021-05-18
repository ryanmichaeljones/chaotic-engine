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
	struct Environment;

	struct Core
	{
	public:
		friend struct engine::Screen;
		friend struct engine::Renderer;

		static std::shared_ptr<Core> initialize(int screenWidth, int screenHeight);
		void start();
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Screen> getScreen();
		//std::shared_ptr<Camera> getCamera();

		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Camera> camera;

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Environment> environment;			
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;

	};
}
