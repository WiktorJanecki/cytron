#pragma once

#include <list>

#include "callable.h"
#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"

class Manager : Callable{

public:
private:
	std::list<Entity*> entities;
	std::list<System*> systems;
	std::list<Callable*> callables;
};