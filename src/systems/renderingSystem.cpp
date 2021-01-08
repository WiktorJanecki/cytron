#include "systems/renderingSystem.h"

#include <SFML/Graphics.hpp>

#include "managers/windowManager.h"
#include "managers/manager.h"
#include "components/rectComponent.h"

RenderingSystem::RenderingSystem(){}

void RenderingSystem::start(){}

void RenderingSystem::update(){}

void RenderingSystem::render(){
    for(auto& i: Manager::getEntitiesWith(Component::getType<RectComponent>())){
        RectComponent* rectComponent =(RectComponent*) Manager::getComponent(i,Component::getType<RectComponent>());
        if(rectComponent != nullptr){
            WindowManager::getWindow()->draw(*(rectComponent->getRectangleShape()));
        }
    }
}
