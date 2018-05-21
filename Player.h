/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: tuba
 *
 * Created on 20 de abril de 2018, 22:55
 */

#ifndef PLAYER_H
#define PLAYER_H
#define PI 3.14159265359

#include "Sprite.h"
#include "Situation.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Clock.h"
#include "RenderWindow.h"
#include "SoundManager.h"


class Player {
public:
    static Player* Instance();
    
    void input();
    void update(int** _collisionMap);
    void render(RenderWindow* window, Clock* clock, float ups);
    void interpolate(float actualTime);
    void keyReleased();
    float degreesToRadians(float degree);
    void move();
    
    void superSpeed();
    void shoot();
    
    void setColor(sf::Color color);
    void setPlayer(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale);
    void setPosition(sf::Vector2f position);
    void setHealth(float health);
    void setStamina(float stamina);
    void setSpeed(int speed);
    void setAxis(sf::Vector2i axis);
    void setDirection(sf::Vector2i direction);
    void newSituation(float x, float y, float g);
    void setPreviousSituation(float x, float y, float g);
    void setActualSituation(float x, float y, float g);
    
    sf::IntRect* getAnimation(int animationNum);
    
    Sprite* getPlayer();
    sf::Color getColor();
    int getSpeed();
    float getHealth();
    float getStamina();
    bool getHability();
    Situation* getPreviousSituation();
    Situation* getActualSituation();
    
    sf::Vector2i getDirection();
    
    bool getFireBullet();
    
    void changePowerUp();
    
    void unlockPowerUp(int powerUpType);
    void lockPowerUp(int powerUpType);
    void unlockAllPowerUps();
    void lockAllPowerUps();
    
    void checkMapCollisions(int** _collisionMap);
    bool getCollisionWithMap();
    
    Clock* getClockDamage();
    float getClockDamageLag();    
    void setCollisionCone(bool b, int damage, float timeUntilNextHit);
    bool getCollisionCone();
    void setCollisionEnemy(bool b, int damage, float timeUntilNextHit);
    bool getCollisionEnemy();
    
    void checkDamage();
    void checkDamageAnimation();
    
    void forceDamageAnimation();
    
    bool getHidden();
    void checkHidden(int** _collisionMap);
    
    bool getPushedBack();
    void setPushedBack(bool b, sf::Vector2f pushedBackDistance);
    
    sf::Vector2i getAxis();
    void resetPlayer();
    
    void setRecoverStamina(bool b);
    bool getRecoverStamina();
    
protected:
    Player();
    Player(const Player& orig);
    virtual ~Player();
private:
    static Player* _pinstance;
    Sprite* _sprite;
    Situation* _previousSituation;
    Situation* _actualSituation;
    int _maxHealth;
    int _maxStamina;
    float _health;
    float _stamina;
    sf::Color _color;
    int _speed;
    int _defaultSpeed;
    
    int _animationNumFrames; //indica el numero de frames de la animacion
    float _animationTime; //indica el tiempo que pasa hasta el siguiente frame
    
    sf::Vector2i _axis;
    sf::Vector2i _direction;
    
    bool _idleAnimationStart;
    bool _movingAnimationStart;
    
    bool _damage;
    Clock* _clockDamageAnimation;
    bool _forceDamageAnimation; //obliga a la animacion a mostrarse aun cuando no se nos hace danyo.
    
    int _actualAnimation;
    
    bool _hability;
    bool _fireBullet; //le indica al mundo que debe crear una bala.
    Clock* _clockHability; //si el reloj es distinto de NULL, el personaje estara en supervelocidad.
    Clock* _clockChangeColor;
    
    bool _redUnlocked;
    bool _blueUnlocked;
    bool _greenUnlocked;
    
    bool _changePowerUp;
    
    bool _collisionWithMap;
    

    Clock* _clockDamage; //tiempo que debe pasar hasta volver a recibir danyo.
    float _clockDamageLag;
    
    bool _collisionCone;
    int _collisionConeDamage; //danyo que hara el siguiente golpe.

    bool _collisionEnemy; //danyo al chocar fisicamente con un enemigo.
    int _collisionEnemyDamage;
    
    bool _hidden;
    
    bool _pushedBack;
    sf::Vector2f _pushedBackDistance;
    
    bool _recoverStamina;

};

#endif /* PLAYER_H */

