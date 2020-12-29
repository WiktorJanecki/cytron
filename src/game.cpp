#include "game.h"

#include <iostream>

#include "definitions.h"
#include "managers/manager.h"
#include "managers/windowManager.h"
#include "managers/timeManager.h"
#include "entities/entity.h"
#include "components/component.h"
#include "components/rectComponent.h"
#include "systems/renderingSystem.h"

void Game::start(){
	WindowManager::createWindow(1280,720,"123");

    Entity* entity0 = new Entity();
    Manager::addEntity(entity0);
    
    RectComponent* rectComponent = new RectComponent(0.f,0.f,50.f,50.f);
    Manager::addComponent(entity0, (Component*) rectComponent);

    Manager::addSystem((System*)new RenderingSystem());

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
    WindowManager::getWindow()->clear();
    for(auto& i : Manager::getSystems()){
        i->render();
    }
    WindowManager::getWindow()->display();
}
