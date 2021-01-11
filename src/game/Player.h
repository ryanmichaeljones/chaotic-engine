#include <engine/Component.h>
#include <engine/Keyboard.h>

#include <memory>

namespace engine
{
	struct Player : public Component
	{
	public:
		void onInitialize();
	private:
		void onTick();

		std::shared_ptr<Transform> pt;
	};
}