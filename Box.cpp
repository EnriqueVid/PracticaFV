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

Box::Box(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
        int boxType, int vt, float speed) : 
Object(objectType,  initialPosX,  initialPosY,  initialAngle,  canBeMoved, texture) {
    _vt = vt;
    _speed=speed;
    _clock=NULL;
    
    _boxType = boxType;
    _breakAnimation=false;
    _breakAnimationFrame=0;
    _clock = new Clock();
}

void Box::interact(){
    //interactuacion con la caja
    if(_breakAnimation==false){
        //solo interactuamos si no se esta rompiendo
        std::cout << "Puedo interactuar con la caja" <<std::endl;
    }
    else{
        std::cout << "No puedo interactuar" <<std::endl;
    }
}
    
void Box::breakBox(){
            std::cout << "Rompiendo la caja" <<std::endl;
    if(_breakAnimation==false){
             std::cout << "Se rompe. Ponieno a true breakanimation." <<std::endl;
        _breakAnimation=true;
        _clock->clockRestart();        
    }
    else{
                std::cout << "No puedo romper la caja porque ya se esta rompiendo." <<std::endl;
    }
}
    
void Box::impact(){
     std::cout << "Intentando Impacto a la caja" <<std::endl;
    if(_breakAnimation==false){
             std::cout << "Hay impacto." <<std::endl;
    _vt = _vt - 1;
        if(_vt<=0){
            std::cout << "0 de vida. llamando a romper." <<std::endl;
            breakBox();
        }
    }
    else{
        std::cout << "No puedo haber impacto porque se esta rompiendo." <<std::endl;
    }
}
    
void Box::update(){
    if(_breakAnimation==true){
        _ignoreCollisions=true;
        //avanzar los frames de la animacion acorde al reloj interno.
            //cuando la animacion haya acabado:
            if(_clock->getClockAsSeconds()>10.0){
                    std::cout << "La caja deberia borrarse" <<std::endl;
                _erase=true;            
            }
    }
    else{
        //realizar acciones normales de update.
    }
}
        
int Box::getVt(){
    return _vt;
}
    
int Box::getBoxType(){
    return _boxType;
}
    
float Box::getSpeed(){
    return _speed;
}
    
bool Box::getBreakAnimation(){
    return _breakAnimation;
}   

int Box::getBreakAnimationFrame(){
    return _breakAnimationFrame;
}
Clock* Box::getClock(){
    return _clock;
}

Box::Box(const Box& orig) {
    
}

Box::~Box() {
    std::cout <<"Llamando al destructor de Box" << std::endl;

    /*
    delete _clock; 
    _clock = NULL;*/
    
    //se llama automaticamente al destructor de objeto (padre).
}