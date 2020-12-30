#pragma once

#include "scenes/scene.h"

class MenuScene : Scene{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp() override;
        ~MenuScene();
};
