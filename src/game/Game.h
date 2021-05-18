#include "Engine.h"

#include <memory>

struct Game
{
public:
	void initialize();

private:
	std::shared_ptr<Core> core;
	std::shared_ptr<Camera> camera;
	std::vector<std::shared_ptr<Entity>> cells;

};
