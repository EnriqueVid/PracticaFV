/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateGameOver.cpp
 * Author: carlos
 * 
 * Created on 17 de abril de 2018, 21:06
 */

#include "StateGameOver.h"
#include "StateStart.h"
#include "StateGameLoop.h"
#include <iostream>

StateGameOver* StateGameOver::_pinstance = 0;


StateGameOver* StateGameOver::Instance()
{
    if(_pinstance==0)
    {
        _pinstance = new StateGameOver;
    }
    return _pinstance;
}

StateGameOver::StateGameOver()
{
    std::cout<<"Creado."<<std::endl;
}
StateGameOver::StateGameOver(const StateGameOver & )
{
    
}

State* StateGameOver::GetNextState()
{
    StateStart* estadoInicio = StateStart::Instance();
    return estadoInicio;
}
void  StateGameOver::test()
{
    std::cout <<"Game over" << std::endl;
}
State*  StateGameOver::getState()
{
    
}
int  StateGameOver::getStateNumber()
{
        
}
void  StateGameOver::setState(State* nextState)
{
        
}

