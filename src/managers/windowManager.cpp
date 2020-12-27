#include "managers/windowManager.h"

#include <SFML/Graphics.hpp>
#include <string>

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

sf::RenderWindow* WindowManager::m_window = new sf::RenderWindow();