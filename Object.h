/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 10:22
 */

#ifndef OBJECT_H
#define OBJECT_H
#include "Sprite.h"
#include "Situation.h"
#include "Texture.h"

class Object {
public:
    Object();
    Object(const Object& orig);
    Object(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture);

    void interact();
    
    void newSituation(float, float, float);
    void setActualSituation(float, float, float);
    void setPreviousSituation(float, float, float);
    
    Sprite* getSprite();
    int getObjectType();
    bool getCanBeMoved();
    Situation* getActualSituation();
    Situation* getPreviousSituation();
    
    void update();
    
    virtual ~Object();
    
protected:
    Sprite* _sprite;
    Situation* _actualSituation;
    Situation* _previousSituation;
    bool _canBeMoved;
    int _objectType;
};

#endif /* OBJECT_H */