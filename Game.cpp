/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: carlos
 * 
 * Created on 17 de abril de 2018, 19:51
 */

#include "Game.h"
#include "State.h"

Game::Game() {

}

Game::Game(const Game& orig) {
    
}

Game::Game(State* stateGame){
    _state = stateGame;
}
    
void Game::StateChanged(){
    if(_state){
        //Obtenemos siguiente estado
        State* pState = _state->GetNextState();
        //borro el anterior estado
        _state = pState;
    }
}
char* Game::getStateName(){
    
}

void Game::testState(){
    _state->test();
}

Game::~Game() {

}

