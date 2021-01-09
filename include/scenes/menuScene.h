#pragma once

#include <SFML/Graphics.hpp>

#include "scenes/scene.h"
#include "events/listener.h"
#include "events/event.h"

class MenuScene :public Scene, public Listener{
    public:
        void start() override;
        void update() override;
        void render() override;
        void cleanUp() override;

        void onEvent(Event) override;
        ~MenuScene();
};
