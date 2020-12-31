#pragma once

#include <list>

#include "callable.h"
#include "components/component.h"

class Manager;

class Entity : Callable{
public:
	int getID();
    virtual ~Entity();
private:
	void setID(int id);	
private:
	int m_id;
	std::list<Component*> m_components;
friend class Manager;
};
