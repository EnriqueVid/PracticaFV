/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyBounce.h
 * Author: newman
 *
 * Created on 26 de abril de 2018, 20:30
 */

#ifndef ENEMYBOUNCE_H
#define ENEMYBOUNCE_H
#define PI 3.14159265359

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <string.h>
#include "RenderWindow.h"
#include "Enemy.h"

using namespace std;

class EnemyBounce : public Enemy{
    
public:
    EnemyBounce(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern);
    EnemyBounce(const EnemyBounce& orig);
    virtual ~EnemyBounce();
    
    void update(int** map);
    void updateStateIdle(int** map);
    void updateStateStop();
    
    void setEnemyBouncePattern(string pattern);
    void setEnemyState(int s);
    void enemyBounceCollision();
    
    string getEnemyBouncePattern();

    bool getCollisionBullet();
    void setCollisionBullet(bool b);    
    
private:
    string _pattern;
    int _actualStep;
    int _state;
    Clock* _stopClock;
    
    bool _collisionBullet;

};

#endif /* ENEMYBOUNCE_H */

