/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 23:26
 */

#include "Door.h"
#include "Object.h"


Door::Door() 
{
}

Door::Door(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, int doorType, float maxTimeOpen) : 
Object(objectType,  initialPosX,  initialPosY,  initialAngle,  canBeMoved, texture){
    _doorType = doorType;
    _maxTimeOpen = maxTimeOpen;
    _open = false;
    _openAnimation =false;
    _closeAnimation = false;
    _clock = new Clock();
}

Door::Door(const Door& orig) 
{
    
}

//Open solo se ejecuta cuando la puerta esta cerrada y se abre.
void Door::open()
{
    1+1;
    
    if(_clock==NULL){
        std::cout <<"Clock no esta alojado en la memoria"<<endl;
    }
    else{
        std::cout <<"Clock si esta alojado en la memoria"<<endl;        
    }
    
    _clock->clockRestart();
    _open = true;
    _openAnimation=true; //inicia una animacion para abrirse.
    _closeAnimation=false;
    
    std::cout <<"LA PUERTA SE ESTA ABRIENDO. OJO."<<endl;
}
        
void Door::close()
{
    _open = false;
    _closeAnimation=true;
    _openAnimation=false;
    
    std::cout <<"LA PUERTA SE ESTA CERRANDO. OJO."<<endl;
}
    
void Door::update()
{
    if(_open==true){
        if (_clock->getClockAsSeconds() > _maxTimeOpen){
        close();
        }
    }
    //Bucle de animaciones de la puerta (abrirse y cerrarse)
    if(_openAnimation){
        openDoorAnimation();
    }
    if(_closeAnimation){
        closeDoorAnimation();
    }
}

void Door::openDoorAnimation()
{
    //cuando termina la animacion{
    _openAnimation=false;
    //}
    std::cout <<"Animacion open door" <<endl;
}

void Door::closeDoorAnimation()
{
    //cuando termina la animacion{
    _closeAnimation=false;
    //}
    std::cout <<"Animacion close door" <<endl;
}

bool Door::getOpen()
{
    return _open;
}

int Door::getDoorType()
{
    return _doorType;
}
    
float Door::getMaxTimeOpen(){
    return _maxTimeOpen;
}

bool Door::getOpenDoorAnimation(){
    return _openAnimation;
}

bool Door::getCloseDoorAnimation(){
    return _closeAnimation;
}

//Clock* getClock()

Door::~Door() 
{
    delete _actualSituation;
    delete _previousSituation;
    delete _sprite;
    delete _clock;
    
    _actualSituation=NULL;
    _previousSituation=NULL;
    _sprite=NULL;
    _clock=NULL;
    
}

