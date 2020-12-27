#include "components/component.h"

#include "callable.h"

Component::Component(Type type){
	this->m_type = type;
}
Component::Type Component::getType(){
	return m_type;
}