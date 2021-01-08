#include "systems/movementSystem.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "managers/manager.h"
#include "managers/timeManager.h"
#include "components/movementComponent.h"
#include "components/rectComponent.h"
#include "entities/player.h"

MovementSystem::MovementSystem(){}

void MovementSystem::start(){
    m_player = Manager::getPlayer();
}

void MovementSystem::update(){
    calculate();
}

void MovementSystem::render(){}

void MovementSystem::handleEvent(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::W){
            m_w = true;
        }
        if(event.key.code == sf::Keyboard::S){
            m_s = true;
        }
        if(event.key.code == sf::Keyboard::A){
            m_a = true;
        }
        if(event.key.code == sf::Keyboard::D){
            m_d = true;
        }
    }
    if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::W){
            m_w = false;
        }
        if(event.key.code == sf::Keyboard::S){
            m_s = false;
        }
        if(event.key.code == sf::Keyboard::A){
            m_a = false;
        }
        if(event.key.code == sf::Keyboard::D){
            m_d = false;
        }
    }
}

void MovementSystem::calculate(){
    if(m_w && !m_s && !m_a && !m_d){
        m_direction = sf::Vector2f(0,-1.f);
    }
    else if(m_s && !m_w && !m_a && !m_d){
        m_direction = sf::Vector2f(0,1.f);
    }
    else if(m_a && !m_w && !m_s && !m_d){
        m_direction = sf::Vector2f(-1.f,0);
    }
    else if(m_d && !m_w && !m_s && !m_a){
        m_direction = sf::Vector2f(1.f,0);
    }
    else if(m_w && m_a && !m_s && !m_d){
        m_direction = sf::Vector2f(-1.f,-1.f);
    }
    else if(m_w && m_d && !m_s && !m_a){
        m_direction = sf::Vector2f(1.f,-1.f);
    }
    else if(m_d && m_s && !m_w && !m_a){
        m_direction = sf::Vector2f(1.f,1.f);
    }
    else if(m_s && m_a && !m_w && !m_d){
        m_direction = sf::Vector2f(-1.f,1.f);
    }
    else{
        m_direction = sf::Vector2f(0.f,0.f);
    }
    if(m_player != nullptr){
        MovementComponent* movComp = (MovementComponent*) Manager::getComponent((Entity*)m_player,Component::Type::MOVEMENT_COMPONENT);
        RectComponent* rectComp = (RectComponent*) Manager::getComponent((Entity*)m_player,Component::Type::RECT_COMPONENT);
        if(movComp != nullptr && rectComp != nullptr){
            float dt = TimeManager::getDT();
            float speed = 500.f; 
            float maxSpeed = 200.f;
            float friction = speed/1.5f;

            movComp->setAcceleration(m_direction.x * speed, m_direction.y * speed);

            movComp->increaseVelocity(movComp->getAcceleration().x*dt,movComp->getAcceleration().y*dt);
             
            if(movComp->getVelocity().x > 0){
                movComp->increaseVelocity(dt * -friction,0.f);
            }
            if(movComp->getVelocity().x < 0){
                movComp->increaseVelocity(dt * friction, 0.f);
            }
            if(movComp->getVelocity().y > 0){
                movComp->increaseVelocity(0.f, dt * -friction);
            }
            if(movComp->getVelocity().y < 0){
                movComp->increaseVelocity(0.f, dt * friction);
            }

            if(movComp->getVelocity().x > maxSpeed){
                movComp->setVelocity(maxSpeed,movComp->getVelocity().y);
            }
            if(movComp->getVelocity().x < -maxSpeed){                                                                            
                movComp->setVelocity(-maxSpeed,movComp->getVelocity().y);                                          
            }
            if(movComp->getVelocity().y > maxSpeed){                                                                            
                movComp->setVelocity(movComp->getVelocity().x,maxSpeed);                                          
            }
            if(movComp->getVelocity().y < -maxSpeed){                                                                            
                movComp->setVelocity(movComp->getVelocity().x,-maxSpeed);                                          
            }
    
            rectComp->getRectangleShape()->move(movComp->getVelocity().x * dt, dt * movComp->getVelocity().y);
        }
    }
}
