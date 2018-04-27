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
#include "Clock.h"

class Box : public Object{
public:
    
    Box();
    Box(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
            int boxType, int vt, float speed);

    Box(const Box& orig);
    
    void interact();
    void breakBox(); //cuando el jugador decide romper una caja.
    void impact(); //cuando recibe un disparo enemigo
    void update(); 
    
    int getVt();
    int getBoxType();
    float getSpeed();
    bool getBreakAnimation(); //si devuelve true, se esta ejecutando la animacion de romperse.
    int getBreakAnimationFrame();
    Clock* getClock();
    
    
    virtual ~Box();
    
private:
    
    int _boxType; //tipo de CAJA de la que se trata.
    int _vt; //maximo numero de balas enemigas que puede recibir antes de romperse.
    float _speed; //velocidad cuando se arrastre.
    
    //Animacion:
    bool _breakAnimation; //indica si se produce o no la animacion de romperse
    int _breakAnimationFrame; //indica el frame de la animacion por el que va
    Clock* _clock; //reloj de soporte para el avance de la animacion.
    
};

#endif /* BOX_H */

