#pragma once

#include "scenes/scene.h"

class GameScene : Scene{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp() override;
};
