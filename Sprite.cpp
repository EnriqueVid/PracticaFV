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

Sprite::Sprite(Texture* texture) 
{
    _sprite.setTexture(texture);
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
}

