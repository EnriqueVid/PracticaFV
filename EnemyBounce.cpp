/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyBounce.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 20:30
 */

#include "EnemyBounce.h"


EnemyBounce::EnemyBounce(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern): Enemy(tex, origin, position, scale) 
{
    _pattern = pattern;
    _actualStep = 0;
    _state = 0;
    setEnemySpeed(5);
    _stopClock = NULL;
    
    _collisionBullet=false;
}

EnemyBounce::EnemyBounce(const EnemyBounce& orig)
{}

EnemyBounce::~EnemyBounce() 
{
    //se llama al destructor de padre

    if(_stopClock!=NULL)
    {
        delete _stopClock;
        _stopClock=NULL;
    }


}

void EnemyBounce::update(int** map)
{
    
    setEnemyAxis(sf::Vector2i(getEnemyDirection().x,getEnemyDirection().y));
    setEnemyDirection(sf::Vector2i(0,0));
    
    if(getCollisionPlayer()||getCollisionObject())
    {
        enemyBounceCollision();
    }
    
    setEnemyPreviousSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle());
    
    if(_collisionBullet)
    {
        _state = 1;
    }
    
    if(_state == 0)
    {
        updateStateIdle(map);
    }
    else
    {
        updateStateStop();
    }
    
    setCollisionPlayer(false);
    setCollisionObject(false);
    
    _collisionBullet=false;
    
}

void EnemyBounce::updateStateIdle(int** map)
{
    if(_actualStep >= _pattern.length()) _actualStep = 0;
    
    switch(_pattern.at(_actualStep))
    {
        case 'u':
            
            setEnemyAxis(sf::Vector2i(0,-1));
            setEnemyDirection(sf::Vector2i(0,-1));
            
            if(map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
            {
                enemyMove(sf::Vector2f(0.0f, -1.0f), 180.0f);
            }
            else
            {
                sf::Vector2f aux;
                while(map[int(getEnemyActualSituation()->getPosition().y-17)/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-17)/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
                {
                    aux.x = getEnemyActualSituation()->getPosition().x;
                    aux.y = getEnemyActualSituation()->getPosition().y-1;
                    setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                }
                _actualStep++;
            }
            break;
            
        case 'd':
            
            setEnemyAxis(sf::Vector2i(0,1));
            setEnemyDirection(sf::Vector2i(0,1));
            
            if(map[int(getEnemyActualSituation()->getPosition().y+16+getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y+16+getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
            {
                enemyMove(sf::Vector2f(0.0f, 1.0f), 0.0f);
            }
            else
            {
                sf::Vector2f aux;
                while(map[int(getEnemyActualSituation()->getPosition().y+17)/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y+17)/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
                {
                    aux.x = getEnemyActualSituation()->getPosition().x;
                    aux.y = getEnemyActualSituation()->getPosition().y+1;
                    setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                }
                _actualStep++;
            }
            break;
            
        case 'l':
            
            setEnemyAxis(sf::Vector2i(-1,0));
            setEnemyDirection(sf::Vector2i(-1,0));
            
            if(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x-16-getEnemySpeed())/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x-16-getEnemySpeed())/32] != 2)
            {
                enemyMove(sf::Vector2f(-1.0f, 0.0f), 90.0f);
            }
            else
            {
                sf::Vector2f aux;
                while(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x-17)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x-17)/32] != 2)
                {
                    aux.x = getEnemyActualSituation()->getPosition().x-1;
                    aux.y = getEnemyActualSituation()->getPosition().y;
                    setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                }
                _actualStep++;
            }
            break;
            
        case 'r':
            
            setEnemyAxis(sf::Vector2i(1,0));
            setEnemyDirection(sf::Vector2i(1,0));
            
            if(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x+16+getEnemySpeed())/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x+16+getEnemySpeed())/32] != 2)
            {
                enemyMove(sf::Vector2f(1.0f, 0.0f), 270.0f);
            }
            else
            {
                sf::Vector2f aux;
                while(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x+17)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x+17)/32] != 2)
                {
                    aux.x = getEnemyActualSituation()->getPosition().x+1;
                    aux.y = getEnemyActualSituation()->getPosition().y;
                    setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                }
                _actualStep++;
            }
            break;
    }
}
    
void EnemyBounce::updateStateStop()
{
    if(_stopClock == NULL) _stopClock = new Clock();
    if(_stopClock != NULL && _stopClock->getClockAsSeconds() > 4.5)
    {
        _state = 0;
        delete _stopClock;
        _stopClock = NULL;
    }
}

void EnemyBounce::enemyBounceCollision()
{
    
    _actualStep++;
    
}

void EnemyBounce::setEnemyState(int s)// s=0 ==> Idle; s=1 ==> Paralizado;
{
    _state = s;
}

void EnemyBounce::setEnemyBouncePattern(string pattern)
{
    _pattern = pattern;
}
    
string EnemyBounce::getEnemyBouncePattern()
{
    return _pattern;
}

bool EnemyBounce::getCollisionBullet()
{
    return _collisionBullet;
}

void EnemyBounce::setCollisionBullet(bool b)
{
    _collisionBullet=b;
}

