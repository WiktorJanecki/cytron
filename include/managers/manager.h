#pragma once

#include <list>

#include "callable.h"
#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"
#include "events/event.h"

class Manager {

public:
    static void start();

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
    
    template<typename T>
    static std::list<Callable*> getCallablesWith(){
        std::list<Callable*> callist = std::list<Callable*>(); 
        T* element;
        for(auto&i : m_callables){
            if((element = dynamic_cast<T*>(i))){
                callist.push_back(i);   
            }  
        }
        return callist;
    }

    static void initEvent(Event);

	static void cleanUp();
private:
	Manager(){};
	static int generateID();
private:
	static std::list<Entity*> m_entities;
	static std::list<System*> m_systems;
	static std::list<Callable*> m_callables;
	static int m_lastID;
};
