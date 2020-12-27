#pragma once

#include <list>

#include "callable.h"

class Manager;

class Entity : Callable{
private:
	std::list<Component> components;
	friend class Manager;
};