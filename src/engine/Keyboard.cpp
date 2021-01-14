#include "Keyboard.h"

namespace engine 
{
	///<summary>
	/// Returns true if a given key is pressed.
	///</summary>
	bool Keyboard::getKey(int key)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == key)
			{
				return true;
			}
		}
		return false;
	}
}