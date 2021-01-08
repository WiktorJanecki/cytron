#pragma once

#include <list>
#include <string>

#include "components/component.h"
#include "entities/entity.h"
#include "entities/player.h"
#include "systems/system.h"

class Manager {

public:
	static bool addEntity(Entity*);
	static bool removeEntity(Entity*);
	static std::list<Entity*> getEntitiesWith(std::string);
    static Player* getPlayer();

	static bool addComponent(Entity*, Component*);
	static bool removeComponent(Entity*, std::string);
	static bool hasComponent(Entity*, std::string);
	static Component* getComponent(Entity*, std::string);

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
