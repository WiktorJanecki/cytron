#include "entities/entity.h"

#include <list>

#include "callable.h"

int Entity::getID(){
	return m_id;
}

void Entity::setID(int id){
	m_id = id;
}