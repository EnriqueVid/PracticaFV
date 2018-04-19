/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 10:22
 */

#include "Object.h"

Object::Object() {
    
}

Object::Object(int objectType, bool canBeMoved, float initialPosX, float initialPosY, float initialAngle, Texture *texture){
    _objectType=objectType;
    _canBeMoved = canBeMoved;
    
    //formacion del sprite adecuado segun el tipo.
    _sprite = new Sprite();
    //hace falta modificar esto de forma acorde.
    
    
    _actualSituation = new Situation(initialPosX,initialPosY,initialAngle);
    _previousSituation = new Situation(initialPosX,initialPosY,initialAngle);
    
}
//estos metodo se heredara y hara algo distinto para cada uno de los hijos
void Object::interact(){
    std::cout <<"This should not happen. Calling the father object interact." <<endl;
}
Sprite* Object::getSprite(){
    return _sprite;
}
bool Object::getCanBeMoved(){
    return _canBeMoved;
}

int Object::getObjectType(){
    return _objectType;
}

void Object::newSituation(float x, float y, float g){
    _previousSituation->setPosition(_actualSituation->getPosition().x, _actualSituation->getPosition().y);
    _previousSituation->setAngle(_actualSituation->getAngle());
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Object::setActualSituation(float x, float y, float g){
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Object::setPreviousSituation(float x, float y, float g){
    _previousSituation->setPosition(x,y);
    _previousSituation->setAngle(g);
}
    
Situation* Object::getActualSituation(){
    return _actualSituation;
}
Situation* Object::getPreviousSituation(){
    return _previousSituation;
}
Object::Object(const Object& orig) {
    
}
Object::~Object() {
    delete _actualSituation;
    delete _previousSituation;
    delete _sprite;
}

