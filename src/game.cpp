#include "game.h"

#include <iostream>

#include "definitions.h"
#include "managers/sceneManager.h"
#include "managers/manager.h"
#include "managers/windowManager.h"
#include "managers/timeManager.h"
#include "scenes/scene.h"
#include "scenes/menuScene.h"
#include "entities/entity.h"
#include "components/component.h"
#include "components/rectComponent.h"
#include "systems/renderingSystem.h"

void Game::start(){
	WindowManager::createWindow(1280,720,"123");

    SceneManager::initScene((Scene*) new MenuScene );

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

    SceneManager::getCurrentScene()->update();
}

void Game::render(){
    WindowManager::getWindow()->clear();
    SceneManager::getCurrentScene()->render();
    WindowManager::getWindow()->display();
}
