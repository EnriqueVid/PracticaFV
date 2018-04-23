/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bullet.h
 * Author: carlos
 *
 * Created on 22 de abril de 2018, 22:04
 */

#ifndef BULLET_H
#define BULLET_H
#define PI 3.14159265359


#include "Texture.h"
#include "Clock.h"
#include "Situation.h"
#include "Sprite.h"
#include <math.h>
#include "RenderWindow.h"

class Bullet {
public:
    Bullet();
    
    Bullet(bool playerBullet,float posX, float posY, float angle, float vel, int damage, Texture *textura);
    
    Bullet(const Bullet& orig);
    
    void update(); //control del tiempo de la bala
    void render(RenderWindow* window, Clock* clock, float ups);
    void interpolate(float actualTime);
    
    void interact();
    
    void impact(); //impacto 
    
    float degreesToRadians(float degree);

    sf::Vector2i getDirection();
    bool getIsFromPlayer();
    int getDamage();
    bool getIgnoreCollisions();
    Sprite* getSprite();
    float getSpeed();
    bool getErase();
    Situation* getPreviousSituation();
    Situation* getActualSituation();
    Clock* getClock();
    
    void setDirection(sf::Vector2i direction);
    void newSituation(float x, float y, float g);
    void setPreviousSituation(float x, float y, float g);
    void setActualSituation(float x, float y, float g);
    
    virtual ~Bullet();
    
private:
    
    sf::Vector2i _direction;
    
    bool _isFromPlayer; //Indica si la bala es del jugador o enemiga.
    int _damage;
    bool _ignoreCollisions;
    
    Sprite* _sprite;
    float _speed;
    
    bool _erase;

    Situation* _previousSituation;
    Situation* _actualSituation;
    
    Clock* _clock;
};

#endif /* BULLET_H */

