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
    _sview = new View();
    _tstartbg = new Texture();
    _tstartbutton = new Texture();
    _tpj1 = new Texture();
    _tpj2 = new Texture();
    _tpj3 = new Texture();
    _tpj4 = new Texture();
    
    
    _tpj1->textureLoadFromFile("./textures/pjWhite.png");
    _tpj2->textureLoadFromFile("./textures/pjRed.png");
    _tpj3->textureLoadFromFile("./textures/pjGreen.png");
    _tpj4->textureLoadFromFile("./textures/pjBlue.png");
    _tstartbg->textureLoadFromFile("./textures/startbg.png");
    _tstartbutton->textureLoadFromFile("./textures/startbutton.png");
    
    //INTRECTS
    sf::IntRect irbg(0,0, 800, 800);
    sf::IntRect irbutton(0, 0 , 343, 147);
    sf::IntRect irpj(0, 0 , 32, 32);
    
    
    _sstartbg = new Sprite(_tstartbg, irbg);
    _sstartbutton = new Sprite(_tstartbutton, irbutton);
    _spj1 = new Sprite(_tpj1, irpj);
    _spj2 = new Sprite(_tpj2, irpj);
    _spj3 = new Sprite(_tpj3, irpj);
    _spj4 = new Sprite(_tpj4, irpj);
    

  
    _sstartbg->setSpriteOrigin(sf::Vector2f(_sstartbg->getGlobalBounds().width/2.f, _sstartbg->getGlobalBounds().height/2.f));


    _sstartbutton->setSpriteOrigin(sf::Vector2f(_sstartbutton->getSpriteTexture().getSize().x/2.f, _sstartbutton->getSpriteTexture().getSize().y/2.f));

    
    _spj1->setSpriteOrigin(sf::Vector2f(_spj1->getGlobalBounds().width/2.f, _spj1->getGlobalBounds().height/2.f));
    _spj1->setSpriteScale(sf::Vector2f(2.5,2.5));
    

    _spj2->setSpriteOrigin(sf::Vector2f(_spj2->getSpriteTexture().getSize().x/2.f, _spj2->getSpriteTexture().getSize().y/2.f));
    _spj2->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj3->setSpriteOrigin(sf::Vector2f(_spj3->getSpriteTexture().getSize().x/2.f, _spj3->getSpriteTexture().getSize().y/2.f));    
    _spj3->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj4->setSpriteOrigin(sf::Vector2f(_spj4->getSpriteTexture().getSize().x/2.f, _spj4->getSpriteTexture().getSize().y/2.f));    
    _spj4->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    
    
}

StateStart::StateStart(const StateStart & )
{
    
}

State* StateStart::GetNextState(int which)
{
    if(which == 2)
    {
        RenderWindow::Instance()->resetView();
        StateGameLoop* stateLoop = StateGameLoop::Instance();
        return stateLoop;
    
    }else if(which == 3)
    {
        RenderWindow::Instance()->resetView();
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

int  StateStart::update(RenderWindow* window)
{
    //COLOCAR LOS SPRITES
        //window->setViewZoom(1);
        _sstartbg->setSpritePosition(window->getViewCenter());
        _sstartbutton->setSpritePosition(sf::Vector2f(window->getViewCenter().x, window->getViewCenter().y+100.f));
        _spj1->setSpritePosition(sf::Vector2f(window->getViewCenter().x,window->getViewCenter().y+100.f-150.f));
        _spj2->setSpritePosition(sf::Vector2f(window->getViewCenter().x-200.f,window->getViewCenter().y+300.f));
        _spj3->setSpritePosition(sf::Vector2f(window->getViewCenter().x,window->getViewCenter().y+300.f));
        _spj4->setSpritePosition(sf::Vector2f(window->getViewCenter().x+200.f,window->getViewCenter().y+300.f));
        
     //PROSEGUIR
    
    //std::cout<<"START"<<endl;
  Input* input = Input::Instance();
  input->inputInput();
  
    sf::Vector2f p2c = window->windowMapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x - window->getWindowPosition().x - 10,sf::Mouse::getPosition().y - window->getWindowPosition().y - 38));
    
    std::cout << p2c.x << ", " << p2c.y << " / " << _spj1->getGlobalBounds().left << ", " << _spj1->getGlobalBounds().top<< endl;
    
    if((input->inputCheck(13) && _sstartbutton->getGlobalBounds().contains(p2c)) || input->inputCheck(11))
    {
        
        RenderWindow::Instance()->setViewZoom(0.45);
        RenderWindow::Instance()->setViewCenter(Player::Instance()->getPlayer()->getSpritePosition());
        return 2;
    }else{
      
      if(input->inputCheck(13) && _spj1->getGlobalBounds().contains(p2c))
      {
          _spj1->setSpriteRotation(_spj1->getSpriteRotation()+90.f);
      }
      if(input->inputCheck(13) && _spj2->getGlobalBounds().contains(p2c))
      {
          _spj2->setSpriteRotation(_spj2->getSpriteRotation()+90.f);
      }
      if(input->inputCheck(13) && _spj3->getGlobalBounds().contains(p2c))
      {
          _spj3->setSpriteRotation(_spj3->getSpriteRotation()+90.f);
      }
      if(input->inputCheck(13) && _spj4->getGlobalBounds().contains(p2c))
      {
          _spj4->setSpriteRotation(_spj4->getSpriteRotation()+90.f);
      }
      
      window->windowClear();
      
      window->windowDraw(_sstartbg);
      window->windowDraw(_sstartbutton);
      window->windowDraw(_spj1);
      window->windowDraw(_spj2);
      window->windowDraw(_spj3);
      window->windowDraw(_spj4);
      
      window->windowDisplay();
      
      
      return 1;
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