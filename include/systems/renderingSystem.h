#pragma once

#include "systems/system.h"

class RenderingSystem : System{
public:
    RenderingSystem();
    void start() override;
    void update() override;
    void render() override;
};
