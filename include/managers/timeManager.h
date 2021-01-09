#pragma once

#include <SFML/Graphics.hpp>

class TimeManager{
public:
	static int getFPS();
    static float getDT();
	static void count();
private:
public:
private:
	static sf::Clock m_fpsClock;
    static sf::Clock m_dtClock;
	static int m_fps;
	static int m_fpsHelper;
    static float m_dt;
};
