/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 23:00
 */

#ifndef BOX_H
#define BOX_H

#include "Situation.h"
#include "Object.h"

class Box : public Object{
public:
    
    Box();
    
    Box(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
            int vt, float speed);

    Box(const Box& orig);
    
    void interact();
    
    void romper();
    
    virtual ~Box();
    
private:
    int _vt;
    float _speed;
    
};

#endif /* BOX_H */

