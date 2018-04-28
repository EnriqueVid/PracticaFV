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
}

EnemyBounce::EnemyBounce(const EnemyBounce& orig)
{}

EnemyBounce::~EnemyBounce() 
{}

void EnemyBounce::update()
{
    setEnemyPreviousSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle());
    
    if(_state == 0)
    {
        updateStateIdle();
    }
    else
    {
        updateStateStop();
    }
    
}

void EnemyBounce::updateStateIdle()
{
    if(_actualStep >= _pattern.length()) _actualStep = 0;
    
    switch(_pattern.at(_actualStep))
    {
        case 'u':
            enemyMove(sf::Vector2f(0.0f, -1.0f), 180.0f);
            
            break;
            
        case 'd':
            enemyMove(sf::Vector2f(0.0f, 1.0f), 0.0f);
            break;
            
        case 'l':
            enemyMove(sf::Vector2f(-1.0f, 0.0f), 90.0f);
            break;
            
        case 'r':
            enemyMove(sf::Vector2f(1.0f, 0.0f), 270.0f);
            break;
    }
}
    
void EnemyBounce::updateStateStop()
{
    
}


void EnemyBounce::setEnemyBouncePattern(string pattern)
{
    _pattern = pattern;
}
    
string EnemyBounce::getEnemyBouncePattern()
{
    return _pattern;
}

