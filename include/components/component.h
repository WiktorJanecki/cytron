#pragma once

#include "callable.h"

class Component : Callable{
public:
	enum Type {
		MESH_COMPONENT = 0,
		TRANSFORM_COMPONENT,
        RECT_COMPONENT,
	};
public:
	Type getType();
protected:
	Type m_type;
};
