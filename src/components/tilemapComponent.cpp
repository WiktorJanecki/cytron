#include "components/tilemapComponent.h"

TilemapComponent::TilemapComponent(){}

TilemapComponent::TilemapComponent(std::string src){
    m_tilemapSource = src;
}

void TilemapComponent::setTilemapSource(std::string src){
    m_tilemapSource = src;
}

std::string TilemapComponent::getTilemapSource(){
    return m_tilemapSource;
}

