/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: newman
 *
 * Created on 25 de abril de 2018, 17:30
 */

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Situation.h"
#include <string.h>


using namespace std;

class Enemy {
    
public:
    Enemy();
    Enemy(Texture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    
    sf::IntRect* getAnimation(int animationNum);
    
    void enemyUpdate();
    void enemyMove(sf::Vector2f dir, float g);
    
    void setEnemyPreviousSituation(sf::Vector2f position, float deg);
    void setEnemyActualSituation(sf::Vector2f position, float deg);
    void setEnemySpeed(int speed);
    void setEnemyDamage(float damage);
    void setEnemyAnimationNumFrames(int num);
    void setEnemyAnimationTime(float time);
    void setEnemyAxis(sf::Vector2i axis);
    void setEnemyDirection(sf::Vector2i dir);
    
    Sprite* getEnemySprite();
    Situation* getEnemyPreviousSituation();
    Situation* getEnemyActualSituation();
    int getEnemySpeed();
    float getEnemyDamage();
    int getEnemyAnimationNumFrames();
    float getEnemyAnimationTime();
    sf::Vector2i getEnemyAxis();
    sf::Vector2i getEnemyDirection();
    
private:
    Sprite* _sprite;
    Situation* _previousSituation;
    Situation* _actualSituation;
    
    int _speed;
    float _damage;
    
    int _animationNumFrames; //indica el numero de frames de la animacionTexture* tex, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale
    float _animationTime; //indica el tiempo que pasa hasta el siguiente frame
    
    sf::Vector2i _axis;
    sf::Vector2i _direction;
    
};

#endif /* ENEMY_H */

