#include "components/movementComponent.h"

MovementComponent::MovementComponent(){
    m_type = Component::Type::MOVEMENT_COMPONENT;
}

void MovementComponent::setVelocity(sf::Vector2f vel){
    m_velocity = vel;
}

void MovementComponent::setAcceleration(sf::Vector2f acc){
    m_acceleration = acc;
}

sf::Vector2f MovementComponent::getVelocity(){
    return m_velocity;
}

sf::Vector2f MovementComponent::getAcceleration(){
    return m_acceleration;
}

void MovementComponent::increaseVelocity(float x, float y){
    m_velocity.x += x;
    m_velocity.y += y;
}

void MovementComponent::increaseAcceleration(float x, float y){
    m_acceleration.x += x;
    m_acceleration.y += y;
}
