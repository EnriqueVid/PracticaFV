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
#include "Player.h"
#include <math.h>

Bullet::Bullet() {
}

Bullet::Bullet(bool playerBullet, bool generatedFromMouse,float posX, float posY, float angle, float speed, 
        float maxDuration, int damage, Texture *texture)
{
    _actualSituation = new Situation(posX,posY,angle);
    _previousSituation = new Situation(posX,posY,angle);
    _clock = new Clock();
    
    _isFromPlayer = playerBullet; //Indica si la bala es del jugador o enemiga.
    _damage=damage;
    _speed=speed;
    _duration=maxDuration;
    
    if(generatedFromMouse)
    {
        _direction = sf::Vector2i(cos(degreesToRadians(angle)),sin(degreesToRadians(angle)));
        _direction.x = cos(degreesToRadians(angle));
        _direction.y = sin(degreesToRadians(angle));
    }
    else
    {
        _direction.x=Player::Instance()->getDirection().x;
        _direction.y=Player::Instance()->getDirection().y;
    }

    _ignoreCollisions=false;
    _erase=false;
    
     
    _sprite = new Sprite(texture,sf::IntRect(0,0,32,32),sf::Vector2f(16.0f,16.0f),sf::Vector2f(340.0f,340.0f),sf::Vector2f(1.0f,1.0f));

    _collisionWithMap=false;

    
    //creacion del sprite
    //_sprite = new Sprite(textura);
}

float Bullet::degreesToRadians(float degree)
{
    return ((degree*PI)/180);
}

void Bullet::update(int** _collisionMap)
{    

    checkMapCollisions(_collisionMap);
    
    
    if(_clock->getClockAsSeconds()>_duration||_collisionWithMap==true){
        _erase=true;
    }
    
    _sprite->spriteMove(sf::Vector2f(_speed*_direction.x , _speed*_direction.y));
    if(_previousSituation->getAngle()==320)_previousSituation->setAngle(320-360);
    
    _sprite->setSpriteRotation(_previousSituation->getAngle()+20);  
    
    
    newSituation(_sprite->getSpritePosition().x, _sprite->getSpritePosition().y, _sprite->getSpriteRotation());

    _collisionWithMap=false;

    //disparos->at(a)->getSprite()->setRotation(disparos->at(a)->getEstadoAnterior()->getGrados()+40); 
}

void Bullet::checkMapCollisions(int** _collisionMap)
{
    if(_direction.x>0)
    {
        if(_collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()+16)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()+16)/32] == 2)
        {
            _actualSituation->setPosition(_previousSituation->getPositionX(),_actualSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()+17)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()+17)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX()+1,_actualSituation->getPositionY());
            }
            _collisionWithMap=true;

        }
    }
    else if(_direction.x<0)
    {
        if(_collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()-16)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()-16)/32] == 2)
        {
            _actualSituation->setPosition(_previousSituation->getPositionX(),_actualSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()-17)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()-17)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX()-1,_actualSituation->getPositionY());
            }
            _collisionWithMap=true;
        }
    }
    
    if(_direction.y>0)
    {
        if(_collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()+16)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()+16)/32][int(_actualSituation->getPositionX()-16)/32] == 2)
        {
            _actualSituation->setPosition(_actualSituation->getPositionX(),_previousSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()+17)/32][int(_actualSituation->getPositionX()+16)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()+17)/32][int(_actualSituation->getPositionX()-16)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX(),_actualSituation->getPositionY()+1);
            }
            _collisionWithMap=true;
        }
    }
    else if(_direction.y<0)
    {
        if(_collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()+16)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-16)/32][int(_actualSituation->getPositionX()-16)/32] == 2)
        {
            _actualSituation->setPosition(_actualSituation->getPositionX(),_previousSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()-17)/32][int(_actualSituation->getPositionX()+16)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-17)/32][int(_actualSituation->getPositionX()-16)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX(),_actualSituation->getPositionY()-1);
            }
            _collisionWithMap=true;
        }
    }
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
    
    std::cout <<"Deleting bullet"<<endl;
    delete _clock;
    _clock=NULL;
    delete _sprite;
    _sprite=NULL;
    delete _previousSituation;
    _previousSituation=NULL;
    delete _actualSituation;
    _actualSituation=NULL;
}

