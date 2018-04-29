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
    std::cout<<"Creado el estado de GAME OVER."<<std::endl;
    _tgameover = new Texture("./textures/gameover.png");
    _sgameover = new Sprite();
    _sgameover->setSpriteTexture(_tgameover);
}

StateGameOver::StateGameOver(const StateGameOver & )
{
}

State* StateGameOver::GetNextState(int which)
{
    if(which == 1)
    {
        StateStart* statestart = StateStart::Instance();
        return statestart;
        
    }else if(which == 2)
    {
        StateGameLoop* stateloop = StateGameLoop::Instance();
        return stateloop;     
    }
}

void  StateGameOver::test()
{
    std::cout <<"GAME OVER" << std::endl;
}
State*  StateGameOver::getState()
{
    return _pinstance;
}
int  StateGameOver::getStateNumber()
{
    return 3;
}

void StateGameOver::update(RenderWindow* window)
{
  Input* input = Input::Instance();
  input->inputInput();
  if(input->inputCheck(12) || input->inputCheck(14))
  {
    _pinstance->GetNextState(1);
    _pinstance->~StateGameOver();
  }else{
      window->windowClear();
      _sgameover->setSpritePosition(window->getWindowWindow()->getView().getCenter());
      window->windowDraw(_sgameover);
      window->windowDisplay();
  }
}

StateGameOver::~StateGameOver(){
    delete _tgameover;
    delete _sgameover;
    _tgameover = NULL;
    _sgameover = NULL;
    delete _pinstance;
    _pinstance = NULL;
}
