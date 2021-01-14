#include <SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace engine
{
	struct Renderer;
	struct Entity;
	struct Keyboard;
	struct Screen;

	struct Core
	{
	public:
		friend struct engine::Renderer;

		static std::shared_ptr<Core> initialize();
		void start();

		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Screen> getScreen();

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		ALCdevice* alcDevice;
		ALCcontext* alcContext;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Screen> screen;
	};

}