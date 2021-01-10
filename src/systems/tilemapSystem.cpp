#include "systems/tilemapSystem.h"

#include <string>

#include "components/tilemapComponent.h"
#include "components/component.h"
#include "managers/manager.h"

void TilemapSystem::start(){
    for(auto&ent : Manager::getEntitiesWith(Component::getType<TilemapComponent>())){
        //bierzemy syćkie id
        //procesujemy je u id managerja i dostajemy cosik w stylu klasy tile
        //loadujemy textury do hashmapy i ta sama textura - ten sam sprite
        // z hashmapy z txt generujemy hash mape z imi spritymi i renderujemy je przemieszczajac je
        //profit

    }
}

void TilemapSystem::update(){}

void TilemapSystem::render(){}
