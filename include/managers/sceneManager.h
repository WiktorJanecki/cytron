#pragma once

#include "callable.h"
#include "scenes/scene.h"

class SceneManager : Callable{
public:
    static Scene* getCurrentScene();
    static void changeScene(Scene*);
    static void initScene(Scene*);
private:
    static Scene* m_currentScene;
};
