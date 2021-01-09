#include "managers/timeManager.h"

#include <SFML/Graphics.hpp>

#include "managers/windowManager.h"
#include "managers/manager.h"
#include "events/event.h"
#include "events/everySecondEvent.h"


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
        Event ev; //Every second callback
        ev.type = EverySecondEvent::getType();
        Manager::initEvent(ev);
	}
    m_dt = m_dtClock.restart().asSeconds();
}	           

sf::Clock TimeManager::m_fpsClock = sf::Clock();
sf::Clock TimeManager::m_dtClock = sf::Clock();
int TimeManager::m_fps = 0;
int TimeManager::m_fpsHelper = 0;
float TimeManager::m_dt = 0;


