#include "systems/movementSystem.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "managers/manager.h"
#include "managers/timeManager.h"
#include "managers/gamepadManager.h"
#include "components/movementComponent.h"
#include "components/rectComponent.h"
#include "components/rectColliderComponent.h"
#include "entities/player.h"

MovementSystem::MovementSystem(){}

void MovementSystem::start(){
    Manager::listen(this);
    m_player = Manager::getPlayer();
}

void MovementSystem::update(){
    calculate();
}

void MovementSystem::render(){}

void MovementSystem::onEvent(Event event){
    if(event.type == "sfEvent"){
        if(event.sfEvent.type == sf::Event::KeyPressed){
            if(event.sfEvent.key.code == sf::Keyboard::W){
                m_w = true;
            }
            if(event.sfEvent.key.code == sf::Keyboard::S){
                m_s = true;
            }
            if(event.sfEvent.key.code == sf::Keyboard::A){
                m_a = true;
            }
            if(event.sfEvent.key.code == sf::Keyboard::D){
                m_d = true;
            }
        }
        if(event.sfEvent.type == sf::Event::KeyReleased){
            if(event.sfEvent.key.code == sf::Keyboard::W){
                m_w = false;
            }
            if(event.sfEvent.key.code == sf::Keyboard::S){
                m_s = false;
            }
            if(event.sfEvent.key.code == sf::Keyboard::A){
                m_a = false;
            }
            if(event.sfEvent.key.code == sf::Keyboard::D){
                m_d = false;
            }
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
    else if(GamepadManager::getConnected()){
        m_direction = sf::Vector2f(sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X)/100.f,sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::Y)/100.f);
    }
    else{
        m_direction = sf::Vector2f(0.f,0.f);
    }
    if(m_player != nullptr){
        MovementComponent* movComp = (MovementComponent*) Manager::getComponent((Entity*)m_player,Component::getType<MovementComponent>());
        RectComponent* rectComp = (RectComponent*) Manager::getComponent((Entity*)m_player,Component::getType<RectComponent>());
        RectColliderComponent * colliderComp = (RectColliderComponent*) Manager::getComponent(m_player,Component::getType<RectColliderComponent>());
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
    
            if(colliderComp == nullptr){
                rectComp->getRectangleShape()->move(movComp->getVelocity().x * dt, dt * movComp->getVelocity().y);
            }
            else{
                float nx = movComp->getVelocity().x * dt;
                float ny = movComp->getVelocity().y * dt;

                float xcolx = rectComp->getRectangleShape()->getPosition().x + nx + colliderComp->getX();
                float xcoly = rectComp->getRectangleShape()->getPosition().y + colliderComp->getY();
                float ycolx = rectComp->getRectangleShape()->getPosition().x + colliderComp->getX();
                float ycoly = rectComp->getRectangleShape()->getPosition().y + ny + colliderComp->getY();
                float colw = colliderComp->getWidth();
                float colh = colliderComp->getHeight();
                
                bool coltestx = false;
                bool coltesty = false;

                for(auto&i : Manager::getEntitiesWith(Component::getType<RectColliderComponent>())){
                    RectComponent* rectBox = (RectComponent*) Manager::getComponent(i,Component::getType<RectComponent>());
                    RectColliderComponent* rectCol = (RectColliderComponent*) Manager::getComponent(i,Component::getType<RectColliderComponent>());
                    if(rectBox != nullptr && rectCol != nullptr && i != m_player){
                        float rectx = rectBox->getRectangleShape()->getPosition().x + rectCol->getX();
                        float recty = rectBox->getRectangleShape()->getPosition().y + rectCol->getY();
                        float rectw = rectCol->getWidth();
                        float recth = rectCol->getHeight();
                        
                        if( xcolx < rectx + rectw &&
                            xcolx + colw > rectx &&
                            xcoly < recty + recth &&
                            xcoly + colh > recty){
                                coltestx = true;
                        }
                        if( ycolx < rectx + rectw &&
                            ycolx + colw > rectx &&
                            ycoly < recty + recth &&
                            ycoly + colh > recty){
                                coltesty = true;
                        }
                    }
                }

                if(!coltestx){
                    rectComp->getRectangleShape()->move(nx,0);
                }
                if(!coltesty){
                    rectComp->getRectangleShape()->move(0,ny);
                }
            }
        }
    }
}

