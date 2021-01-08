#pragma once

#include <SFML/Graphics.hpp>

#include "scenes/scene.h"

class MenuScene : Scene{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp() override;

        void handleEvents(sf::Event) override;
        ~MenuScene();
};
