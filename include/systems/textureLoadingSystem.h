#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

#include "systems/system.h"

class TextureLoadingSystem : System{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp();
        virtual ~TextureLoadingSystem();
    private:
        std::unordered_map<std::string, sf::Texture*> m_textures;
};
