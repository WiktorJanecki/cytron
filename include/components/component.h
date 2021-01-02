#pragma once

class Component {
public:
	enum Type {
		MESH_COMPONENT = 0,
		TRANSFORM_COMPONENT,
        RECT_COMPONENT,
        TEXTURE_COMPONENT,
        RECT_COLLIDER_COMPONENT,
	};
    virtual ~Component(){}
public:
	Type getType();
protected:
	Type m_type;
};
