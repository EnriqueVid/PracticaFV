/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyStand.h
 * Author: newman
 *
 * Created on 26 de abril de 2018, 23:02
 */

#ifndef ENEMYSTAND_H
#define ENEMYSTAND_H
#include "Enemy.h"

using namespace std;

class EnemyStand : public Enemy{
public:
    EnemyStand(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern);
    EnemyStand(const EnemyStand& orig);
    virtual ~EnemyStand();
    
private:
    Sprite* _cone;
    string _pattern;

};

#endif /* ENEMYSTAND_H */

