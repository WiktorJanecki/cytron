#pragma once

#include "entities/entity.h"

class Manager;

class Player : Entity{
    public:
        Player(){
            m_player = true;
        }
    friend class Manager;
};
