/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stairs.cpp
 * Author: carlos
 * 
 * Created on 30 de abril de 2018, 0:18
 */

#include "Stairs.h"

Stairs::Stairs() 
{

}

Stairs::Stairs(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int actualLevel, int nextLevel)
{
    _sprite = new Sprite(texture,sf::IntRect(96,0,32,32),sf::Vector2f(16.0f,16.0f),sf::Vector2f(400.0f,400.0f),sf::Vector2f(1.0f,1.0f));  
    _sprite = new Sprite(texture,sf::IntRect(96,0,32,32),sf::Vector2f(16.0f,16.0f),
            sf::Vector2f(initialPosX,initialPosY),sf::Vector2f(1.0f,1.0f));
    _actualLevel=actualLevel;
    _nextLevel = nextLevel;
    
    
    
}
    
int Stairs::getActualLevel()
{
    return _actualLevel;
}
int Stairs::getNextLevel()
{
    return _nextLevel;
}
bool Stairs::getTouchedByPlayer()
{
    return _touchedByPlayer;
}
void Stairs::collision()
{
    //por si hay consecuencias de colisionar con una escalera.
}
Stairs::Stairs(const Stairs& orig) 
{
    
}

Stairs::~Stairs() 
{
 //llama al destructor de su padre   
}

