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
    
    sf::Font* fmes = new sf::Font();
    fmes->loadFromFile("./textures/Pixeled.ttf");
    
    _cual = 0;
    _contador = 0;
    _sview = new View();
    _tstartbg = new Texture();
    _tstartbutton = new Texture();
    _tpj1 = new Texture();
    _tpj2 = new Texture();
    _tpj3 = new Texture();
    _tpj4 = new Texture();
    _texit = new Texture();
    _thelp = new Texture();
    _tmes = new Texture();
    _tcar = new Texture();
    _tini1 = new Texture();
    _tini2 = new Texture();
    
    _tpj1->textureLoadFromFile("./textures/pjWhite.png");
    _tpj2->textureLoadFromFile("./textures/pjRed.png");
    _tpj3->textureLoadFromFile("./textures/pjGreen.png");
    _tpj4->textureLoadFromFile("./textures/pjBlue.png");
    _tstartbg->textureLoadFromFile("./textures/startbg.png");
    _tstartbutton->textureLoadFromFile("./textures/startbutton.png");
    _texit->textureLoadFromFile("./textures/exitbutton.png");
    _thelp->textureLoadFromFile("./textures/help.png");
    _tmes->textureLoadFromFile("./textures/fondotexto.png");
    _tcar->textureLoadFromFile("./textures/Cargando.png");
    _tini1->textureLoadFromFile("./textures/Inicio.png");
    _tini2->textureLoadFromFile("./textures/inicio2.png");
    
    
    //INTRECTS
    
    sf::IntRect irbg(0,0, 1280, 720);
    sf::IntRect irbutton(0, 0 , 343, 147);
    sf::IntRect irpj(0, 0 , 32, 32);
    sf::IntRect iexit(0, 0 , 330, 130);
    

    _sstartbg = new Sprite(_tstartbg, irbg);
    _sstartbutton = new Sprite(_tstartbutton, irbutton);
    _spj1 = new Sprite(_tpj1, irpj);
    _spj2 = new Sprite(_tpj2, irpj);
    _spj3 = new Sprite(_tpj3, irpj);
    _spj4 = new Sprite(_tpj4, irpj);
    _shelp  = new Sprite(_thelp, irpj);
    _sexit = new Sprite(_texit, iexit);
    _scar = new Sprite(_tcar, irbg);
    _sini1 = new Sprite(_tini1, irbg);
    _sini2 = new Sprite(_tini2, irbg);
    _car = new Sprite(_tini2, irbutton);
    
    _car->setSpriteTextureRect(sf::IntRect(0,0,1,1));
    _car->setSpriteScale(sf::Vector2f(1,1));

    _shelp->setSpriteOrigin(sf::Vector2f(_shelp->getGlobalBounds().width/2.f, _shelp->getGlobalBounds().height/2.f));
    _sexit->setSpriteOrigin(sf::Vector2f(_sexit->getGlobalBounds().width/2.f, _sexit->getGlobalBounds().height/2.f));
    _sexit->setSpriteScale(sf::Vector2f(0.3, 0.3));
    _shelp->setSpriteScale(sf::Vector2f(1.3, 1.3));
    
    _sstartbg->setSpriteOrigin(sf::Vector2f(_sstartbg->getGlobalBounds().width/2.f, _sstartbg->getGlobalBounds().height/2.f));
    _scar->setSpriteOrigin(sf::Vector2f(_scar->getGlobalBounds().width/2.f, _scar->getGlobalBounds().height/2.f));
    _sini1->setSpriteOrigin(sf::Vector2f(_sini1->getGlobalBounds().width/2.f, _sini1->getGlobalBounds().height/2.f));
    _sini2->setSpriteOrigin(sf::Vector2f(_sini2->getGlobalBounds().width/2.f, _sini2->getGlobalBounds().height/2.f));
    

    _sstartbutton->setSpriteOrigin(sf::Vector2f(_sstartbutton->getSpriteTexture().getSize().x/2.f, _sstartbutton->getSpriteTexture().getSize().y/2.f));

    
    _spj1->setSpriteOrigin(sf::Vector2f(_spj1->getGlobalBounds().width/2.f, _spj1->getGlobalBounds().height/2.f));
    _spj1->setSpriteScale(sf::Vector2f(2.5,2.5));
    

    _spj2->setSpriteOrigin(sf::Vector2f(_spj2->getSpriteTexture().getSize().x/2.f, _spj2->getSpriteTexture().getSize().y/2.f));
    _spj2->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj3->setSpriteOrigin(sf::Vector2f(_spj3->getSpriteTexture().getSize().x/2.f, _spj3->getSpriteTexture().getSize().y/2.f));    
    _spj3->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _spj4->setSpriteOrigin(sf::Vector2f(_spj4->getSpriteTexture().getSize().x/2.f, _spj4->getSpriteTexture().getSize().y/2.f));    
    _spj4->setSpriteScale(sf::Vector2f(2.5,2.5));
    
    _mehelp = new Message(0, fmes, _tmes, sf::FloatRect(0, 0, 608, 256), sf::Vector2f(400.f, 400.f));
    
    _snmes = 0;
    
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
     
        
    if(_cual < 2)
    {
        _contador = _contador + 2;
        
        //Playing music
        SoundManager* soundmanager = SoundManager::Instance();
        soundmanager->playMusic(1);
        soundmanager->setMusicVolume(30);
        //end music
        
    }else if(_cual == 3)
    {
            _contador = _contador +1; 
    }else{
        _contador = 0;
    }
    
    
    
    //COLOCAR LOS SPRITES
        //window->setViewZoom(1);
    
    
        
    
        _sstartbg->setSpritePosition(window->getViewCenter());
        _sstartbutton->setSpritePosition(sf::Vector2f(window->getViewCenter().x, window->getViewCenter().y+100.f));
        _spj1->setSpritePosition(sf::Vector2f(window->getViewCenter().x,window->getViewCenter().y+100.f-150.f));
        _spj2->setSpritePosition(sf::Vector2f(window->getViewCenter().x-200.f,window->getViewCenter().y+300.f));
        _spj3->setSpritePosition(sf::Vector2f(window->getViewCenter().x,window->getViewCenter().y+300.f));
        _spj4->setSpritePosition(sf::Vector2f(window->getViewCenter().x+200.f,window->getViewCenter().y+300.f));
        _shelp->setSpritePosition(sf::Vector2f(window->getViewCenter().x + 50.f, window->getViewCenter().y+200.f));
        _mehelp->getSpriteMessage()->setSpritePosition(window->getViewCenter());
        _mehelp->getTextMessage()->setPosition(window->getViewCenter().x-70, window->getViewCenter().y);
        _sexit->setSpritePosition(sf::Vector2f(window->getViewCenter().x - 50.f, window->getViewCenter().y+200.f));
        _scar->setSpritePosition(window->getViewCenter());
        _sini1->setSpritePosition(window->getViewCenter());
        _sini2->setSpritePosition(window->getViewCenter());
    
        _car->setSpriteScale(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.8, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.35));
        _car->setSpriteScale(sf::Vector2f(float(_contador)*2,40));
        _car->setSpritePosition(sf::Vector2f(window->getViewCenter().x - window->getWindowWindow()->getSize().x * 0.30,window->getViewCenter().y));    
   
     //PROSEGUIR
    
    //std::cout<<"START"<<endl;
  Input* input = Input::Instance();
  input->inputInput();
  
    sf::Vector2f p2c = window->windowMapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x - window->getWindowPosition().x - 10,sf::Mouse::getPosition().y - window->getWindowPosition().y - 38));
    
    //std::cout << p2c.x << ", " << p2c.y << " / " << _spj1->getGlobalBounds().left << ", " << _spj1->getGlobalBounds().top<< endl;
    
    if((input->inputCheck(13) && _sstartbutton->getGlobalBounds().contains(p2c)) && _cual == 2 || input->inputCheck(11) && _cual == 2)
    {
                    
        //Playing sound effect
        SoundManager* soundmanager = SoundManager::Instance();
        soundmanager->playSound(17);
        //end sound effect   
            
        _cual = 3;
        return 1;
    }else{
      
        if(_cual == 2)
        {
                if(input->inputCheck(13) && _spj1->getGlobalBounds().contains(p2c))
                {
                    _spj1->setSpriteRotation(_spj1->getSpriteRotation()+5.f);
                }
                if(input->inputCheck(13) && _spj2->getGlobalBounds().contains(p2c))
                {
                    _spj2->setSpriteRotation(_spj2->getSpriteRotation()+5.f);
                }
                if(input->inputCheck(13) && _spj3->getGlobalBounds().contains(p2c))
                {
                    _spj3->setSpriteRotation(_spj3->getSpriteRotation()+5.f);
                }
                if(input->inputCheck(13) && _spj4->getGlobalBounds().contains(p2c))
                {
                    _spj4->setSpriteRotation(_spj4->getSpriteRotation()+5.f);
                }
                if(input->inputCheck(13) && _sexit->getGlobalBounds().contains(p2c))
                {
                    //Playing sound effect
                    SoundManager* soundmanager = SoundManager::Instance();
                    soundmanager->playSound(10);
                    //end sound effect   
                    window->windowClose();
                }
                if(input->inputCheck(13) && _shelp->getGlobalBounds().contains(p2c))
                {        
                    _snmes = 1;
                }
                if(input->inputCheck(13) && !_shelp->getGlobalBounds().contains(p2c))
                {        
                    _snmes = 0;
                }
        }
      window->windowClear();
      
      if(_cual == 2)
      {
        window->windowDraw(_sstartbg);
        window->windowDraw(_sstartbutton);
        window->windowDraw(_spj1);
        window->windowDraw(_spj2);
        window->windowDraw(_spj3);
        window->windowDraw(_spj4);
        window->windowDraw(_shelp);
        window->windowDraw(_sexit);
        if(_snmes == 1)
        {
            window->windowDraw(_mehelp);
        }
        _contador = 0;
      
      }else if(_cual == 3)
      {
             
          window->windowDraw(_scar);
          window->windowDraw(_car);
          if(_contador == 400){
              _contador = 0;
              _cual = 0;
              RenderWindow::Instance()->setViewZoom(0.45);
              RenderWindow::Instance()->setViewCenter(Player::Instance()->getPlayer()->getSpritePosition());
              _cual = 2;
              return 2;
          }
      }else if(_cual == 0)
      {

          window->windowDraw(_sini1);
          if(_contador == 600){
              _contador = 0;
              _cual = 1;
          }
          
      }else if(_cual == 1)
      {
          window->windowDraw(_sini2);
          if(_contador == 600){
              _contador = 0;
              _cual = 2;
          }
      }
      
      
      
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