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
    _life = new Sprite();
    _rectangle = new Sprite();
    _stamina = new Sprite();
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
}

void Hud::update(float life, float stamina, int r, int g, int b, int a)
{
    _life->setSpriteScale(sf::Vector2f(float((life*200)/256),20));
    
    _rectangle->setSpriteColor(r, g, b, a);
    
    _stamina->setSpriteColor(r, g, b, a);
    _stamina->setSpriteScale(sf::Vector2f(float((stamina*165)/100),10));
}

void Hud::setSprites(Texture* texture)
{
    _life->setSpriteTexture(texture);
    _life->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _life->setSpriteColor(255,255,255,255);
    _life->setSpriteScale(sf::Vector2f(200,20));
    _life->setSpritePosition(sf::Vector2f(20,20));
    
    _rectangle->setSpriteTexture(texture);
    _rectangle->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _rectangle->setSpriteColor(255,255,255,255);
    _rectangle->setSpriteScale(sf::Vector2f(30,30));
    _rectangle->setSpritePosition(sf::Vector2f(20,42));
    
    _stamina->setSpriteTexture(texture);
    _stamina->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _stamina->setSpriteColor(255,255,255,255);
    _stamina->setSpriteScale(sf::Vector2f(165,10));
    _stamina->setSpritePosition(sf::Vector2f(55,52));
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

