#pragma once

#include <SFML/Graphics.hpp>

#include "callable.h"

class TimeManager : Callable{
public:
	static int getFPS();
	static void count();
private:
public:
private:
	static sf::Clock m_clock;
	static int m_fps;
	static int m_fpsHelper;
};