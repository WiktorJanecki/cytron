#pragma once

#include "events/event.h"

class Listener{
    public:
        virtual void onEvent(Event) = 0;
        virtual ~Listener(){};
};
