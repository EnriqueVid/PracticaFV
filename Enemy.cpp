/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.cpp
 * Author: newman
 * 
 * Created on 25 de abril de 2018, 17:30
 */

#include "Enemy.h"

Enemy::Enemy()
{
    
}

Enemy::Enemy(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale) 
{
    
    _previousSituation = new Situation();
    _actualSituation = new Situation();
    
    sf::IntRect* animation = getAnimation(0);
    
    _sprite = new Sprite(tex, animation, origin, position, scale, _animationNumFrames, _animationTime);
    _previousSituation->setPosition(position.x, position.y);
    _actualSituation->setPosition(position.x, position.y);
    
    animation = NULL;
    
    _speed = 0;
    _axis.x = 0;
    _axis.y = 0;
    _direction.x = 0;
    _direction.y = 0;
    _damage = 0;
    
    _collisionPlayer=false;
    _collisionObject=false;
}

Enemy::Enemy(const Enemy& orig) 
{
    if(_sprite != NULL)
    {
        delete _sprite;
        _sprite = NULL;
    }
    
    if(_previousSituation != NULL)
    {
        delete _previousSituation;
        _previousSituation = NULL;
    }
        
    if(_actualSituation != NULL)
    {
        delete _actualSituation;
        _actualSituation = NULL;
    } 
}

Enemy::~Enemy() 
{
    delete _sprite;
    delete _previousSituation;
    delete _actualSituation;
}

void Enemy::enemyMove(sf::Vector2f dir, float g)
{
    _actualSituation->setPosition(_actualSituation->getPositionX()+dir.x*_speed, _actualSituation->getPositionY()+dir.y*_speed);
    _actualSituation->setAngle(g);
    
    
}

sf::IntRect* Enemy::getAnimation(int animationNum)
{
    sf::IntRect* animation;
    
    switch(animationNum)
    {
        case 0:
            animation = new sf::IntRect[8];
            
            for(int i=0; i<8; i++)
            {
                animation[i] = sf::IntRect((0+32*i),0,32,32);
            }
            
            _animationNumFrames = 8;
            _animationTime = 0.01;
            return animation;
            break;
    }
    return animation;
}

void Enemy::setEnemyPreviousSituation(sf::Vector2f position, float deg)
{
    cout<<"Prev Situation: "<<_previousSituation->getPositionY()<<endl;
    cout<<"Actual Situation: "<<_actualSituation->getPositionY()<<endl;
    
    cout<<"asdasdasdsad"<<endl;
    
    _previousSituation->setPosition(position.x, position.y);
    _previousSituation->setAngle(deg);
}

void Enemy::setEnemyActualSituation(sf::Vector2f position, float deg)
{   
    
    
    _actualSituation->setPosition(position.x, position.y);
    _actualSituation->setAngle(deg);
}

void Enemy::setEnemySpeed(int speed)
{
    _speed = speed;
}

void Enemy::setEnemyDamage(float damage)
{
    _damage = damage;
}

void Enemy::setEnemyAnimationNumFrames(int num)
{
    _animationNumFrames = num;
}

void Enemy::setEnemyAnimationTime(float time)
{
    _animationTime = time;
}

void Enemy::setEnemyAxis(sf::Vector2i axis)
{
    _axis = axis;
}

void Enemy::setEnemyDirection(sf::Vector2i dir)
{
    _direction = dir;
}
    
Sprite* Enemy::getEnemySprite()
{
    return _sprite;
}

Situation* Enemy::getEnemyPreviousSituation()
{
    return _previousSituation;
}

Situation* Enemy::getEnemyActualSituation()
{
    return _actualSituation;
}

int Enemy::getEnemySpeed()
{
    return _speed;
}

float Enemy::getEnemyDamage()
{
    return _damage;
}

int Enemy::getEnemyAnimationNumFrames()
{
    return _animationNumFrames;
}

float Enemy::getEnemyAnimationTime()
{
    return _animationTime;
}

sf::Vector2i Enemy::getEnemyAxis()
{
    return _axis;
}

sf::Vector2i Enemy::getEnemyDirection()
{
    return _direction;
}

bool Enemy::getCollisionPlayer()
{
    return _collisionPlayer;
}

bool Enemy::getCollisionObject()
{
    return _collisionObject;
}
void Enemy::setCollisionPlayer(bool b)
{
    _collisionPlayer=b;
}
void Enemy::setCollisionObject(bool b)
{
    _collisionObject=b;
}
