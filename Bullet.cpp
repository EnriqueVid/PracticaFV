/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bullet.cpp
 * Author: carlos
 * 
 * Created on 22 de abril de 2018, 22:04
 */

#include "Bullet.h"
#include <math.h>

Bullet::Bullet() {
}

Bullet::Bullet(bool playerBullet,float posX, float posY, float angle, float speed, int damage, Texture *textura)
{
    _actualSituation = new Situation(posX,posY,angle);
    _previousSituation = new Situation(posX,posY,angle);
    _clock = new Clock();
    
    _isFromPlayer = playerBullet; //Indica si la bala es del jugador o enemiga.
    _damage=damage;
    _speed=speed;
    
    _direction = sf::Vector2i(cos(degreesToRadians(angle)),sin(degreesToRadians(angle)));
    _direction.x = cos(degreesToRadians(angle));
    _direction.y = sin(degreesToRadians(angle));

    _ignoreCollisions=false;
    _erase=false;
    
    //creacion del sprite
    //_sprite = new Sprite(textura);
}

float Bullet::degreesToRadians(float degree)
{
    return ((degree*PI)/180);
}

void Bullet::update()
{    

    _sprite->spriteMove(sf::Vector2f(_speed*_direction.x , _speed*_direction.y));
    if(_previousSituation->getAngle()==320)_previousSituation->setAngle(320-360);
    
    _sprite->setSpriteRotation(_previousSituation->getAngle()+40);   
    newSituation(_sprite->getSpritePosition().x, _sprite->getSpritePosition().y, _sprite->getSpriteRotation());

    //disparos->at(a)->getSprite()->setRotation(disparos->at(a)->getEstadoAnterior()->getGrados()+40); 
}

void Bullet::render(RenderWindow* window, Clock* clock, float ups)
{
    float actualTime = clock->getClockAsSeconds() / ups;
    interpolate(actualTime);
    window->windowDraw(_sprite);
}

void Bullet::interpolate(float actualTime)
{
    float x, y, g;

    x = (((actualTime-0)*(_actualSituation->getPosition().x - _previousSituation->getPosition().x))/(1-0)) + _previousSituation->getPosition().x;
    y = (((actualTime-0)*(_actualSituation->getPosition().y - _previousSituation->getPosition().y))/(1-0)) + _previousSituation->getPosition().y;
    g = (((actualTime-0)*(_actualSituation->getAngle() - _previousSituation->getAngle()))/(1-0)) + _previousSituation->getAngle();
    
    _sprite->setSpritePosition(sf::Vector2f(x,y));
    _sprite->setSpriteRotation(g);
}

    
void Bullet::interact()
{
    //interactuacion cuando se choca con algo.
    impact();
}
    
void Bullet::impact()
{
    _erase=true;
}

void Bullet::setDirection(sf::Vector2i direction)
{
    _direction = direction;
}


void Bullet::newSituation(float x, float y, float g)
{
    _previousSituation->setPosition(_actualSituation->getPosition().x, _actualSituation->getPosition().y);
    _previousSituation->setAngle(_actualSituation->getAngle());
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}

void Bullet::setActualSituation(float x, float y, float g)
{
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Bullet::setPreviousSituation(float x, float y, float g)
{
    _previousSituation->setPosition(x,y);
    _previousSituation->setAngle(g);
} 

sf::Vector2i Bullet::getDirection()
{
    return _direction;
}
bool Bullet::getIsFromPlayer(){
    return _isFromPlayer;
}
int Bullet::getDamage()
{
    return _damage;
}
bool Bullet::getIgnoreCollisions()
{
    return _ignoreCollisions;
}
Sprite* Bullet::getSprite()
{
    return _sprite;
}
float Bullet::getSpeed()
{
    return _speed;
}
bool Bullet::getErase()
{
    return _erase;
}
Situation* Bullet::getPreviousSituation()
{
    return _previousSituation;
}
Situation* Bullet::getActualSituation()
{
    return _actualSituation;
}
Clock* Bullet::getClock()
{
    return _clock;
}
        

Bullet::Bullet(const Bullet& orig) 
{
    
}

Bullet::~Bullet() 
{
    delete _sprite;
    _sprite=NULL;
    delete _previousSituation;
    _previousSituation=NULL;
    delete _actualSituation;
    _actualSituation=NULL;
}

