#pragma once

#include <string>

#include "components/component.h"

class TextureComponent : public Component{
    public:
        TextureComponent();
        TextureComponent(std::string);

        void setPath(std::string);
        std::string getPath();
    private:
        std::string m_path;
};

