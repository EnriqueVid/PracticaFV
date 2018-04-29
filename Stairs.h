/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stairs.h
 * Author: carlos
 *
 * Created on 30 de abril de 2018, 0:18
 */

#ifndef STAIRS_H
#define STAIRS_H

#include "Object.h"


class Stairs : public Object {
public:
    Stairs();
    
    Stairs(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int actualLevel, int nextLevel);
    
    int getActualLevel();
    int getNextLevel();
    
    bool getTouchedByPlayer();
        
    void collision();

    Stairs(const Stairs& orig);
        
    virtual ~Stairs();
private:
    
    
    int _actualLevel;
    int _nextLevel;
    bool _touchedByPlayer;
    
    
};

#endif /* STAIRS_H */

