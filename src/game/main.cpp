#include "Game.h"
#include "TestScene.h"

int main(int argc, char* args[])
{
	std::make_shared<TestScene>()->Scene();

	//std::shared_ptr<Game> game = std::make_shared<Game>();
	//game->initialize();

	return 0;
}

