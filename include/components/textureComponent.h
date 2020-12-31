#pragma once

#include <string>

#include "components/component.h"

class TextureComponent : Component{
    public:
        TextureComponent();
        TextureComponent(std::string);

        void setPath(std::string);
        std::string getPath();
    private:
        std::string m_path;
};

