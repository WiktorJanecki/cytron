#include "managers/gamepadManager.h"

#include <iostream>


void printNewGamepadInfo(bool*);

bool GamepadManager::getConnected(){
    return GamepadManager::m_isConnected;
}

void GamepadManager::onEvent(Event event){
    if(event.type == "sfEvent"){
        if(event.sfEvent.type == sf::Event::JoystickConnected){
            if(event.sfEvent.joystickConnect.joystickId == 0){
                printNewGamepadInfo(&m_isConnected);
            }
        }
        if(!m_isConnected && sf::Joystick::isConnected(0)){
            printNewGamepadInfo(&m_isConnected);
        }
    }
}

void printNewGamepadInfo(bool* m_isConnected){
    auto info = sf::Joystick::getIdentification(0);
    std::cout << "New gamepad connected: " << info.name.toAnsiString() << "\n";                                               
    std::cout << "Hint: Only xbox controllers are supported \n";                                                              
    std::cout << "Gamepad status: ";
    if(info.name.find("xbox")){                                                                                               
        std::cout<<"available \n";                                                                                            
        *m_isConnected = true;                                                                                              
    }                                                                                                                         
    else{                                                                                                                  
        std::cout<<"not supported :( \n";                                                                                  
    }                                                                                                                         
}

bool GamepadManager::m_isConnected = false;
