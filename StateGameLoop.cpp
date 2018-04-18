/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateGameLoop.cpp
 * Author: carlos
 * 
 * Created on 17 de abril de 2018, 20:22
 */

#include "StateGameLoop.h"
#include "StateGameOver.h"
#include <iostream>

StateGameLoop* StateGameLoop::_pinstance = 0;


StateGameLoop* StateGameLoop::Instance()
{
    if(_pinstance==0)
    {
        _pinstance = new StateGameLoop;
    }
    return _pinstance;
}

StateGameLoop::StateGameLoop()
{
    std::cout<<"Creado."<<std::endl;
}
StateGameLoop::StateGameLoop(const StateGameLoop & )
{
    
}



State* StateGameLoop::GetNextState()
{
    StateGameOver* stateGameOver = StateGameOver::Instance();
    return stateGameOver;
}
void  StateGameLoop::test()
{
    std::cout <<"Juego en Marcha" << std::endl;
}
State*  StateGameLoop::getState()
{
    
}
int  StateGameLoop::getStateNumber()
{
        
}
void  StateGameLoop::setState(State* nextState)
{
        
}

