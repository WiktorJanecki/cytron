#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "events/event.h"
#include "events/everySecondEvent.h"
#include "events/listener.h"

class WindowManager : public Listener{
public:
	static sf::RenderWindow* createWindow(int, int, std::string);
	static sf::RenderWindow* getWindow();
	static void changeTitle(std::string);
private:
public:
private:
	static sf::RenderWindow* m_window;
	static std::string title;
    void onEvent(Event) override;
};
