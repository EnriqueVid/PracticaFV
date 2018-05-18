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
#include "World.h"


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
    _aux = 0;

    _t1 = new Texture("./textures/startbg.png");
    _s1 = new Sprite();
    _s1->setSpriteTexture(_t1);
    _s1->setSpriteOrigin(sf::Vector2f(_s1->getSpriteTexture().getSize().x/2.f, _s1->getSpriteTexture().getSize().y/2.f));
    _s1->setSpritePosition(sf::Vector2f(400.f, 400.f));
    //FALTA INICIALIZAR WORLD
    _window = RenderWindow::Instance();
    _world = World::Instance();

    _world->buildWorld(-2);
    _window = RenderWindow::Instance();
    _nextLevel = 0;
    _actualLevel = 0;
    
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
    //std::cout <<"Juego en Marcha" << std::endl;
}
State*  StateGameLoop::getState()
{
    return _pinstance;
}
int  StateGameLoop::getStateNumber()
{
    //RenderWindow::Instance()->resetView();
    return 2;
}
int  StateGameLoop::update(RenderWindow* window)
{
    //std::cout<<"GAME LOOP"<<endl;
    Input* input = Input::Instance();
    input->inputInput();
    if(_world == NULL)
    {
        _world = World::Instance();
        _world->buildWorld(_actualLevel);
        
    }
    _world->update();
    
    
    if(World::Instance()->getLevelDone() == true)
    {
        _window->resetView();
        RenderWindow::Instance()->setViewZoom(0.45);
        RenderWindow::Instance()->setViewCenter(Player::Instance()->getPlayer()->getSpritePosition());
        _actualLevel = _world->getNextLevel();
        _world->resetWorld();
        _world = NULL;
    }
    
    if(Player::Instance()->getHealth() <= 0 || input->inputCheck(10))
    {   
        if(_aux == 3){
            _window->resetView();
            _world->resetWorld();
            _world = NULL;
            _pinstance->GetNextState(3);
            return 3;    
        }else
        {
            _aux = _aux +1;
            //RenderWindow::Instance()->resetView();
            return 2;
        }
    //HACER DELETE DE TODO;
    }else{
     
        //window->windowClear();
        //window->windowDraw(_s1);
        //window->windowDisplay();
        //RenderWindow::Instance()->resetView();
        return 2;
    }
    
    
    
    
}

StateGameLoop::~StateGameLoop()
{
    delete _pinstance;
    _pinstance = NULL;
}

void StateGameLoop::render(RenderWindow* window)
{
    if(_world!=NULL)
    {
        _world->render(window);
    }
    
}
