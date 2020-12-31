#pragma once

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

#include "callable.h"
#include "systems/system.h"


class TextureLoadingSystem : System{
    public:
        void start();
        void update();
        void render();
        void cleanUp();
        virtual ~TextureLoadingSystem();
    private:
        std::unordered_map<std::string, sf::Texture*> m_textures;
};
