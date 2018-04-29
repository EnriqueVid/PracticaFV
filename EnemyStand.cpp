/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyStand.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 23:02
 */

#include "EnemyStand.h"

EnemyStand::EnemyStand(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern, float loop): Enemy(tex, origin, position, scale)
{
    _pattern = pattern;
    _cone = new Sprite(tex, sf::IntRect(160, 112, 96, 144), sf::Vector2f(48.0f,0.0f), position, scale);
    _actualStep = 0;
    _state = 2;
    setEnemySpeed(0);
    _loop = loop;
    _stopClock = NULL;
    _chaseClock = NULL;
    _loopClock = new Clock();
}

EnemyStand::EnemyStand(const EnemyStand& orig) 
{
    
}

EnemyStand::~EnemyStand() 
{
    
}

void EnemyStand::update(sf::Vector2f playerPos)
{
    setEnemyPreviousSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle());
    
    if(_state == 0)
    {
        updateStateIdle();
    }
    else if(_state == 1)
    {
        updateStateChase(playerPos);
    }
    else
    {
        updateStateStop();
    }
}

void EnemyStand::updateStateIdle()
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
                //cout<<getEnemyActualSituation()->getAngle()<<endl;
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
    
    
    //Probar una cosa
    //_cone->setSpritePosition(getEnemyActualSituation()->getPosition());
    //_cone->setSpriteRotation(getEnemyActualSituation()->getAngle());
}

void EnemyStand::updateStateChase(sf::Vector2f playerPos)
{
    if(_chaseClock == NULL) _chaseClock = new Clock;
    
    if(_chaseClock->getClockAsSeconds() <= 60.0f)
    {
        float plX, plY, eX, eY, catC, catO, hipo, rot;
        plX = playerPos.x;
        plY = playerPos.y;
        eX = getEnemyActualSituation()->getPositionX();
        eY = getEnemyActualSituation()->getPositionY();
        catC = eX-plX;
        catO = eY-plY;
        hipo = sqrt((catC*catC)+(catO*catO));
        rot = 0;
        
        //cout<<"catC: "<<catC<<endl;
        //cout<<"catO: "<<catO<<endl;
        //cout<<"hipo: "<<hipo<<endl;
        
        if(eY > plY)
        {
            rot =   (3.14159265359/2+acos(catC/hipo))*180/3.14159265359;
            //cout<<"rot = "<<rot<<endl;
            setEnemyActualSituation(getEnemyActualSituation()->getPosition(), rot);
        }
        else
        {
            rot =   (3.14159265359/2-acos(catC/hipo))*180/3.14159265359;
            //cout<<"rot = "<<rot<<endl;
            setEnemyActualSituation(getEnemyActualSituation()->getPosition(), rot);
        }
        
        if(getEnemyActualSituation()->getAngle() < 0) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() + 360);
        if(getEnemyActualSituation()->getAngle() > 360) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() - 360);
        
    }
    else
    {
        delete _chaseClock;
        _chaseClock = NULL;
        _state = 0;
        setEnemyActualSituation(getEnemyActualSituation()->getPosition(), int(getEnemyActualSituation()->getAngle())/5*5);
        //cout<<int(getEnemyActualSituation()->getAngle())<<endl;
    }
}

void EnemyStand::updateStateStop()
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

void EnemyStand::enemyStandCollision()
{
    //Carlos Acaba ya con las malditas colisiones
}

void EnemyStand::setEnemyStandPattern(string pattern)
{
    _pattern = pattern;
}

void EnemyStand::setEnemyState(int s)
{
    _state = s;
}

Sprite* EnemyStand::getConeSprite()
{
    return _cone;
}

