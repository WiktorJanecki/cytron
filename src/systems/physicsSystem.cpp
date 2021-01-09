#include "systems/physicsSystem.h"

#include <iostream>

#include "managers/manager.h"
#include "managers/timeManager.h"
#include "components/rectComponent.h"
#include "components/physicsComponent.h"
#include "components/component.h"

PhysicsSystem::PhysicsSystem(){}

void PhysicsSystem::start(){}

void PhysicsSystem::update(){
    calculate();
}

void PhysicsSystem::render(){}

void PhysicsSystem::calculate(){
    for(auto&ent : Manager::getEntitiesWith(Component::getType<PhysicsComponent>())){
        RectComponent* rectComp = (RectComponent*) Manager::getComponent(ent,Component::getType<RectComponent>());
        PhysicsComponent* physicsComp = (PhysicsComponent*) Manager::getComponent(ent,Component::getType<PhysicsComponent>());
        
        if(rectComp != nullptr && physicsComp != nullptr){
            float dt = TimeManager::getDT();
            float friction = physicsComp->getFriction();
            sf::Vector2f acceleration = physicsComp->getAcceleration();
            
            //grav = physicsComp->increaseVelocity(0,-10.f * dt);
            
            physicsComp->increaseVelocity(acceleration.x * dt,acceleration.y * dt);

            if(physicsComp->getVelocity().x > 0){
                physicsComp->increaseVelocity(dt * -friction,0.f);
            }
            if(physicsComp->getVelocity().x < 0){
                physicsComp->increaseVelocity(dt* friction,0.f);
            }
            if(physicsComp->getVelocity().y > 0){
                physicsComp->increaseVelocity(0,dt * -friction);
            }
            if(physicsComp->getVelocity().y < 0){
                physicsComp->increaseVelocity(0,dt * friction);
            }

            sf::Vector2f velocity = physicsComp->getVelocity();
            rectComp->getRectangleShape()->move(velocity.x * dt, velocity.y * dt);
        }
    }
}

