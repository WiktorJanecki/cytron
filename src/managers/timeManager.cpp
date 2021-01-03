#include "managers/timeManager.h"

#include <SFML/Graphics.hpp>

#include "managers/windowManager.h"


int TimeManager::getFPS(){
	return m_fps;
}

float TimeManager::getDT(){
    return m_dt;
}

void TimeManager::count(){
	m_fpsHelper++;
	if(m_fpsClock.getElapsedTime().asSeconds() >= 1.0f){
		m_fps = m_fpsHelper;
		m_fpsHelper = 0;
		m_fpsClock.restart();
		//TODO MOVE TO ONSECONDCALLBACK
		WindowManager::changeTitle("cytron     FPS: "+std::to_string(m_fps));
	}
    m_dt = m_dtClock.restart().asSeconds();
}	           

sf::Clock TimeManager::m_fpsClock = sf::Clock();
sf::Clock TimeManager::m_dtClock = sf::Clock();
int TimeManager::m_fps = 0;
int TimeManager::m_fpsHelper = 0;
float TimeManager::m_dt = 0;


