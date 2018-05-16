/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hud.h
 * Author: tuba
 *
 * Created on 28 de abril de 2018, 15:40
 */

#ifndef HUD_H
#define HUD_H

#include "Player.h"
#include <iostream>

class Hud {
public:
    static Hud* Instance();
    
    void update(float life, float stamina, int r, int g, int b, int a);
    void setSprites(Texture* texture);
    void setPosition();
    
    Sprite* getLife();
    Sprite* getRectangle();
    Sprite* getStamina();
    
protected:
    Hud();
    Hud(const Hud& orig);
    virtual ~Hud();
    
private:
    
    static Hud* _pinstance;
    
    Sprite* _life;
    Sprite* _rectangle;
    Sprite* _stamina;
};

#endif /* HUD_H */

