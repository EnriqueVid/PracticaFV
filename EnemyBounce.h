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
    EnemyBounce(Texture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern);
    EnemyBounce(const EnemyBounce& orig);
    virtual ~EnemyBounce();
    
    void update();
    void updateStateIdle();
    void updateStateStop();
    
    void setEnemyBouncePattern(string pattern);
    void setEnemyState(int s);
    
    string getEnemyBouncePattern();
    
private:
    string _pattern;
    int _actualStep;
    int _state;

};

#endif /* ENEMYBOUNCE_H */

