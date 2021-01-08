#pragma once

#include "systems/system.h"

class RenderingSystem : public System{
public:
    RenderingSystem();
    void start() override;
    void update() override;
    void render() override;
};
