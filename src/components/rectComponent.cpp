#include "components/rectComponent.h"

#include <SFML/Graphics.hpp>


RectComponent::RectComponent(){
    this->m_type = Component::Type::RECT_COMPONENT; 
}

RectComponent::RectComponent(float x, float y, float width, float height){  
    this->m_type = Component::Type::RECT_COMPONENT; 
    this->m_shape = sf::RectangleShape();
    this->m_shape.setPosition(x,y);
    this->m_shape.setSize(sf::Vector2f(width,height));
}

sf::RectangleShape* RectComponent::getRectangleShape(){
    return &m_shape;
}

