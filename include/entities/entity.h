#pragma once

#include <list>

#include "components/component.h"

class Manager;

class Entity {
public:
	int getID();
    virtual ~Entity();
private:
	void setID(int id);	
private:
	int m_id;
	std::list<Component*> m_components;
protected:
    bool m_player = false;
friend class Manager;
};
