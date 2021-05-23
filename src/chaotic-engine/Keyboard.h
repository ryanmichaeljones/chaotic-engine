#include <vector>

#ifdef USE_SDL
	#define KEY_A 'a'
#else
	#define KEY_A 223
#endif

namespace engine
{
	struct Core;

	struct Keyboard
	{
	public:
		bool getKey(int key);

	private:
		friend struct engine::Core;

		std::vector<int> keys;

	};
}