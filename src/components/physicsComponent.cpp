#include "components/physicsComponent.h"

PhysicsComponent::PhysicsComponent(){

};

void PhysicsComponent::setVelocity(float x,float y){
    m_velocity.x = x;
    m_velocity.y = y;
}

void PhysicsComponent::setAcceleration(float x, float y){
    m_acceleration.x = x;
    m_acceleration.y = y;
}

void PhysicsComponent::setFriction(float value){
    m_friction = value;
}

sf::Vector2f PhysicsComponent::getVelocity(){
    return m_velocity;
}

sf::Vector2f PhysicsComponent::getAcceleration(){
    return m_acceleration;
}

float PhysicsComponent::getFriction(){
    return m_friction;
}

void PhysicsComponent::increaseVelocity(float x, float y){
    m_velocity.x += x;
    m_velocity.y += y;
}

void PhysicsComponent::increaseAcceleration(float x, float y){
    m_acceleration.x += x;
    m_acceleration.y += y;
}

