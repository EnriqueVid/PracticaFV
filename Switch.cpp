/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 23:26
 */

#include "Switch.h"

Switch::Switch() {
    
}

Switch::Switch(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
    int switchType) : Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture){
    _switchType = switchType;
}

void Switch::activate(){
    _pressed=true;
    if(_switchType==1){
        if(_door!=NULL){
            _door->open();            
        }
    } 
}

void Switch::deactivate(){
    _pressed=false;
}
    
void Switch::setDoor(Door* door){
    
    if(_door!=NULL){
        delete _door;
    }
    
    _door = door;
}
    
Door* Switch::getDoor(){
    
    if(_door!=NULL){
        return _door;        
    }
    return NULL;
}

bool Switch::getPressed(){
    return _pressed;
}

int Switch::getSwitchType(){
    return _switchType;
}

Switch::Switch(const Switch& orig) {
    
}

Switch::~Switch() {
    delete _actualSituation;
    delete _previousSituation;
    delete _sprite;
    
    delete _door;
}

