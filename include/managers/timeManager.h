#pragma once

#include <SFML/Graphics.hpp>

class TimeManager{
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
