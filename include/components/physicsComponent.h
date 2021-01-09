#pragma once

#include "components/component.h"

#include <SFML/Graphics.hpp>

class PhysicsComponent : public Component{
    public:
        PhysicsComponent();
        
        void setVelocity(float, float);
        void setAcceleration(float, float);
        void setFriction(float);

        sf::Vector2f getVelocity();
        sf::Vector2f getAcceleration();
        float getFriction();

        void increaseVelocity(float,float);
        void increaseAcceleration(float,float);

        virtual ~PhysicsComponent(){}
    private:
        sf::Vector2f m_velocity = sf::Vector2f(0.f,0.f);
        sf::Vector2f m_acceleration = sf::Vector2f(0.f,0.f);
        float m_friction = 3.f;
};
