#include "scenes/scene.h"

#include "managers/manager.h"
Scene::~Scene(){
    Manager::cleanUp();
}


