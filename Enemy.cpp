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

Enemy::Enemy(Texture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale) 
{
    
    _previousSituation = new Situation();
    _actualSituation = new Situation();
    
    sf::IntRect* animation = getAnimation(0);
    
    _sprite = new Sprite(tex, box, origin, position, scale, _animationNumFrames, _animationTime);
    
    animation = NULL;
    
    _speed = 0;
    _axis.x = 0;
    _axis.y = 0;
    _direction.x = 0;
    _direction.y = 0;
    _damage = 0;
}

Enemy::Enemy(const Enemy& orig) 
{
}

Enemy::~Enemy() 
{
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

