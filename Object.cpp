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

Object::Object() 
{
    
}
Object::Object(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture* texture)
{
    //cout <<"Ejecutando constructor de padre"<<endl;
    _objectType=objectType;
    _canBeMoved = canBeMoved;
    //formacion del sprite adecuado segun el tipo.ende
    
    _sprite = NULL;
    
    //hace falta modificar esto de forma acorde.
    _actualSituation = new Situation(initialPosX,initialPosY,initialAngle);
    _previousSituation = new Situation(initialPosX,initialPosY,initialAngle);
    _ignoreCollisions=false;
    
    _collisionPlayer=false;
    _collisionEnemy=false;
    _collisionBox=false;
    _collisionObject=false;
    
    _collisionEnemyLastUpdate=false;
    _erase=false;
    
    /*
    if(_objectType==1){
        _sprite = new Sprite(texture,sf::IntRect(0,0,64,64));
    }*/
    
}
//estos metodo se heredara y hara algo distinto para cada uno de los hijos
void Object::interact()
{
    //std::cout <<"This should not happen. ERROR: IS Calling the father object interact." <<endl;
}

void Object::update()
{
    //std::cout <<"This should not happen. ERROR: IS Calling the father object update." <<endl;    
}


bool Object::getCollisionPlayer()
{
    return _collisionPlayer;
}
bool Object::getCollisionEnemy()
{
    return _collisionEnemy;
}
bool Object::getCollisionBox()
{
    return _collisionBox;
}
bool Object::getCollisionObject()
{
    return _collisionObject;
}

void Object::setCollisionPlayer(bool b)
{
    _collisionPlayer=b;
}
void Object::setCollisionEnemy(bool b)
{
    _collisionEnemy=b;
}
void Object::setCollisionBox(bool b)
{
    _collisionBox=b;
}
void Object::setCollisionObject(bool b)
{
    _collisionObject=b;
}


Sprite* Object::getSprite()
{
    return _sprite;
}
bool Object::getCanBeMoved()
{
    return _canBeMoved;
}
int Object::getObjectType()
{
    return _objectType;
}
void Object::newSituation(float x, float y, float g)
{
    _previousSituation->setPosition(_actualSituation->getPosition().x, _actualSituation->getPosition().y);
    _previousSituation->setAngle(_actualSituation->getAngle());
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Object::setActualSituation(float x, float y, float g)
{
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Object::setPreviousSituation(float x, float y, float g)
{
    _previousSituation->setPosition(x,y);
    _previousSituation->setAngle(g);
} 
Situation* Object::getActualSituation()
{
    return _actualSituation;
}
Situation* Object::getPreviousSituation()
{
    return _previousSituation;
}
bool Object::getIgnoreCollisions(){
    return _ignoreCollisions;
}

bool Object::getCollisionEnemyLastUpdate()
{
    return _collisionEnemyLastUpdate;
}

bool Object::getErase(){
    return _erase;
}

void Object::render(RenderWindow* window, Clock* clock, float ups)
{
    //cout <<"Renderizando objeto"<<endl;
    float actualTime = clock->getClockAsSeconds() / ups;
    interpolate(actualTime);
    window->windowDraw(_sprite);
}

void Object::interpolate(float actualTime)
{
    
    float x, y, g;

    x = (((actualTime-0)*(_actualSituation->getPosition().x - _previousSituation->getPosition().x))/(1-0)) + _previousSituation->getPosition().x;
    y = (((actualTime-0)*(_actualSituation->getPosition().y - _previousSituation->getPosition().y))/(1-0)) + _previousSituation->getPosition().y;
    g = (((actualTime-0)*(_actualSituation->getAngle() - _previousSituation->getAngle()))/(1-0)) + _previousSituation->getAngle();
    
    
    //cout <<"Interpolando a: " <<x<<" , "<<y<<" , "<<g<<" , "<<endl;
    
    _sprite->setSpritePosition(sf::Vector2f(x,y));
    _sprite->setSpriteRotation(g);
}

Object::Object(const Object& orig) 
{
    
}

//Ojo: Este metodo tambien se sobreescribe en los hijos. Puede haber problemas de gestion de memoria si no se tiene cuidado.
Object::~Object() 
{
    //std::cout <<"Deleting object" << std::endl;
    /*
    delete _actualSituation;
    _actualSituation=NULL;
    delete _previousSituation;
    _previousSituation=NULL;
    delete _sprite;
    _sprite=NULL;*/
    
}

