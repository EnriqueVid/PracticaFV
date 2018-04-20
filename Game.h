/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: carlos
 *
 * Created on 17 de abril de 2018, 19:51
 */

#ifndef GAME_H
#define GAME_H
#include "State.h"

class Game {
public:
    Game();
    Game(State* stateGame);
    Game(const Game& orig);
    
    void StateChanged();
    
    void testState();
    
    char* getStateName();
    
    virtual ~Game();
private:
    
protected:
    void DoCleanUp();

    State* _state;
    //Estados: Juego en marcha \ Game Over \ Pantalla de Inicio
    
};

#endif /* Game_H */

