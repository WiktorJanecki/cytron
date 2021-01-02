#pragma once

#include <list>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"

class Manager {

public:
	static bool addEntity(Entity*);
	static bool removeEntity(Entity*);
	static std::list<Entity*> getEntitiesWith(Component::Type);

	static bool addComponent(Entity*, Component*);
	static bool removeComponent(Entity*, Component::Type);
	static bool hasComponent(Entity*, Component::Type);
	static Component* getComponent(Entity*, Component::Type);

	static bool addSystem(System*);
	static bool removeSystem(System*);
	static std::list<System*> getSystems();

	static void cleanUp();
private:
	Manager(){};
	static int generateID();
private:
	static std::list<Entity*> m_entities;
	static std::list<System*> m_systems;
	static int m_lastID;
};
