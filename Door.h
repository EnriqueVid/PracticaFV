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
            int doorType, float maxTimeOpen);
    Door(const Door& orig);
    virtual ~Door();
    
    void open();
        
    void close();
    
    void update();
    
    void openDoorAnimation();
    void closeDoorAnimation();
        
    bool getOpen();
    int getDoorType();
    float getMaxTimeOpen();
    //Clock getClock();
    bool getOpenDoorAnimation();
    bool getCloseDoorAnimation();
    
private:
    
    bool _open;
    int _doorType;
    float _maxTimeOpen;
    Clock* _clock;
    
    bool _openAnimation; //false en el constructor
    bool _closeAnimation;
};

#endif /* DOOR_H */

