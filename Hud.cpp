/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hud.cpp
 * Author: tuba
 * 
 * Created on 28 de abril de 2018, 15:40
 */

#include "Hud.h"

Hud* Hud::_pinstance = 0;

Hud* Hud::Instance()
{
    if(_pinstance == 0)
    {
        _pinstance = new Hud;
    }
    return _pinstance;
}

Hud::Hud()
{
    
    
    _thudbox = new Texture("./textures/HUDBOX.png");
    _life = new Sprite();
    _rectangle = new Sprite();
    _stamina = new Sprite();
    _shudbox = new Sprite();
    _shudbox->setSpriteTexture(_thudbox);
    _shudbox->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(0, 0)));
    _shudbox->setSpriteColor(255,255,255,150);

}

Hud::Hud(const Hud& orig)
{
}

Hud::~Hud()
{
    delete _life;
    _life = NULL;
    delete _rectangle;
    _rectangle = NULL;
    delete _stamina;
    _stamina = NULL;
    delete _shudbox;
    delete _thudbox;
    _shudbox = NULL;
    _thudbox = NULL;
}

void Hud::update(float life, float stamina, int r, int g, int b, int a)
{
    _life->setSpriteScale(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.23, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.05));
    _rectangle->setSpriteScale(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.02, RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.02));
    _stamina->setSpriteScale(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.18, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.05));
    _shudbox->setSpriteScale(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.0018, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.0025));
    _life->setSpriteScale(sf::Vector2f(float((life*100)/256),10));
    _rectangle->setSpriteColor(r, g, b, a);
    _stamina->setSpriteColor(r, g, b, a);
    _stamina->setSpriteScale(sf::Vector2f(float((stamina*80)/240),10));    
}

void Hud::setSprites(Texture* texture)
{
    _life->setSpriteTexture(texture);
    _life->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _life->setSpriteColor(255,255,255,255);
    _life->setSpriteScale(sf::Vector2f(1,1));
    _life->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(0, -20)));

    _rectangle->setSpriteTexture(texture);
    _rectangle->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _rectangle->setSpriteColor(255,255,255,255);
    _rectangle->setSpriteScale(sf::Vector2f(15,15));
    _rectangle->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(20, 100)));

    
    _stamina->setSpriteTexture(texture);
    _stamina->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _stamina->setSpriteColor(255,255,255,255);
    _stamina->setSpriteScale(sf::Vector2f(100,5));
    _stamina->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(55, 200)));
  
}

void Hud::setPosition()
{ 
    _shudbox->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(0.f,0.f)));
    _life->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.05, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.10)));
    _rectangle->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.05, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.23)));
    _stamina->setSpritePosition(RenderWindow::Instance()->windowMapPixelToCoords(sf::Vector2i(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.18, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.25)));
    
   //_life->setSpritePosition(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.20, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.125));
    //_rectangle->setSpritePosition(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.085, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.21));
    //_stamina->setSpritePosition(sf::Vector2f(RenderWindow::Instance()->getWindowWindow()->getView().getSize().x * 0.26, RenderWindow::Instance()->getWindowWindow()->getView().getSize().y * 0.21));
  
}


Sprite* Hud::getLife()
{
    return _life;
}

Sprite* Hud::getRectangle()
{
    return _rectangle;
}

Sprite* Hud::getStamina()
{
    return _stamina;
}

Sprite* Hud::getHUDBOX()
{
    return _shudbox;
}

