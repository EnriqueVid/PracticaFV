/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Situation.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 10:46
 */

#include "Situation.h"

Situation::Situation() 
{
    _pos_x=0.0;
    _pos_y=0.0;
    _angle=0.0;
}
Situation::Situation(const Situation& orig) 
{
    
}

Situation::Situation(float x, float y, float g)
{
    _pos_x=x;
    _pos_y=y;
    _angle=g;
    
}

    
sf::Vector2f Situation::getPosition()
{
    return sf::Vector2f(_pos_x,_pos_y);
}
float Situation::getPositionX()
{
    return _pos_x;
}
float Situation::getPositionY()
{
    return _pos_y;
}
    
float Situation::getAngle()
{
    return _angle;
}
    
void Situation::setPosition(float x, float y)
{
    _pos_x = x;
    _pos_y = y;
}
    
void Situation::setAngle(float g)
{
    _angle = g;
}



Situation::~Situation() 
{
}

