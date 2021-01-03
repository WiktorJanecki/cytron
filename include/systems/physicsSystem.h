#pragma once

#include "systems/system.h"

class PhysicsSystem : System{
    public:
        PhysicsSystem();

        void start() override;
        void update() override;
        void render() override;
    private:
        void calculate(); 
};
