#include "components/movementComponent.h"

MovementComponent::MovementComponent(){

}

void MovementComponent::setVelocity(float x, float y){
    m_velocity.x = x;
    m_velocity.y = y;
}

void MovementComponent::setAcceleration(float x,float y){
    m_acceleration.x = x;
    m_acceleration.y = y;
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
