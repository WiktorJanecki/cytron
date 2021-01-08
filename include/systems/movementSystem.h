#pragma once

#include <SFML/Graphics.hpp>

#include "systems/system.h"
#include "entities/player.h"

class MovementSystem :public System{
    public:
        MovementSystem();
        void start() override;
        void update() override;
        void render() override;

        void handleEvents(sf::Event) override;
    private:
        void calculate();
        sf::Vector2f m_direction = sf::Vector2f(0.f,0.f);
        Player* m_player;
        bool m_w = false;
        bool m_s = false;
        bool m_a = false;
        bool m_d = false;
};

