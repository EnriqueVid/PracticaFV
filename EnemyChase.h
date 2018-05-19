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
    EnemyChase(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern, float loop);
    EnemyChase(const EnemyChase& orig);
    virtual ~EnemyChase();
    
    void update(int** map, int width, int height);
    void updateStateIdle(int** map);
    void updateStateChase(int** map, int width, int height);
    void updateStateStop();
    
    void setEnemyChasePattern(string pattern);
    void setEnemyState(int s);
    void enemyChaseCollision();
    
    string getEnemyChasePattern();
    
    Sprite* getConeSprite();
    
private:
    Sprite* _cone;
    string _pattern;
    int _actualStep;
    int _state;
    int _counter;
    int _actualAstar;
    float _loop;
    Clock* _chaseClock;
    Clock* _loopClock;
    Clock* _stopClock;
    sf::Vector2i* _path;
    int _pathDim;
    int _pathPos;
    

};

#endif /* ENEMYCHASE_H */

