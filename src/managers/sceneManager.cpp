#include "managers/sceneManager.h"

#include "scenes/scene.h"
#include "managers/manager.h"

Scene* SceneManager::getCurrentScene(){
    return m_currentScene;
}

void SceneManager::changeScene(Scene* next){
    m_currentScene->cleanUp();
    delete m_currentScene;
    m_currentScene = next;
    m_currentScene->start();
}

void SceneManager::initScene(Scene* next){
    m_currentScene = next;
    m_currentScene->start();
};

Scene* SceneManager::m_currentScene = nullptr;
