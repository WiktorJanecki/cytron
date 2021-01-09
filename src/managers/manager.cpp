#include "managers/manager.h"

#include <algorithm>
#include <list>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"
#include "managers/windowManager.h"
#include "managers/timeManager.h"
#include "managers/sceneManager.h"

bool Manager::addEntity(Entity* entity){
	entity->setID(generateID());
	m_entities.push_back(entity);
	return true;
}

bool Manager::removeEntity(Entity* entity){

	if(std::find(m_entities.begin(), m_entities.end(), entity) == m_entities.end()){ //if list does not contain element
		return false;
	}
	m_entities.remove(entity);
	return true;
}

std::list<Entity*> Manager::getEntitiesWith(std::string type){
	std::list<Entity*> entities = {};
	for(const auto& i : m_entities){
		if(Manager::hasComponent(i,type)){
			entities.push_back(i);
		}
	}
	return entities;
}

Player* Manager::getPlayer(){
    for(auto&i : m_entities){
        if(i->m_player){
            return (Player*)i;
        }
    }
    return nullptr;
}

bool Manager::addComponent(Entity* entity, Component* component){
	if(Manager::hasComponent(entity,component->getType())){
		return false;
	}
	entity->m_components.push_back(component);
	return true;
}

bool Manager::removeComponent(Entity* entity, std::string type){
	if(!Manager::hasComponent(entity,type)){
		return false;
	}
	m_entities.remove(entity);
	return true;
}


bool Manager::hasComponent(Entity* entity, std::string type){
	for(auto& i : entity->m_components){
		if(i->getType() == type){
			return true;
		}
	}
	return false;
}

Component* Manager::getComponent(Entity* entity, std::string type){
	for(auto& i: entity->m_components){
		if(i->getType() == type)
		return i;
	}
	return nullptr;
}

bool Manager::addSystem(System* system){
	for(auto&i : m_systems){
		if(i == system){
			return false;
		}
	}
	m_systems.push_back(system);
	return true;
}

bool Manager::removeSystem(System* system){
	for(auto&i : m_systems){
		if(i == system){
			m_systems.remove(system);
			return true;
		}
	}
	return false;
}

std::list<System*> Manager::getSystems(){
	return m_systems;
}

void Manager::listen(Listener* listener){
    m_listeners.push_back(listener);
}

void Manager::initEvent(Event event){
    std::list<Listener*> helper = m_listeners;
    for(auto&i : m_listeners){
        i->onEvent(event);
        if(m_listeners != helper)
        {
            break; //IMPORTANT  when keyev changes scene m_listeners will have changed and create an segfault error
        }
    }
}

int Manager::generateID(){
	m_lastID++;
	return m_lastID-1;
}

void Manager::cleanUp(){
    for(auto&i : m_entities){
        delete i;
    }
    m_entities.clear();
    for(auto&i : m_systems){
        delete i;
    }
    m_systems.clear();
    m_listeners.clear();
    m_lastID = 0;
}

std::list<Entity*> Manager::m_entities = {};
std::list<System*> Manager::m_systems = {};
std::list<Listener*> Manager::m_listeners = {};
int Manager::m_lastID = 0;
