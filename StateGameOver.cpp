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
    _sgameover->setSpriteOrigin(sf::Vector2f(_sgameover->getSpriteTexture().getSize().x/2.f, _sgameover->getSpriteTexture().getSize().y/2.f));
}

StateGameOver::StateGameOver(const StateGameOver & )
{
}

State* StateGameOver::GetNextState(int which)
{
    if(which == 1)
    {
        //RenderWindow::Instance()->resetView();
        StateStart* statestart = StateStart::Instance();
        return statestart;
        
    }else if(which == 2)
    {
        //RenderWindow::Instance()->resetView();
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

int StateGameOver::update(RenderWindow* window)
{
        std::cout<<"GAME OVER"<<endl;
  Input* input = Input::Instance();
  input->inputInput();
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      window->windowClose();
      return 1;
  }
  
  if(input->inputCheck(12) || input->inputCheck(14))
  {
      
    Player* pj = Player::Instance();
    pj->setHealth(200.f);
    return 1;
    
  }else{
      window->windowClear();
      _sgameover->setSpritePosition(window->getWindowWindow()->getView().getCenter());
      window->windowDraw(_sgameover);
      window->windowDisplay();
      return 3;
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
