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
    EnemyStand(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern, float loop);
    EnemyStand(const EnemyStand& orig);
    virtual ~EnemyStand();
    
    void update(sf::Vector2f playerPos);
    void updateStateIdle();
    void updateStateChase(sf::Vector2f playerPos);
    void updateStateStop();
    
    void setEnemyStandPattern(string pattern);
    void setEnemyState(int s);
    void enemyStandCollision();
    
    string getEnemyStandPattern();
    Sprite* getConeSprite();
    
    bool getCollisionPlayerCone();
    void setCollisionPlayerCone(bool b);
    
    bool getCollisionBullet();
    void setCollisionBullet(bool b);    
    
private:
    Sprite* _cone;
    string _pattern;
    int _actualStep;
    int _state;
    float _loop;
    Clock* _chaseClock;
    Clock* _loopClock;
    Clock* _stopClock;
    
    bool _collisionPlayerCone;
    bool _collisionBullet;

};

#endif /* ENEMYSTAND_H */

