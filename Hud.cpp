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

void Hud::update(float life, float stamina, sf::Color color)
{
    _life->setSpriteScale(sf::Vector2f(float((life*100)/256),20));
    
    _rectangle->setSpriteColor(color.r,color.g,color.b, color.a);
    
    _stamina->setSpriteColor(color.r,color.g,color.b, color.a);
    _stamina->setSpriteScale(sf::Vector2f(float((stamina*60)/100),10));
}

void Hud::setSprites(Texture* texture)
{
    _life->setSpriteTexture(texture);
    _life->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _life->setSpriteColor(255,255,255,1);
    _life->setSpriteScale(sf::Vector2f(100,20));
    _life->setSpritePosition(sf::Vector2f(5,5));
    
    _rectangle->setSpriteTexture(texture);
    _rectangle->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _rectangle->setSpriteColor(255,255,255,1);
    _rectangle->setSpriteScale(sf::Vector2f(30,30));
    _rectangle->setSpritePosition(sf::Vector2f(10,30));
    
    _stamina->setSpriteTexture(texture);
    _stamina->setSpriteTextureRect(sf::IntRect(16,16,1,1));
    _stamina->setSpriteColor(255,255,255,1);
    _stamina->setSpriteScale(sf::Vector2f(60,10));
    _stamina->setSpritePosition(sf::Vector2f(40,35));
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

