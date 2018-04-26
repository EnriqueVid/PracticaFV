/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: newman
 *
 * Created on 25 de abril de 2018, 17:30
 */

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "Sprite.h"

using namespace std;

class Enemy {
    
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    
    void update();
    
private:
    
    
};

#endif /* ENEMY_H */

