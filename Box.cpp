/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 23:00
 */

#include "Box.h"
#include "Object.h"

Box::Box() {
}

Box::Box(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture* texture, int vt, float speed) : 
Object(objectType,  initialPosX,  initialPosY,  initialAngle,  canBeMoved, texture) {
    _vt = vt;
    _speed=speed;
}

Box::Box(const Box& orig) {
    
}

Box::~Box() {
    delete _actualSituation;
    delete _previousSituation;
    delete _sprite;
    
    _actualSituation=NULL;
    _previousSituation=NULL;
    _sprite=NULL;
}