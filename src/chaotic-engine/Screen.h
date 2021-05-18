#include <rend/rend.h>

namespace engine
{
	struct Screen
	{
	public:
		Screen(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) { }
		rend::mat4 getPerspective();
		rend::mat4 getOrthographic();

		int screenWidth;
		int screenHeight;

	};
}
