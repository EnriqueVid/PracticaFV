/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PowerUp.h
 * Author: carlos
 *
 * Created on 22 de abril de 2018, 20:40
 */

#ifndef POWERUP_H
#define POWERUP_H

#include "Object.h"

#include <SFML/Graphics/Color.hpp>


class PowerUp : public Object {
    
public:
    PowerUp();
    PowerUp(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int PowerUpType);

    void interact();
    void update();
    
    void pickPowerUp();
    int getPowerUpType();
    sf::Color getColor();
    
    PowerUp(const PowerUp& orig);
    virtual ~PowerUp();    
private:
    int _powerUpType; //1: ROJO . 2: AZUL . 3: VERDE...
    sf::Color _color;
    
    int _animationNumFrames; //indica el numero de frames de la animacion
    float _animationTime; //indica el tiempo que pasa hasta el siguiente frame    
    
};

#endif /* POWERUP_H */

