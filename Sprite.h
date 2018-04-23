/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.h
 * Author: newman
 *
 * Created on 10 de abril de 2018, 17:47
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "Clock.h"
#include "Bitmasks.h"


class Sprite {
public:
    Sprite();
    Sprite(Texture* texture, sf::IntRect box);
    Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position);
    Sprite(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position);
    Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale);
    Sprite(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
    bool spriteIntersectsBounds(Sprite* spr);    
    bool spriteIntersectsPixel(const sf::Sprite& Object2, sf::Uint8 AlphaLimit);
    void spriteMove(sf::Vector2f move);
    void spriteRotate(float rot);
    void spriteScale(sf::Vector2f scale);
    
    void setSpritePosition(sf::Vector2f pos);
    void setSpriteOrigin(sf::Vector2f orig);
    void setSpriteScale(sf::Vector2f scale);
    void setSpriteRotation(float rot);
    void setSpriteColor(int r, int g, int b, int a);
    void setSpriteTexture(Texture* texture);
    void setSpriteTextureRect(sf::IntRect box);
    
    Texture* getSpriteTexture();
    sf::Vector2f getSpritePosition();
    sf::Vector2f getSpriteOrigin();
    sf::Vector2f getSpriteScale();
    float getSpriteRotation();
    sf::Sprite getSpriteSprite();
    sf::IntRect getSpriteTextureRect();
    sf::FloatRect getGlobalBounds();
    sf::Transform  getSpriteInverseTransform();
        
    Clock* getClock();
    sf::IntRect* getBox(); //getTextureRect
    
private:
    sf::Sprite _sprite;
    Texture* _texture;
    
    sf::IntRect* _box;
    
    //sf::Transform _inverseTransform;
    
    Clock* _clock;
    
    bool _animation;
    int _animationFrame;
    
    Bitmasks* _bitmasks;
    
};

#endif /* SPRITE_H */

