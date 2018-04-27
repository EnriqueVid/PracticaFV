/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 23:26
 */

#ifndef SWITCH_H
#define SWITCH_H
#include "Door.h"
#include "Texture.h"

class Switch : public Object {
public:
    Switch(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int switchType);
    Switch(const Switch& orig);
    virtual ~Switch();
    
    void activate();
    void deactivate();
    
    void setDoor(Door* door1, Door* door2);
    
    void update();
    
    Door* getDoor1();
    Door* getDoor2();
    bool getPressed();
    int getSwitchType();
    
private:
    int _switchType;
    bool _pressed;
    Door* _door1; //puerta de arriba / izquierda
    Door* _door2; //puerta de abajo / derecha
    
    //bool _pressedAnimation();
    //bool _unpressedAnimation();
    
};

#endif /* SWITCH_H */

