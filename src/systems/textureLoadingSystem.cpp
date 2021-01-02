#include "systems/textureLoadingSystem.h"

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "managers/manager.h"
#include "components/component.h"
#include "components/textureComponent.h"
#include "components/rectComponent.h"

void TextureLoadingSystem::start(){
    m_textures = std::unordered_map<std::string, sf::Texture*>();
    
    for(auto& i : Manager::getEntitiesWith(Component::Type::TEXTURE_COMPONENT)){
        TextureComponent* txtcomp = (TextureComponent*) Manager::getComponent(i,Component::Type::TEXTURE_COMPONENT);

        if(txtcomp != nullptr){
            if(m_textures.find(txtcomp->getPath()) != m_textures.end()){
                if(Manager::hasComponent(i,Component::Type::RECT_COMPONENT)){
                    ((RectComponent*)Manager::getComponent(i, Component::Type::RECT_COMPONENT))->getRectangleShape()->setTexture(m_textures[txtcomp->getPath()]);
                }
            }else{
                sf::Texture* txt = new sf::Texture();
                if(txt->loadFromFile("res/textures/" + txtcomp->getPath())){
                    m_textures.insert({txtcomp->getPath(),txt});
                    if(Manager::hasComponent(i,Component::Type::RECT_COMPONENT)){
                        ((RectComponent*)Manager::getComponent(i, Component::Type::RECT_COMPONENT))->getRectangleShape()->setTexture(m_textures[txtcomp->getPath()]);
                    }
                }
            }
        }
    }
}

void TextureLoadingSystem::update(){}

void TextureLoadingSystem::render(){}

void TextureLoadingSystem::cleanUp(){}

void TextureLoadingSystem::handleEvent(sf::Event ev){
        //std::cout<<ev.type;
}

TextureLoadingSystem::~TextureLoadingSystem(){
    for(auto&i : m_textures){
        delete i.second;
    }
    m_textures.clear();
}
