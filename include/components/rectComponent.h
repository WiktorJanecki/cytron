#pragma once

#include <SFML/Graphics.hpp>

#include "components/component.h"


class RectComponent : Component{
public:
    RectComponent();
    RectComponent(float, float, float, float);
    sf::RectangleShape* getRectangleShape();
private:
    sf::RectangleShape m_shape;
};
