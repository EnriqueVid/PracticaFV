/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyBounce.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 20:30
 */

#include "EnemyBounce.h"


EnemyBounce::EnemyBounce(Texture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern): Enemy(tex, box, origin, position, scale) 
{
    _pattern = pattern;
}

EnemyBounce::EnemyBounce(const EnemyBounce& orig)
{
}

EnemyBounce::~EnemyBounce() {
}

