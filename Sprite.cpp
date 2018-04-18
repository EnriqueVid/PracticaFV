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
    _sprite.setTexture(texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    
}

Sprite::Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _sprite.setTexture(texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);

    
}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position)
{
    _sprite.setTexture(texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _sprite.setTexture(texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);
}

Sprite::Sprite(const Sprite& orig)
{

}

Sprite::~Sprite()
{
    delete _box;
}
    
bool Sprite::spriteIntersectsBounds(Sprite* spr)
{

}

bool Sprite::spriteIntersectsPixel(Sprite* spr)
{

}

void Sprite::spriteMove(sf::Vector2f move)
{

}

void Sprite::spriteRotate(float rot)
{

}

void Sprite::spriteScale(sf::Vector2f scale)
{

}
    
void Sprite::setSpritePosition(sf::Vector2f pos)
{

}

void Sprite::setSpriteOrigin(sf::Vector2f orig)
{

}

void Sprite::setSpriteScale(sf::Vector2f scale)
{

}

void Sprite::setSpriteRotation(float rot)
{

}

void Sprite::setSpriteColor(int r, int g, int b, int a)
{

}

void setSpriteTexture(Texture* texture)
{
    
}

void setSpriteTextureRect(sf::IntRect box)
{
        
}
    
sf::Vector2f Sprite::getSpritePosition()
{

}

sf::Vector2f Sprite::getSpriteOrigin()
{

}

sf::Vector2f Sprite::getSpriteScale()
{

}

float Sprite::getSpriteRotation()
{

}

sf::Sprite Sprite::getSpriteSprite()
{
    return _sprite;
}