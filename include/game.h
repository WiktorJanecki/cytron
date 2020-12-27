#pragma once

#include <SFML/Graphics.hpp>

#include "managers/manager.h"

class Game{

private:
	sf::RenderWindow* m_window;

public:
	void start();
private:
	void updateEvents();
	void update();
	void render();
};
