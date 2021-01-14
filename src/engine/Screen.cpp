#include "Screen.h"

namespace engine
{
	///<summary>
	/// Returns the width of the screen.
	///</summary>
	unsigned int Screen::getWidth()
	{
		return width;
	}

	///<summary>
	/// Returns the height of the screen.
	///</summary>
	unsigned int Screen::getHeight()
	{
		return height;
	}

	///<summary>
	/// Sets the width of the screen.
	///</summary>
	void Screen::setWidth(unsigned int width)
	{
		this->width = width;
	}

	///<summary>
	/// Sets the height of the screen.
	///</summary>
	void Screen::setHeight(unsigned int height)
	{
		this->height = height;
	}
}