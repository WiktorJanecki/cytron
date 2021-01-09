#include "managers/windowManager.h"

#include <SFML/Graphics.hpp>
#include <string>

#include "managers/timeManager.h"

sf::RenderWindow* WindowManager::createWindow(int width, int height, std::string title){
	m_window->create(sf::VideoMode(width,height),title);
	return m_window;
}

sf::RenderWindow* WindowManager::getWindow(){
	return m_window;
}

void WindowManager::changeTitle(std::string title){
	m_window->setTitle(title);
}

void WindowManager::onEvent(Event ev){
    if(ev.type == EverySecondEvent::getType()){
        WindowManager::changeTitle("cytron    FPS: "+std::to_string(TimeManager::getFPS()));
    }
}

sf::RenderWindow* WindowManager::m_window = new sf::RenderWindow();
