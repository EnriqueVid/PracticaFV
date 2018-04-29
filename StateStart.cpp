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
    

    _tstartbg->textureLoadFromFile("./textures/startbg.png");
    _tstartbutton->textureLoadFromFile("./textures/startbutton.png");
    _sstartbg->setSpriteTexture(_tstartbg);
    _sstartbutton->setSpriteTexture(_tstartbutton);
    
    _tpj1->textureLoadFromFile("./textures/pjWhite.png");
    _tpj2->textureLoadFromFile("./textures/pjRed.png");
    _tpj3->textureLoadFromFile("./textures/pjGreen.png");
    _tpj4->textureLoadFromFile("./textures/pjBlue.png");
    
    _spj1->setSpriteTexture(_tpj1);
    _spj1->setSpriteOrigin(sf::Vector2f(_spj1->getSpriteTexture().getSize().x/2.f, _spj1->getSpriteTexture().getSize().y/2.f));
    _spj1->setSpritePosition(sf::Vector2f(400.f,350.f));
    _spj1->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj2->setSpriteTexture(_tpj2);
    _spj2->setSpriteOrigin(sf::Vector2f(_spj2->getSpriteTexture().getSize().x/2.f, _spj2->getSpriteTexture().getSize().y/2.f));
    _spj2->setSpritePosition(sf::Vector2f(200.f,700.f));
    _spj2->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj3->setSpriteTexture(_tpj3);
    _spj3->setSpriteOrigin(sf::Vector2f(_spj3->getSpriteTexture().getSize().x/2.f, _spj3->getSpriteTexture().getSize().y/2.f));    
    _spj3->setSpritePosition(sf::Vector2f(400.f,700.f));
    _spj3->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj4->setSpriteTexture(_tpj4);
    _spj4->setSpriteOrigin(sf::Vector2f(_spj4->getSpriteTexture().getSize().x/2.f, _spj4->getSpriteTexture().getSize().y/2.f));    
    _spj4->setSpritePosition(sf::Vector2f(600.f,700.f));
    _spj4->setSpriteScale(sf::Vector2f(2.5,2.5));
    
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

void  StateStart::update(RenderWindow* window)
{
  
  Input* input = Input::Instance();
  input->inputInput();
  if(input->inputCheck(13) && _sstartbutton->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
  {
      
    _pinstance->GetNextState(2);
    
  }else{
      
      if(input->inputCheck(13) && _spj1->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
      {
          _spj1->setSpriteRotation(90.f);
      }
      if(input->inputCheck(13) && _spj1->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
      {
          _spj2->setSpriteRotation(90.f);
      }
      if(input->inputCheck(13) && _spj1->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
      {
          _spj3->setSpriteRotation(90.f);
      }
      if(input->inputCheck(13) && _spj1->getGlobalBounds().contains((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y))
      {
          _spj4->setSpriteRotation(90.f);
      }
      window->windowClear();
      window->windowDraw(_sstartbg);
      window->windowDraw(_sstartbutton);
      window->windowDraw(_spj1);
      window->windowDraw(_spj2);
      window->windowDraw(_spj3);
      window->windowDraw(_spj4);
      window->windowDisplay();
      
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
   
       delete _tpj1;
    delete _tpj2;
    delete _tpj3;
    delete _tpj4;

    delete _spj1;
    delete _spj2;
    delete _spj3;
    delete _spj4;
    
    _tpj1 = NULL;
    _tpj2 = NULL;
    _tpj3 = NULL;
    _tpj4 = NULL;
    
    _spj1 = NULL;
    _spj2 = NULL;
    _spj3 = NULL;
    _spj4 = NULL;
}