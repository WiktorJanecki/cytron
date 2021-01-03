#include "scenes/menuScene.h"

#include <iostream>

#include "managers/manager.h"
#include "entities/entity.h"
#include "entities/player.h"
#include "components/component.h"
#include "components/rectComponent.h"
#include "components/textureComponent.h"
#include "components/movementComponent.h"
#include "components/physicsComponent.h"
#include "systems/renderingSystem.h"
#include "systems/textureLoadingSystem.h"
#include "systems/physicsSystem.h"
#include "systems/movementSystem.h"

void MenuScene::start(){
    std::cout << " \n MenuScene started \n \n";
    
    Entity* entity0 = new Entity;
    Entity* entity1 = new Entity;
    Player* player = new Player;
    Manager::addEntity(entity0);
    Manager::addEntity(entity1);
    Manager::addEntity((Entity*)player);

    Manager::addComponent(entity0,(Component*) new RectComponent(0,0,512,512));
    Manager::addComponent(entity0,(Component*) new TextureComponent("txt.png"));
    Manager::addComponent(entity0,(Component*) new PhysicsComponent());

    Manager::addComponent(entity1,(Component*) new RectComponent(512,512,512,512));
    Manager::addComponent(entity1,(Component*) new TextureComponent("txt.png"));

    Manager::addComponent((Entity*)player,(Component*) new RectComponent(500,500,64,64));
    Manager::addComponent((Entity*)player,(Component*) new TextureComponent("txt.png"));
    Manager::addComponent((Entity*)player,(Component*) new MovementComponent());

    Manager::addSystem((System*) new RenderingSystem);
    Manager::addSystem((System*) new TextureLoadingSystem);
    Manager::addSystem((System*) new PhysicsSystem);
    Manager::addSystem((System*) new MovementSystem);

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

MenuScene::~MenuScene(){}
