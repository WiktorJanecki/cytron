#pragma once

#include "callable.h"

class Component : Callable{
public:
	enum Type {
		MESH_COMPONENT = 0,
		TRANSFORM_COMPONENT,
	};
public:
	Component(Type);
	Type getType();
private:
	Type m_type;
};