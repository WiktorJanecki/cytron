#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

#include "callable.h"
#include "systems/system.h"

class TextureLoadingSystem : System{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp();
        void handleEvent(sf::Event) override;
        virtual ~TextureLoadingSystem();
    private:
        std::unordered_map<std::string, sf::Texture*> m_textures;
};
