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

Door::Door(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, int doorType, float maxTimeOpen, float doorSpeed) : 
Object(objectType,  initialPosX,  initialPosY,  initialAngle,  canBeMoved, texture){
    _doorType = doorType;
    _maxTimeOpen = maxTimeOpen;
    _open = false;
    _close=true;
    
    _opening =false;
    _closing = false;
        
    _clock = new Clock();
    
    _speed = doorSpeed;
    
    /*
DoorType:

PUERTAS VERTICALES
0 - Parte superior de la puerta
1 - Parte inferior de la puerta

PUERTAS HORIZONTALES
2 - Parte izquierda de una puerta
3 - Parte derecha de una puerta
     */
    
    if(doorType==0)
    {
        _sprite = new Sprite(texture,sf::IntRect(64,0,64+32,32),sf::Vector2f(32.0f,32.0f),sf::Vector2f(340.0f,340.0f),sf::Vector2f(1.0f,1.0f));
        _initialPosition=initialPosY;
        _maxPosition=initialPosY-32;
    }
    else if(doorType==1)
    {
        _sprite = new Sprite(texture,sf::IntRect(64,32,64,64),sf::Vector2f(32.0f,32.0f),sf::Vector2f(340.0f,340.0f),sf::Vector2f(1.0f,1.0f));    
        _initialPosition=initialPosY;
        _maxPosition=initialPosY+32;
    }
    else
    {
        _sprite=NULL;
        _initialPosition=-1;
        _maxPosition=-1;
    }
}

Door::Door(const Door& orig) 
{
    
}

//Open solo se ejecuta cuando la puerta esta cerrada y se abre.
void Door::open()
{
    _clock->clockRestart();
    _opening=true; 
    _closing=false;
    _open = false;
    _close=false;
    std::cout <<"LA PUERTA SE ESTA ABRIENDO. OJO."<<endl;
}
        
void Door::close()
{
    _open = false;
    _close=false;
    _closing=true;
    _opening=false;
    std::cout <<"LA PUERTA SE ESTA CERRANDO. OJO."<<endl;
}
    
void Door::update()
{
        
    newSituation(_actualSituation->getPositionX(),_actualSituation->getPositionY(),_actualSituation->getAngle());
    
    _sprite->setSpritePosition(_actualSituation->getPosition());
    _sprite->setSpriteRotation(_actualSituation->getAngle());
    
    if(!_close&&!_closing)
    {
        if (_clock->getClockAsSeconds() > _maxTimeOpen)
        {
            close();
        }
    }
    else
    {
        _clock->clockRestart();
    }
    
    
    if(_opening||_closing){
        if(!_collisionPlayer&&!_collisionObject){
            if(_opening)
            {
                cout <<"Abriendo"<<endl;
                if(checkMaxPositionOpening())
                {

                    cout <<"MAXIMA POSICION ALCANZADA"<<endl;

                    _open=true;
                    _opening=false;

                    _closing=false;
                    _close=false;

                }
                else
                {
                    move();
                }
            }

            else if(_closing)
            {
                cout <<"Cerrando"<<endl;
                if(checkMaxPositionClosing()){
                    cout <<"MAXIMA POSICION CLOSING ALCANZADA"<<endl;

                    fixPositionClosing();
                    _close=true;
                    _closing=false;

                    _opening=false;
                    _open=false;
                }
                else
                {
                    move();
                }
            }
        }
        else{

            open();
            move();

            _collisionPlayer=false;
            _collisionObject=false;
        }
    }
}

void Door::move(){
    if(_opening){
        if(_doorType==0){
            setActualSituation(_actualSituation->getPositionX(),_actualSituation->getPositionY()-_speed,_actualSituation->getAngle());
        }
        else if(_doorType==1){
            setActualSituation(_actualSituation->getPositionX(),_actualSituation->getPositionY()+_speed,_actualSituation->getAngle());            
        }
    }
    else if(_closing){
        if(_doorType==0){
            setActualSituation(_actualSituation->getPositionX(),_actualSituation->getPositionY()+_speed,_actualSituation->getAngle());            
        }
        else if(_doorType==1){
            setActualSituation(_actualSituation->getPositionX(),_actualSituation->getPositionY()-_speed,_actualSituation->getAngle());            
        }        
    }
}

bool Door::checkMaxPositionOpening()
{
    if(_doorType==0){
        if(_actualSituation->getPositionY()<=_maxPosition){
            return true;
        }
    }
    else if(_doorType==1){
        if(_actualSituation->getPositionY()>=_maxPosition){
            return true;
        }
    }
    return false;
}

bool Door::checkMaxPositionClosing()
{
    if(_doorType==0){
        if(_actualSituation->getPositionY()>=_initialPosition){
            return true;
        }
    }
    else if(_doorType==1){
        if(_actualSituation->getPositionY()<=_initialPosition){
            return true;
        }
    }
    return false;
}

void Door::fixPositionClosing(){
    if(_doorType==0||_doorType==1){
        setActualSituation(_actualSituation->getPositionX(), _initialPosition, _actualSituation->getAngle());
    }
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

bool Door::getOpening(){
    return _opening;
}

bool Door::getClosing(){
    return _closing;
}

Clock* Door::getClock(){
    return _clock;
}

//es importante eliminar puerta por separado, debido a que eliminar el boton de una puerta
//no elimina directamente a la puerta.
Door::~Door() 
{
    delete _clock;
    _clock=NULL;
    //el destructor del padre se encarga de destruir el resto de punteros.
}

