/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyChase.h
 * Author: newman
 *
 * Created on 26 de abril de 2018, 23:02
 */

#ifndef ENEMYCHASE_H
#define ENEMYCHASE_H

#include "Enemy.h"

using namespace std;

class EnemyChase : public Enemy{
public:
    EnemyChase(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern);
    EnemyChase(const EnemyChase& orig);
    virtual ~EnemyChase();
    
private:
    Sprite* _cone;
    string _pattern;
    

};

#endif /* ENEMYCHASE_H */

