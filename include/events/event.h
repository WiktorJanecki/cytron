#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "events/everySecondEvent.h"

class Event{
    public:
        std::string type;

        //all possible types;

        sf::Event sfEvent;
        EverySecondEvent everySecondEvent;
};
