#include "components/textureComponent.h"

#include <string>

#include "components/component.h"


TextureComponent::TextureComponent(){

}

TextureComponent::TextureComponent(std::string path){
    m_path = path;
}

void TextureComponent::setPath(std::string path){
    m_path = path;
}

std::string TextureComponent::getPath(){
    return m_path;
}
