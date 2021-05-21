#include "Screen.h"

namespace engine
{
	Screen::Screen(std::string _name, int _width, int _height)
	{
		name = _name;
		width = _width;
		height = _height;

		window = SDL_CreateWindow(name.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		if (!window)
		{
			throw std::exception("Failed to create Window");
		}
	}

	SDL_Window* Screen::getWindow()
	{
		return window;
	}

	int Screen::getWidth()
	{
		return width;
	}

	int Screen::getHeight()
	{
		return height;
	}

	rend::mat4 Screen::getPerspective()
	{
		return rend::perspective(rend::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
	}

	rend::mat4 Screen::getOrthographic()
	{
		return rend::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	}
}