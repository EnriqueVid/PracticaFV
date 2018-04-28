/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyStand.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 23:02
 */

#include "EnemyStand.h"

EnemyStand::EnemyStand(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern): Enemy(tex, origin, position, scale)
{
    _pattern = pattern;
    _cone = new Sprite(tex, sf::IntRect(160, 112, 96, 144), sf::Vector2f(48.0f,0.0f), position, scale);
}

EnemyStand::EnemyStand(const EnemyStand& orig) 
{
    
}

EnemyStand::~EnemyStand() 
{
    
}

