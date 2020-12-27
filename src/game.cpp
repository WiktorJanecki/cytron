#include "game.h"

#include <iostream>

#include "definitions.h"
#include "managers/manager.h"
#include "managers/windowManager.h"
#include "managers/timeManager.h"
#include "entities/entity.h"
#include "components/component.h"

void Game::start(){
	WindowManager::createWindow(1280,720,"123");


	while(WindowManager::getWindow()->isOpen()){
		update();
		render();
	}
}

void Game::updateEvents(){
    sf::Event event;
    while (WindowManager::getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            WindowManager::getWindow()->close();
    }

}

void Game::update(){
	updateEvents();

	TimeManager::count();
}

void Game::render(){

}