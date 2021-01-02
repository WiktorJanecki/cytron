#pragma once

#include <SFML/Graphics.hpp>

#include "callable.h"

class System : virtual Callable{
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

    virtual void handleEvent(sf::Event){}; 

    virtual ~System(){};
};
