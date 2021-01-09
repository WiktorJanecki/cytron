#pragma once

#include <list>
#include <string>

#include "components/component.h"
#include "entities/entity.h"
#include "entities/player.h"
#include "systems/system.h"
#include "events/listener.h"
#include "events/event.h"

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

    static void listen(Listener*);
    static void initEvent(Event);

	static void cleanUp();
private:
	Manager(){};
	static int generateID();
private:
	static std::list<Entity*> m_entities;
	static std::list<System*> m_systems;
    static std::list<Listener*> m_listeners;
	static int m_lastID;
};
