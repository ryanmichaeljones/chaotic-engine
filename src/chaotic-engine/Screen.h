#include <SDL.h>
#include <rend/rend.h>

namespace engine
{
	struct Screen
	{
	public:
		Screen(std::string _name, int _width, int _height);
		SDL_Window* getWindow();
		int getWidth();
		int getHeight();
		rend::mat4 getPerspective();
		rend::mat4 getOrthographic();

	private:
		std::string name;
		int width;
		int height;
		SDL_Window* window;

	};
}
