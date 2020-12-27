#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "callable.h"

class WindowManager : Callable{
public:
	static sf::RenderWindow* createWindow(int, int, std::string);
	static sf::RenderWindow* getWindow();
	static void changeTitle(std::string);
private:
public:
private:
	static sf::RenderWindow* m_window;
	static std::string title;
};