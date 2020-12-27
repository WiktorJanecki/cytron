#include <iostream>
#include "game.h"
#include "definitions.h"
#include "managers/manager.h"

void Game::start(){
	this->m_manager = new Manager;
	std::cout<< VERSION;
}

void Game::update(){

}

void Game::render(){

}