#include "scenes/menuScene.h"

#include <iostream>

#include "managers/manager.h"
#include "managers/windowManager.h"
#include "managers/sceneManager.h"
#include "entities/entity.h"
#include "components/component.h"
#include "components/rectComponent.h"
#include "components/textureComponent.h"
#include "systems/renderingSystem.h"
#include "systems/textureLoadingSystem.h"
#include "scenes/gameScene.h"

void MenuScene::start(){
    std::cout << " \n MenuScene started \n \n";
    
    Entity* entity0 = new Entity;
    Manager::addEntity(entity0);

    float sx = WindowManager::getWindow()->getSize().x;
    float sy = WindowManager::getWindow()->getSize().y;

    Manager::addComponent(entity0, new RectComponent(sx/2 - 256,sy/2 - 256,512,512));
    Manager::addComponent(entity0, new TextureComponent("menu.png"));

    Manager::addSystem(new RenderingSystem);
    Manager::addSystem(new TextureLoadingSystem);

    for(auto&i : Manager::getSystems()){
        i->start();
    }
}

void MenuScene::update(){
    for(auto&i : Manager::getSystems()){
        i->update();
    }
}

void MenuScene::render(){
    for(auto&i : Manager::getSystems()){
        i->render();
    }
}

void MenuScene::cleanUp(){
    Manager::cleanUp();
}

void MenuScene::handleEvents(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Space){
            SceneManager::changeScene((Scene*)new GameScene());
        }
    }
}

MenuScene::~MenuScene(){}
