#pragma once

#include <SFML/Graphics.hpp>

#include "components/component.h"

class MovementComponent : public Component{
    public:
        MovementComponent();

        void setVelocity(float, float);
        void setAcceleration(float, float);

        sf::Vector2f getVelocity();
        sf::Vector2f getAcceleration();

        void increaseVelocity(float, float);
        void increaseAcceleration(float, float);
    private:
        sf::Vector2f m_velocity;
        sf::Vector2f m_acceleration;
};
