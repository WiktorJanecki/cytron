#include "managers/manager.h"

#include <algorithm>
#include <list>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"

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

std::list<Entity*> Manager::getEntitiesWith(Component::Type type){
	std::list<Entity*> entities = {};
	for(const auto& i : m_entities){
		if(Manager::hasComponent(i,type)){
			entities.push_back(i);
		}
	}
	return entities;
}

bool Manager::addComponent(Entity* entity, Component component){
	if(Manager::hasComponent(entity,component.getType())){
		return false;
	}
	entity->m_components.push_back(component);
	return true;
}

bool Manager::removeComponent(Entity* entity, Component::Type type){
	if(!Manager::hasComponent(entity,type)){
		return false;
	}
	m_entities.remove(entity);
	return true;
}


bool Manager::hasComponent(Entity* entity, Component::Type type){
	for(auto& i : entity->m_components){
		if(i.getType() == type){
			return true;
		}
	}
	return false;
}

Component* Manager::getComponent(Entity* entity, Component::Type type){
	for(auto& i: entity->m_components){
		if(i.getType() == type)
		return &i;
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

int Manager::generateID(){
	m_lastID++;
	return m_lastID-1;
}

std::list<Entity*> Manager::m_entities = {};
std::list<System*> Manager::m_systems = {};
std::list<Callable*> Manager::m_callables = {};
int Manager::m_lastID = 0;