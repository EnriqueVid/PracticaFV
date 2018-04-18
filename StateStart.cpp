/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateStart.cpp
 * Author: carlos
 * 
 * Created on 18 de abril de 2018, 13:40
 */

#include "StateGameOver.h"
#include "StateGameLoop.h"
#include "StateStart.h"
#include <iostream>

StateStart* StateStart::_pinstance = 0;

StateStart* StateStart::Instance()
{
    if(_pinstance==0)
    {
        _pinstance = new StateStart;
    }
    return _pinstance;
}

StateStart::StateStart()
{
    std::cout<<"Creado."<<std::endl;
}
StateStart::StateStart(const StateStart & )
{
    
}

State* StateStart::GetNextState()
{
    StateGameLoop* stateLoop = StateGameLoop::Instance();
    return StateGameLoop::Instance();
}
void  StateStart::test()
{
    std::cout <<"Inicio del juego" << std::endl;
}
State*  StateStart::getState()
{
    
}
int  StateStart::getStateNumber()
{
        
}
void  StateStart::setState(State* nextState)
{
        
}

