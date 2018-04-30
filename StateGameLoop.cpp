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
    std::cout<<"Creado el state GAMELOOP"<<std::endl;
    
    _t1 = new Texture("./textures/startbg.png");
    _s1 = new Sprite();
    _s1->setSpriteTexture(_t1);
    _s1->setSpriteOrigin(sf::Vector2f(_s1->getSpriteTexture().getSize().x/2.f, _s1->getSpriteTexture().getSize().y/2.f));
    _s1->setSpritePosition(sf::Vector2f(400.f, 400.f));
    //FALTA INICIALIZAR WORLD
    
    
}


StateGameLoop::StateGameLoop(const StateGameLoop & )
{
}



State* StateGameLoop::GetNextState(int which)
{
    if(which == 1)
    {
        StateStart* statestart = StateStart::Instance();
        return statestart;
        
    }else if(which == 3)
    {
        StateGameOver* stateover = StateGameOver::Instance();
        return stateover;     
    }
}
void  StateGameLoop::test()
{
    std::cout <<"Juego en Marcha" << std::endl;
}
State*  StateGameLoop::getState()
{
    return _pinstance;
}
int  StateGameLoop::getStateNumber()
{
    return 2;
}
int  StateGameLoop::update(RenderWindow* window)
{
    std::cout<<"GAME LOOP"<<endl;
    Input* input = Input::Instance();
    input->inputInput();
  
    if(Player::Instance()->getHealth() == 0 || input->inputCheck(10) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
    _pinstance->GetNextState(3);
    return 3;
    //HACER DELETE DE TODO;
    }else{
     
        //window->windowClear();
        //window->windowDraw(_s1);
        //window->windowDisplay();
      
        return 2;
    }
}

StateGameLoop::~StateGameLoop()
{
    delete _pinstance;
    _pinstance = NULL;
}
