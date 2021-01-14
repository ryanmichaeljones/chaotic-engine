#include "Engine.h"
#include "TestScene.h"
#include "Player.h"
//#include "engine/SoundSource.h"

#include <memory>

using namespace engine;							

int main(int argc, char* args[])
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<Texture> texture = entity->addComponent<Texture>("../src/textures/gray-texture.jpg");
	texture->getTransform()->setPosition(rend::vec3(0.34, 0.6, 0));
	texture->getTransform()->setScale(rend::vec3(0.5, 0.5, 1));

	/*std::shared_ptr<Sound> sound;
	sound->onLoad("../src/sounds/sound.ogg");
	std::shared_ptr<SoundSource> soundSource = entity->addComponent<SoundSource>(sound);
	soundSource->onInitialize(sound);*/

	std::shared_ptr<Entity> p = core->addEntity();
	std::shared_ptr<Renderer> pr = p->addComponent<Renderer>();
	p->addComponent<Player>();

	core->start();

	return 0;
}