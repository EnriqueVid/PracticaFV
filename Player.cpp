/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   _player.cpp
 * Author: tuba
 * 
 * Created on 20 de abril de 2018, 22:55
 */

#include "Player.h"
#include "Input.h"

Player* Player::_pinstance=0;

Player* Player::Instance()
{
    if(_pinstance==0)
    {
        _pinstance = new Player();
    }
    return _pinstance;
}

//Si no se setea nada el jugador empieza sin Textura y con todos los parámetros
//por defecto.
Player::Player() 
{
     _maxHealth=256;
     _health=256;
     _maxStamina=100;
     _stamina=100;
     _player=new Sprite();
     _speed=5;
     _color=sf::Color::White;
     _hability=false;
     _previousSituation=new Situation();
     _actualSituation=new Situation();
}

Player::Player(const Player& orig) 
{
    
}

Player::~Player()
{
    delete _player;
    _player = NULL;
    
    _pinstance = 0;
    
    delete _actualSituation;
    _actualSituation = NULL;
    
    delete _previousSituation;
    _previousSituation = NULL;
}

void Player::input()
{
    Input* input = Input::Instance();
    
    input->inputInput();
    
    if(input->inputCheck(0))
    {
        _axis.x = 0;
        _axis.y = -1;
        //cout<<"UP"<<endl;
    }
    if(input->inputCheck(1))
    {
        _axis.x = 0;
        _axis.y = 1;
        //cout<<"DOWN"<<endl;
    }
    if(input->inputCheck(2))
    {
        _axis.x = -1;
        _axis.y = 0;
        //cout<<"LEFT"<<endl;
    }
    if(input->inputCheck(3))
    {
        _axis.x = 1;
        _axis.y = 0;
        //cout<<"RIGHT"<<endl;
    }
    
    if(input->inputCheck(0) && input->inputCheck(3))
    {
        _axis.x = 1;
        _axis.y = -1;
        //cout<<"UP AND RIGHT"<<endl;
    }
    if(input->inputCheck(1) && input->inputCheck(3))
    {
        _axis.x = 1;
        _axis.y = 1;
        //cout<<"DOWN AND RIGHT"<<endl;
    }
    if(input->inputCheck(0) && input->inputCheck(2))
    {
        _axis.x = -1;
        _axis.y = -1;
        //cout<<"UP AND LEFT"<<endl;
    }
    if(input->inputCheck(1) && input->inputCheck(2))
    {
        _axis.x = -1;
        _axis.y = 1;
        //cout<<"DOWN AND LEFT"<<endl;
    }
    
    if(input->inputCheck(12))
    {
        _hability = true;
    }
    
    
}

void Player::keyReleased()
{
    _axis.x = 0;
    _axis.y = 0;
    _hability = false;
}

void Player::update()
{
    _player->setSpritePosition(_actualSituation->getPosition());
    _player->setSpriteRotation(_actualSituation->getAngle());
        
    _previousSituation = new Situation(_actualSituation->getPositionX(), _actualSituation->getPositionY(), _actualSituation->getAngle());
    
    if(_clock==NULL)
    {
        move();
    }else
    {
        _axis.x = _direction.x;
        _axis.y = _direction.y;
    }
    
    superSpeed();
    
    sf::Vector2f moving(0,0);
    
    moving.x = abs(_axis.x)*_speed*(cos(degreesToRadians(_player->getSpriteRotation())));
    
    moving.y = abs(_axis.y)*_speed*(sin(degreesToRadians(_player->getSpriteRotation())));
    
    _player->spriteMove(moving);
    
    _actualSituation = new Situation(_player->getSpritePosition().x, _player->getSpritePosition().y, _player->getSpriteRotation());
    
    keyReleased();
}

void Player::render(RenderWindow* window, Clock* clock, float ups)
{
    float actualTime = clock->getClockAsSeconds() / ups;
    interpolate(actualTime);
    window->windowDraw(_player);
}

void Player::interpolate(float actualTime)
{
    float x, y, g;
    
    
    x = (((actualTime-0)*(_actualSituation->getPosition().x - _previousSituation->getPosition().x))/(1-0)) + _previousSituation->getPosition().x;
    
    y = (((actualTime-0)*(_actualSituation->getPosition().y - _previousSituation->getPosition().y))/(1-0)) + _previousSituation->getPosition().y;
    
    g = (((actualTime-0)*(_actualSituation->getAngle() - _previousSituation->getAngle()))/(1-0)) + _previousSituation->getAngle();
    
    
    _player->setSpritePosition(sf::Vector2f(x,y));
    _player->setSpriteRotation(g);
    
}

void Player::superSpeed()
{
    if(_hability && _clock==NULL && _stamina==_maxStamina)
    {
        _clock = new Clock();
        _hability=false;
        _stamina=0;
        _speed = _speed*4;
    }
    
    if(_clock!=NULL)
    {
        if(_clock->getClockAsSeconds()<=1.0f)
        {
            
        }else
        {
            delete _clock;
            _clock = NULL;
            _speed = _speed/4;
        }
    }
    
}

float Player::degreesToRadians(float degree)
{
    return ((degree*PI)/180);
}

void Player::move()
{
    float angle = 0;
        
    //cout << "Valor ejeX: "<< ejeX << ". Valor ejeY: " << ejeY << endl;
    //arriba-derecha
    
    if(_axis.x==1&&_axis.y==-1)
    {
        
        if(_player->getSpriteRotation()<135)
        {
            _previousSituation->setAngle(_player->getSpriteRotation()+360);
        }
        
        angle = 315;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(_speed*sin(45),-_speed*sin(45)));
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
        
    }else
        //abajo derecha
    if(_axis.x==1&&_axis.y==1)
    {

        angle = 45;
        
        if(_player->getSpriteRotation()>225)
        {
            _previousSituation->setAngle(_player->getSpriteRotation()-360);
        }

        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(_speed*sin(45),_speed*sin(45)));
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //arriba izquierda
    if(_axis.x==-1&&_axis.y==-1)
    {
        
        angle = 225;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(-_speed*sin(45),-_speed*sin(45)));
    
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //abajo izquierda
    if(_axis.x==-1&&_axis.y==1)
    {
        
        angle = 135;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(-_speed*sin(45),_speed*sin(45)));
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //derecha
    if(_axis.x==1)
    {
        
        //sprite->setRotation(0);
        /*
        if(sprite->getRotation()==330)
        {
            
            SituationAnterior->setGrados(-90);
            sprite->setRotation(sprite->getRotation()+90);    
            
        }
        
        if(sprite->getRotation()>180)
        {
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>0)
        {
            sprite->setRotation(sprite->getRotation()-90);
        }*/
        
        angle = 0;
        
        if(_player->getSpriteRotation()>180)
        {
            _previousSituation->setAngle(_player->getSpriteRotation()-360);
        }
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(_speed,0));
        
        _direction.x=_axis.x;
        _direction.y=0;
        
        //izquierda
    }else if(_axis.x==-1)
    {
        //sprite->setRotation(180);
        /*if(sprite->getRotation()<180)
        {
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>180)
        {
            sprite->setRotation(sprite->getRotation()-90);
        }
         */
        angle = 180;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(_speed*(cos((angle)/(2*PI))),0));
        
        
        _direction.x=_axis.x;
        _direction.y=0;
        
    }else 
        //arriba
    if(_axis.y==-1)
    {
        //sprite->setRotation(270);
        
        /*
        if(sprite->getRotation()==0)
        {
            SituationAnterior->setGrados(360);
        }
        
        if(sprite->getRotation()<270 && sprite->getRotation()>=90)
        {
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>270 || sprite->getRotation()<90)
        {
            sprite->setRotation(sprite->getRotation()-90);
        }
         */
        
        if(_player->getSpriteRotation()<180)
        {
            _previousSituation->setAngle(_player->getSpriteRotation()+360);
        }
        
        angle = 270;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(0,-_speed));
        
        
        _direction.x=0;
        _direction.y=_axis.y;
        
        //abajo
    }else if(_axis.y==1)
    {
        //sprite->setRotation(90);
        /*
        if(sprite->getRotation()<90)
        {
            sprite->setRotation(sprite->getRotation()+30);
        }else if(sprite->getRotation()>90)
        {
            sprite->setRotation(sprite->getRotation()-30);
        }
         */
        
        angle = 90;
        
        _player->setSpriteRotation(angle);
        //_player->spriteMove(sf::Vector2f(0,_speed));
        
        _direction.x=0;
        _direction.y=_axis.y;
    }
}


//Setters
void Player::setColor(sf::Color color)
{
    _color = color;
}

void Player::setAxis(sf::Vector2i axis)
{
    _axis = axis;
}

void Player::setHealth(float health)
{
    _health = health;
}

void Player::setDirection(sf::Vector2i direction)
{
    _direction = direction;
}

void Player::setPlayer(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _previousSituation->setPosition(position.x, position.y);
    _actualSituation->setPosition(position.x, position.y);
    _player = new Sprite(texture, box, origin, position, scale);
}

void Player::setSpeed(int speed)
{
    _speed = speed;
}

void Player::setStamina(float stamina)
{
    _stamina = stamina;
}

void Player::newSituacion(float x, float y, float g)
{
    _previousSituation->setPosition(_actualSituation->getPosition().x, _actualSituation->getPosition().y);
    _previousSituation->setAngle(_actualSituation->getAngle());
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}

void Player::setActualSituation(float x, float y, float g)
{
    _actualSituation->setPosition(x,y);
    _actualSituation->setAngle(g);
}
void Player::setPreviousSituation(float x, float y, float g)
{
    _previousSituation->setPosition(x,y);
    _previousSituation->setAngle(g);
} 


//Getters
Sprite* Player::getPlayer()
{
    return _player;
}

sf::Color Player::getColor()
{
    return _color;
}

int Player::getSpeed()
{
    return _speed;
}

float Player::getHealth()
{
    return _health;
}

float Player::getStamina()
{
    return _stamina;
}

bool Player::getHability()
{
    return _hability;
}

Situation* Player::getPreviousSituation()
{
    return _previousSituation;
}

Situation* Player::getActualSituation()
{
    return _actualSituation;
}