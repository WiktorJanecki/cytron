#include "entities/entity.h"

#include <list>

#include "callable.h"

int Entity::getID(){
	return m_id;
}

void Entity::setID(int id){
	m_id = id;
}

Entity::~Entity(){
    for(auto&i : m_components){
        delete i;
    }
    m_components.clear();
}
