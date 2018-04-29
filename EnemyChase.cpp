/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyChase.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 23:02
 */

#include "EnemyChase.h"

EnemyChase::EnemyChase(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern, float loop): Enemy(tex, origin, position, scale) 
{
    _pattern = pattern;
    _cone = new Sprite(tex, sf::IntRect(160, 112, 96, 144), sf::Vector2f(48.0f,0.0f), position, scale);
    _actualStep = 0;
    _state = 0;
    setEnemySpeed(5);
    _loop = loop;
    _stopClock = NULL;
    _chaseClock = NULL;
    _loopClock = new Clock();
}

EnemyChase::EnemyChase(const EnemyChase& orig) {
}

EnemyChase::~EnemyChase() {
}

void EnemyChase::update(int** map)
{
    setEnemyPreviousSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle());
    
    if(_state == 0)
    {
        updateStateIdle(map);
    }
    else if(_state == 1)
    {
        updateStateChase();
    }
    else
    {
        updateStateStop();
    }
}

void EnemyChase::updateStateIdle(int** map)
{
    if(_actualStep >= _pattern.length()) _actualStep = 0;
    
    switch(_pattern.at(_actualStep))
    {
        case 'u':
            if(getEnemyActualSituation()->getAngle() < 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else if(getEnemyActualSituation()->getAngle() > 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else
            {
                if(map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 || map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
                {
                    enemyMove(sf::Vector2f(0.0f, -1.0f), 180.0f);
                    //cout<<"Me traslado"<<endl;
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
                }
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'd':
            if(getEnemyActualSituation()->getAngle() > 0 && getEnemyActualSituation()->getAngle() <= 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else if(getEnemyActualSituation()->getAngle() < 360 && getEnemyActualSituation()->getAngle() > 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
                
            }
            else
            {
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
                }
            }
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'l':
            if(getEnemyActualSituation()->getAngle() > 90 && getEnemyActualSituation()->getAngle() <= 270)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else if(getEnemyActualSituation()->getAngle() < 90 || getEnemyActualSituation()->getAngle() > 270)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else
            {
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
                }
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'r':
            if(getEnemyActualSituation()->getAngle() < 270 && getEnemyActualSituation()->getAngle() >= 90)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else if(getEnemyActualSituation()->getAngle() > 270 || getEnemyActualSituation()->getAngle() < 90)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else
            {
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
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        default:
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
    }
    if(getEnemyActualSituation()->getAngle() < 0) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() + 360);
    if(getEnemyActualSituation()->getAngle() > 360) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() - 360);
}

void EnemyChase::updateStateChase()
{
    // Aqui va el maravillosisimo codigo de A*
}

void EnemyChase::updateStateStop()
{
    if(_stopClock == NULL) _stopClock = new Clock();
    if(_stopClock != NULL && _stopClock->getClockAsSeconds() > 15)
    {
        _state = 0;
        delete _stopClock;
        _stopClock = NULL;
        _cone->setSpriteColor(255, 255, 255, 255);
        
    }
    else
    {
        _cone->setSpriteColor(255, 255, 255, 0);
    }
}

void EnemyChase::enemyChaseCollision()
{
    
}
    
void EnemyChase::setEnemyChasePattern(string pattern)
{
    _pattern = pattern;
}

void EnemyChase::setEnemyState(int s)
{
    _state = s;
}
    
string EnemyChase::getEnemyChasePattern()
{
    return _pattern;
}
    
Sprite* EnemyChase::getConeSprite()
{
    return _cone;
}


