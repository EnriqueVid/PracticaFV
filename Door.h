/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 23:26
 */

#ifndef DOOR_H
#define DOOR_H
#include "Object.h"
#include "Clock.h"

class Door : public Object {
public:
    Door();
    Door(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int doorType, float maxTimeOpen,float doorSpeed);
    Door(const Door& orig);
    
    virtual ~Door();
    
    void open();
    void close();
    void update();
    
    bool checkMaxPositionOpening();
    bool checkMaxPositionClosing();
    void fixPositionClosing();
    
    void move();
        
    bool getOpen();
    int getDoorType();
    float getMaxTimeOpen();
    Clock* getClock();
    bool getOpening();
    bool getClosing();
    
private:
    bool _open;
    bool _close;
    int _doorType; //1: horizontal, 2: Vertical
    float _maxTimeOpen;
    Clock* _clock;
    
    bool _opening; 
    bool _closing;
    
    float _speed;
    
    float _initialPosition;
    float _maxPosition;
};

#endif /* DOOR_H */

