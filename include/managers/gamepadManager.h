#pragma once

#include <SFML/Graphics.hpp>

#include "events/listener.h"
#include "events/event.h"

class GamepadManager : public Listener{
    public:
        static bool getConnected();
        void onEvent(Event) override;
        virtual ~GamepadManager(){}
    private:
        static bool m_isConnected;
};
