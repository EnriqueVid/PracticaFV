/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PowerUp.cpp
 * Author: carlos
 * 
 * Created on 22 de abril de 2018, 20:40
 */

#include "PowerUp.h"
#include "Player.h"

PowerUp::PowerUp() 
{
    
}

PowerUp::PowerUp(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int PowerUpType) : Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture)
{
    _powerUpType = PowerUpType;
    
    if(_powerUpType==1){ //ROJO
        _color=sf::Color::Red;
    }
    else if(_powerUpType==2){ //AZUL
        _color=sf::Color::Blue;        
    }
    else if(_powerUpType==3){ //VERDE
       _color=sf::Color::Green;
    }
    else{
        _color=sf::Color::White;
    }
}

void PowerUp::interact()
{
    //acciones que ocurren cuando se toca el objeto
    pickPowerUp();
}

void PowerUp::pickPowerUp()
{
    //condiciones para el jugador
    Player::Instance()->setColor(_color);
    _erase=true;
}

int PowerUp::getPowerUpType()
{
    return _powerUpType;
}

sf::Color PowerUp::getColor(){
    return _color;
}
    
PowerUp::PowerUp(const PowerUp& orig) 
{
}


PowerUp::~PowerUp() 
{
    //se llama al destructor de object
}

