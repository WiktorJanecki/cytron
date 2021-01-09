#pragma once

#include "scenes/scene.h"

class SceneManager{
public:
    static Scene* getCurrentScene();
    static void changeScene(Scene*);
    static void initScene(Scene*);
private:
    static Scene* m_currentScene;
};
