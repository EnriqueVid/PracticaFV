/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PowerUp.cpp
 * Author: carlos
 * 
 * Created on 22 de abril de 2018, 20:40
 */

#include "PowerUp.h"
#include "Player.h"

PowerUp::PowerUp() 
{
    
}

PowerUp::PowerUp(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture,
            int PowerUpType) : Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture)
{
    _powerUpType = PowerUpType;

    _animationTime=0.1f;
    _animationNumFrames=20;
    
    sf::IntRect* animation = new sf::IntRect[20];
    
    if(_powerUpType==1){ //ROJO
        _color=sf::Color::Red;
        
        animation[0] = sf::IntRect(32*0, 32*2, 32, 32);  
        animation[1] = sf::IntRect(32*1, 32*2, 32, 32);  
        animation[2] = sf::IntRect(32*2, 32*2, 32, 32);  
        animation[3] = sf::IntRect(32*1, 32*2, 32, 32);  
        
        for(int x=4; x<_animationNumFrames;x++){
            animation[x] = sf::IntRect(32*0, 32*2, 32*1, 32);              
        }
        
         _color=sf::Color::Red;   
       
        //"animation" se borra de memoria en el constructor de Sprite.
        _sprite = new Sprite(texture, animation,  sf::Vector2f(16.0f,16.0f), sf::Vector2f(initialPosX,initialPosY), _animationNumFrames, _animationTime);
    }
    else if(_powerUpType==2){ //AZUL
        animation[0] = sf::IntRect(32*0, 32*3, 32, 32);  
        animation[1] = sf::IntRect(32*1, 32*3, 32, 32);  
        animation[2] = sf::IntRect(32*2, 32*3, 32, 32);  
        animation[3] = sf::IntRect(32*1, 32*3, 32, 32);  
        for(int x=4; x<_animationNumFrames;x++)
        {
            animation[x] = sf::IntRect(32*0, 32*3, 32*1, 32);              
        }
        _color=sf::Color::Cyan;   
        //"animation" se borra de memoria en el constructor de Sprite.
        _sprite = new Sprite(texture, animation,  sf::Vector2f(16.0f,16.0f), sf::Vector2f(initialPosX,initialPosY),   _animationNumFrames,  _animationTime);        
    }
    else if(_powerUpType==3){ //VERDE
        
        animation[0] = sf::IntRect(32*0, 32*4, 32, 32);  
        animation[1] = sf::IntRect(32*1, 32*4, 32, 32);  
        animation[2] = sf::IntRect(32*2, 32*4, 32, 32);  
        animation[3] = sf::IntRect(32*1, 32*4, 32, 32);  
        
        for(int x=4; x<_animationNumFrames;x++){
            animation[x] = sf::IntRect(32*0, 32*4, 32*1, 32);              
        }
        
        
        _color=sf::Color::Green;
        //"animation" se borra de memoria en el constructor de Sprite.
        _sprite = new Sprite(texture, animation,  sf::Vector2f(16.0f,16.0f), sf::Vector2f(initialPosX,initialPosY),   _animationNumFrames,  _animationTime);
    }
    else{        
        //blanco - neutro

        animation[0] = sf::IntRect(32*0, 32*7, 32, 32);  
        animation[1] = sf::IntRect(32*1, 32*7, 32, 32);  
        animation[2] = sf::IntRect(32*2, 32*7, 32, 32);  
        animation[3] = sf::IntRect(32*1, 32*7, 32, 32);  
        
        for(int x=4; x<_animationNumFrames;x++){
            animation[x] = sf::IntRect(32*0, 32*7, 32*1, 32);
        }
        
        _color=sf::Color::White;
        //"animation" se borra de memoria en el constructor de Sprite.
        _sprite = new Sprite(texture, animation,  sf::Vector2f(16.0f,16.0f), sf::Vector2f(initialPosX,initialPosY),   _animationNumFrames,  _animationTime);
    }
}

void PowerUp::interact()
{
    //acciones que ocurren cuando se toca el objeto
    pickPowerUp();
}

void PowerUp::update()
{
    _sprite->updateAnimation();
    if(_collisionPlayer){
        pickPowerUp();
    }
}

void PowerUp::pickPowerUp()
{
    //condiciones para el jugador
    Player::Instance()->setColor(_color);
    
    if(_color == sf::Color::Red)
    {
        Player::Instance()->unlockPowerUp(1);        
    }
    else if(_color == sf::Color::Cyan)
    {
        Player::Instance()->unlockPowerUp(2);        
    }
    else if(_color == sf::Color::Green)
    {
        Player::Instance()->unlockPowerUp(3);                
    }
    
    _collisionPlayer=false;
    _erase=true;
}

int PowerUp::getPowerUpType()
{
    return _powerUpType;
}

sf::Color PowerUp::getColor(){
    return _color;
}
    
PowerUp::PowerUp(const PowerUp& orig) 
{
}


PowerUp::~PowerUp() 
{
    cout <<"Delete de powerup"<<endl;
    //se llama al destructor de object
}

