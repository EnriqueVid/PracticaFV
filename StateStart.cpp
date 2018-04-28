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


#include "StateStart.h"


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
    std::cout<<"Creado el estado de START"<<std::endl;
    _tstartbg->textureLoadFromFile("./textures/start.jpg");
    _tstartbutton->textureLoadFromFile("./textures/startbutton.png");
    _sstartbg->setSpriteTexture(_tstartbg);
    _sstartbutton->setSpriteTexture(_tstartbutton);
}

StateStart::StateStart(const StateStart & )
{
    
}

State* StateStart::GetNextState(int which)
{
    if(which == 2)
    {
        StateGameLoop* stateLoop = StateGameLoop::Instance();
        return stateLoop;
    
    }else if(which == 3)
    {
        StateGameOver* stateover = StateGameOver::Instance();
        return stateover;     
    }
}

void  StateStart::test()
{
    std::cout <<"Inicio del juego" << std::endl;
}

State*  StateStart::getState()
{
    return _pinstance;
}

int  StateStart::getStateNumber()
{
    return 1;
}

void  StateStart::update()
{
  Input* input = Input::Instance();
  input->inputInput();
  if(input->inputCheck(13) && _sstartbutton->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
  {
    _pinstance->GetNextState(2);
  }
}

StateStart::~StateStart()
{
   delete _tstartbutton;
   delete _sstartbutton;
   delete _tstartbg;
   delete _sstartbg;
   delete _pinstance;
   _tstartbutton = NULL;
   _sstartbutton = NULL;
   _pinstance = NULL;
   _tstartbutton = NULL;
   _sstartbutton = NULL;
}