#include "managers/timeManager.h"

#include <SFML/Graphics.hpp>

#include "managers/windowManager.h"


int TimeManager::getFPS(){
	return m_fps;
}

void TimeManager::count(){
	m_fpsHelper++;
	if(m_clock.getElapsedTime().asSeconds() >= 1.0f){
		m_fps = m_fpsHelper;
		m_fpsHelper = 0;
		m_clock.restart();
		//TODO MOVE TO ONSECONDCALLBACK
		WindowManager::changeTitle("cytron     FPS: "+std::to_string(m_fps));
	}
}	           

sf::Clock TimeManager::m_clock = sf::Clock();
int TimeManager::m_fps = 0;
int TimeManager::m_fpsHelper = 0;


