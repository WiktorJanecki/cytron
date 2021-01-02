#pragma once

#include <SFML/Graphics.hpp>


class System {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

    virtual void handleEvent(sf::Event){}; 

    virtual ~System(){};
};
