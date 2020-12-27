#pragma once

#include <list>

#include "callable.h"
#include "components/component.h"
#include "components/componentType.h"
#include "entities/entity.h"
#include "systems/system.h"

class Manager : Callable{

public:
	static bool addEntity(Entity*);
	static bool removeEntity(Entity*);
	static std::list<Entity*> getEntitiesWith(ComponentType);

	static bool addComponent(Entity*, Component*);
	static bool removeComponent(Entity*, Component);
	static bool hasComponent(Entity*, ComponentType);

	static bool addSystem(System*);
	static bool removeSystem(System*);
	static std::list<System*> getSystems();

	static bool clean();
private:
	Manager(){};		
private:
	static std::list<Entity*> m_entities;
	static std::list<System*> m_systems;
	static std::list<Callable*> m_callables;


};