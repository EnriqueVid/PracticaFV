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


class Player {
public:
    static Player* Instance();
    
    void input();
    void update();
    void render(RenderWindow* window, Clock* clock, float ups);
    void interpolate(float actualTime);
    void keyReleased();
    void superSpeed();
    float degreesToRadians(float degree);
    void move();
    
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
    
    int _animationNumFrames; //indica el numero de frames de la animacion
    float _animationTime; //indica el tiempo que pasa hasta el siguiente frame
    
    sf::Vector2i _axis;
    sf::Vector2i _direction;
    
    bool _idleAnimationStart;
    bool _movingAnimationStart;
    bool _damage;
    int _actualAnimation;
    
    bool _hability;
    Clock* _clock; //si el reloj es distinto de NULL, el personaje estara en supervelocidad.
};

#endif /* PLAYER_H */

