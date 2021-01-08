#include "components/rectColliderComponent.h"

RectColliderComponent::RectColliderComponent(){
    m_isColliding = false;
}

RectColliderComponent::RectColliderComponent(float x, float y, float width, float height){
    m_isColliding = false;
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
}

void RectColliderComponent::setColliding(bool b){
    m_isColliding = b;
}

void RectColliderComponent::setCollidingDirection(CollidingDirection dir){
    m_direction = dir;
}

void RectColliderComponent::setX(float x){
    m_x = x;
}

void RectColliderComponent::setY(float y){
    m_y = y;
}

void RectColliderComponent::setWidth(float width){
    m_width = width;
}

void RectColliderComponent::setHeight(float height){
    m_height = height;
}

bool RectColliderComponent::getColliding(){
    return m_isColliding;
}

RectColliderComponent::CollidingDirection RectColliderComponent::getCollidingDirection(){
    return m_direction;
}

float RectColliderComponent::getX(){
    return m_x;
}

float RectColliderComponent::getY(){
    return m_y;
}

float RectColliderComponent::getWidth(){
    return m_width;
}

float RectColliderComponent::getHeight(){
    return m_height;
}
