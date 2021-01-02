#pragma once

#include "events/event.h"

class onEvent{
    public:
        virtual void listenEvent(Event) = 0;
};
