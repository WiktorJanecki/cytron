#pragma once

#include "callable.h"

class Scene : Callable {
    public:
       virtual void start()=0;
       virtual void update()=0;
       virtual void render()=0;
       virtual void cleanUp()=0;
       virtual ~Scene(){};
};
