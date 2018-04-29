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
    int switchType) : Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture)
{
    _switchType = switchType;
    _door1=NULL; //esto es MUY importante.
    _door2=NULL;
    _sprite = new Sprite(texture,sf::IntRect(32,0,32,32),sf::Vector2f(16.0f,16.0f),sf::Vector2f(400.0f,400.0f),sf::Vector2f(1.0f,1.0f));  
    _sprite->setSpritePosition(sf::Vector2f(initialPosX,initialPosY));
}

void Switch::activate()
{
    std::cout <<"Activando interruptor" <<endl;
    _pressed=true;
    if(_switchType==1){
        if(_door1!=NULL&&_door2!=NULL){
            std::cout <<"Se abriria la puerta de este interruptor."<<endl;
            _door1->open();
            _door2->open();
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
 
void Switch::update(){
    //update (animations?)
    //cout << _sprite->getSpritePosition().x << ","<<_sprite->getSpritePosition().y<<endl;
}


void Switch::setDoor(Door* door1, Door* door2)
{
    
    std::cout <<"Seteando puerta para el interruptor."<<endl;
    
    if(_door1!=NULL){
            std::cout <<"Eliminando anterior puerta."<<endl;
        delete _door1;
        _door1=NULL;   
    }
    if(_door2!=NULL){
            std::cout <<"Eliminando anterior puerta."<<endl;
        delete _door2;
        _door2=NULL;   
    }
    std::cout <<"Puerta asignada al interruptor."<<endl;
    _door1 = door1;
    _door2 = door2;
}
    
Door* Switch::getDoor1()
{
    if(_door1!=NULL){
            std::cout <<"Devuelta la puerta 1 del interruptor"<<endl;
        return _door1;        
    }
    else{
            std::cout <<"No hay puerta 1."<<endl;
    }
    
    return NULL;
}

Door* Switch::getDoor2()
{
    
    if(_door2!=NULL){
            std::cout <<"Devuelta la puerta 2 del interruptor"<<endl;
        return _door2;        
    }
    else{
            std::cout <<"No hay puerta 2."<<endl;
    }
    
    return NULL;
}


bool Switch::getPressed()
{
    return _pressed;
}

int Switch::getSwitchType()
{
    return _switchType;
}

Switch::Switch(const Switch& orig)
{
    
}

Switch::~Switch()
{  

    //MUY IMPORTANTE: LAS PUERTAS SE BORRAN EN EL SWITCH    
    /*
    delete _door;
    */
    delete _door1;
    _door1=NULL;
    delete _door2;
    _door2=NULL;
    
    //el destructor del padre se encarga de destruir el resto de punteros.
}

