#include "scenes/gameScene.h"

#include <iostream>

#include "managers/manager.h"
#include "entities/entity.h"
#include "entities/player.h"
#include "components/rectComponent.h"
#include "components/movementComponent.h"
#include "components/textureComponent.h"
#include "components/physicsComponent.h"
#include "components/rectColliderComponent.h"
#include "systems/movementSystem.h"
#include "systems/physicsSystem.h"
#include "systems/renderingSystem.h"
#include "systems/textureLoadingSystem.h"


void GameScene::start(){

    std::cout << " \n GameScene started \n \n";
    
    Entity* entity0 = new Entity();
    Entity* entity1 = new Entity();
    Player* player = new Player();

    Manager::addEntity(entity0);
    Manager::addEntity(entity1);
    Manager::addEntity(player);

    Manager::addComponent(entity0, new RectComponent(128,128,512,512));
    Manager::addComponent(entity0, new TextureComponent("txt.png"));
    Manager::addComponent(entity0, new RectColliderComponent(0,0,512,512));
    Manager::addComponent(entity1, new RectComponent(640,256,128,128));
    Manager::addComponent(entity1, new TextureComponent("txt.png"));
    Manager::addComponent(entity1, new RectColliderComponent(0,0,128,128));
    Manager::addComponent(player, new RectComponent(0,0,64,64));
    Manager::addComponent(player, new TextureComponent("player.png"));
    Manager::addComponent(player, new RectColliderComponent(0,0,64,64));
    Manager::addComponent(player, new PhysicsComponent());
    Manager::addComponent(player, new MovementComponent());

    Manager::addSystem(new RenderingSystem());
    Manager::addSystem(new TextureLoadingSystem());
    Manager::addSystem(new PhysicsSystem());
    Manager::addSystem(new MovementSystem());

    for(auto&i : Manager::getSystems()){
        i->start();
    }
}

void GameScene::update(){
    for(auto&i : Manager::getSystems()){
        i->update();
    }
}

void GameScene::render(){
    for(auto&i : Manager::getSystems()){
        i->render();
    }
}

void GameScene::cleanUp(){
    Manager::cleanUp();
}
