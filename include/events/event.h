#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Event{
    public:
        std::string type;

        //all possible types;

        sf::Event sfEvent;
};
