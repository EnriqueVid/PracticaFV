/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: newman
 * 
 * Created on 10 de abril de 2018, 17:47
 */
#include "Sprite.h"

Sprite::Sprite(){
    
}

Sprite::Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position)
{
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    
    _animationFrame=-1;
    _animation = false;
    
    _clock = new Clock();
}

Sprite::Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);
    
    _animationFrame=-1;
    _animation = false;
    
    _clock = new Clock();
}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position)
{
    //crear una animacion
    _sprite.setTexture(*texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    
    _animationFrame=0;
    _animation = true;
    
    _clock = new Clock();
}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    //crear una animacion
    _sprite.setTexture(*texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);
    
    _animationFrame=0;
    _animation = true;
    
    _clock = new Clock();
}

Sprite::Sprite(const Sprite& orig)
{
    
}

Sprite::~Sprite()
{
    delete _box;
    delete _clock;
}
    
bool Sprite::spriteIntersectsBounds(Sprite* spr)
{
    if(_box->intersects(*spr->getBox())){
        return true;
    }
    else{
        return false;
    }
}

bool Sprite::spriteIntersectsPixel(Sprite* spr)
{
    //Collision::PixelPerfect(spr);
    if(spriteIntersectsBounds(spr))
    {
        //if Collision::PixelPerfect(spr){
        return true;
        //}
    }
    return false;
}

void Sprite::spriteMove(sf::Vector2f move)
{
    _sprite.move(move);
}

void Sprite::spriteRotate(float rot)
{
    _sprite.rotate(rot);
}

void Sprite::spriteScale(sf::Vector2f scale)
{
    _sprite.scale(scale);
}
    
void Sprite::setSpritePosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

void Sprite::setSpriteOrigin(sf::Vector2f orig)
{
    _sprite.setOrigin(orig);
}

void Sprite::setSpriteScale(sf::Vector2f scale)
{
    _sprite.setScale(scale);
}

void Sprite::setSpriteRotation(float rot)
{
    _sprite.setRotation(rot);
}

void Sprite::setSpriteColor(int r, int g, int b, int a)
{
    _sprite.setColor(sf::Color(r,g,b,a));
}

void Sprite::setSpriteTexture(Texture* texture)
{
    _sprite.setTexture(*texture->getTextureTexture());
}

void Sprite::setSpriteTextureRect(sf::IntRect box)
{
    _sprite.setTextureRect(box);
}
    
sf::Vector2f Sprite::getSpritePosition()
{
    return _sprite.getPosition();
}

sf::Vector2f Sprite::getSpriteOrigin()
{
    return _sprite.getOrigin();
}

sf::Vector2f Sprite::getSpriteScale()
{
    return _sprite.getScale();
}

float Sprite::getSpriteRotation()
{
    return _sprite.getRotation();
}

sf::Sprite Sprite::getSpriteSprite()
{
    return _sprite;
}

sf::IntRect* Sprite::getBox(){
    return _box;
}