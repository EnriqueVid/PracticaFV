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

class Sprite {
public:
    Sprite(Texture* texture);
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
private:
    sf::Sprite _sprite;
    
};

#endif /* SPRITE_H */

