/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyChase.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 23:02
 */

#include "EnemyChase.h"

EnemyChase::EnemyChase(Texture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern): Enemy(tex, box, origin, position, scale) 
{
    _pattern = pattern;
    _cone = new Sprite(tex, sf::IntRect(160, 112, 96, 144), sf::Vector2f(48.0f,0.0f), position, scale);
}

EnemyChase::EnemyChase(const EnemyChase& orig) {
}

EnemyChase::~EnemyChase() {
}

