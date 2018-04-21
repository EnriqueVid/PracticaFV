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

Switch::Switch(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
    int switchType) : Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture){
    
    _switchType = switchType;
    _door=NULL; //esto es MUY importante.
}

void Switch::activate(){
    std::cout <<"Activando interruptor" <<endl;
    _pressed=true;
    if(_switchType==1){
        if(_door!=NULL){
            std::cout <<"Se abriria la puerta de este interruptor."<<endl;
            _door->open();            
        }
        else{
            std::cout <<"No tengo puerta."<<endl;            
        }
    } 
}

void Switch::deactivate(){
    std::cout <<"Desactivando interruptor"<<endl;
    _pressed=false;
}
    
void Switch::setDoor(Door* door){
    
    std::cout <<"Seteando puerta para el interruptor."<<endl;
    
    if(_door!=NULL){
            std::cout <<"Eliminando anterior puerta."<<endl;
        delete _door;
        _door=NULL;
    }
        std::cout <<"Puerta asignada al interruptor."<<endl;
    _door = door;
}
    
Door* Switch::getDoor(){
    
    if(_door!=NULL){
            std::cout <<"Devuelta la puerta del interruptor"<<endl;
        return _door;        
    }
    else{
            std::cout <<"No hay puerta."<<endl;
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
    //¡¡CUIDADO!! No eliminamos la puerta desde aqui porque si no, al hacer delete de puerta ocurrirá un 
    //segmentation fault. Debido a que la puerta la declaramos por separado y luego la asignamos si el
    //interruptor es un interruptor con puerta.
    
    //En resumen: Se debe eliminar la puerta por separado debido a que se crea por separado.
    
    /*
    delete _door;
    */
    _door=NULL;
    
    //el destructor del padre se encarga de destruir el resto de punteros.
}

