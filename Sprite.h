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
    Sprite(Texture* texture, sf::IntRect* box, int aniFrames, float aniTime);
    Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position);
    Sprite(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, int aniFrames, float aniTime);
    Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale);
    Sprite(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, int aniFrames, float aniTime);
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
    
    void setAnimationFrame(int f);
    void setAnimationNumFrames(int n);
    void setAnimationTime(float t);
    
    sf::Texture getSpriteTexture();
    sf::Vector2f getSpritePosition();
    sf::Vector2f getSpriteOrigin();
    sf::Vector2f getSpriteScale();
    float getSpriteRotation();
    sf::Sprite getSpriteSprite();
    sf::IntRect getSpriteTextureRect();
    sf::FloatRect getGlobalBounds();
    sf::Transform  getSpriteInverseTransform();
    
    int getAnimationFrame();
    
    
    void updateAnimation(); //cambia el frame de la animacion cuando haya animacion.
    void changeAnimation(sf::IntRect* box, int animationNumFrames, float animationTime);
    
    Clock* getClock();
    sf::IntRect* getBox(); //getTextureRect
    
private:
    sf::Sprite _sprite;
    sf::IntRect* _box;
    //sf::Transform _inverseTransform;
    Clock* _clock;
    bool _animation; //indica si tiene animacion
    int _animationFrame; //indica el frame de la animacion actual
    int _animationNumFrames; //indica el numero de frames de la animacion
    float _animationTime; //indica el tiempo que pasa hasta el siguiente frame
    Bitmasks* _bitmasks;
};

#endif /* SPRITE_H */

