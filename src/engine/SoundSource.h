#include "Component.h"
#include "Sound.h"

#include <AL/al.h>

namespace engine
{
	struct SoundSource : public Component
	{
	public:
		void onInitialize(std::shared_ptr<Sound> sound);
		void onTick();
		void onDestroy();

	private:
		ALuint sid;
	};
}
