#pragma once

#include <SFML/Graphics.hpp>

#include "components/component.h"

class MovementComponent : Component{
    public:
        MovementComponent();

        void setVelocity(sf::Vector2f);
        void setAcceleration(sf::Vector2f);

        sf::Vector2f getVelocity();
        sf::Vector2f getAcceleration();

        void increaseVelocity(float, float);
        void increaseAcceleration(float, float);
    private:
        sf::Vector2f m_velocity;
        sf::Vector2f m_acceleration;
};
