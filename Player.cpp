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
#include "Situation.h"

Player* Player::_pinstance=0;

Player* Player::Instance()
{
    if(_pinstance==0)
    {
        _pinstance = new Player;
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
     _sprite=new Sprite();
     _speed=5;
     _color=sf::Color::White;
     _hability=false;
     _previousSituation=new Situation();
     _actualSituation=new Situation();
     _clock = NULL;
     _animationNumFrames=-1;
     _animationTime=-1;
     _idleAnimationStart=true;
     _movingAnimationStart=false;
     _damage=false;
     _actualAnimation=0;
     
}

Player::Player(const Player& orig) 
{
    
}

Player::~Player()
{
    delete _sprite;
    _sprite = NULL;
    
    _pinstance = 0;
    
    delete _actualSituation;
    _actualSituation = NULL;
    
    delete _previousSituation;
    _previousSituation = NULL;
}

void Player::setPlayer(Texture* texture, sf::IntRect* box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _previousSituation->setPosition(position.x, position.y);
    _actualSituation->setPosition(position.x, position.y);
    
    
    _sprite = new Sprite(texture,getAnimation(0),origin,position,scale,_animationNumFrames,_animationTime);
    
   //_sprite = new Sprite(texture, *box, origin, position, scale);
    
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
    
    if(input->inputCheck(4))
    {
        _axis.x = 0;
        _axis.y = -1;
        //cout<<"UP"<<endl;
    }
    if(input->inputCheck(6))
    {
        _axis.x = 0;
        _axis.y = 1;
        //cout<<"DOWN"<<endl;
    }
    if(input->inputCheck(5))
    {
        _axis.x = -1;
        _axis.y = 0;
        //cout<<"LEFT"<<endl;
    }
    if(input->inputCheck(7))
    {
        _axis.x = 1;
        _axis.y = 0;
        //cout<<"RIGHT"<<endl;
    }
    
    if(input->inputCheck(4) && input->inputCheck(7))
    {
        _axis.x = 1;
        _axis.y = -1;
        //cout<<"UP AND RIGHT"<<endl;
    }
    if(input->inputCheck(6) && input->inputCheck(7))
    {
        _axis.x = 1;
        _axis.y = 1;
        //cout<<"DOWN AND RIGHT"<<endl;
    }
    if(input->inputCheck(4) && input->inputCheck(5))
    {
        _axis.x = -1;
        _axis.y = -1;
        //cout<<"UP AND LEFT"<<endl;
    }
    if(input->inputCheck(6) && input->inputCheck(5))
    {
        _axis.x = -1;
        _axis.y = 1;
        //cout<<"DOWN AND LEFT"<<endl;
    }
    
    if(input->inputCheck(8))
    {    
        _damage=true; 
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
    _damage = false;
}

void Player::update()
{
    _sprite->setSpritePosition(_actualSituation->getPosition());
    _sprite->setSpriteRotation(_actualSituation->getAngle());
        
    _previousSituation = new Situation(_actualSituation->getPositionX(), _actualSituation->getPositionY(), _actualSituation->getAngle());
    
    if(_clock==NULL)
    {
        move();
    }else
    {
        _axis.x = _direction.x;
        _axis.y = _direction.y;
    }
    
    if(_color == sf::Color::Blue)
    {
       superSpeed();
    }
    if(_color == sf::Color::Red)
    {
       //breakBox();
    }
    if(_color == sf::Color::Green)
    {
       //shoot();
    }
    
    
    sf::Vector2f moving(0,0);
    
    moving.x = abs(_axis.x)*_speed*(sin(degreesToRadians(_sprite->getSpriteRotation())))*-1;
    
    moving.y = abs(_axis.y)*_speed*(cos(degreesToRadians(_sprite->getSpriteRotation())));
    
    //cout << "damage: " <<_damage << endl;
    
    _sprite->spriteMove(moving);
    
    _sprite->updateAnimation();
    
    _actualSituation = new Situation(_sprite->getSpritePosition().x, _sprite->getSpritePosition().y, _sprite->getSpriteRotation());
    
    int actualFrame = 0;
    
    if(_axis.x==0&&_axis.y==0)
    {
        if(_idleAnimationStart){
            //SI EL PERSONAJE ESTA QUIETO
            if(!_damage)
            {
            sf::IntRect* animationBox = getAnimation(0);
            _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);  
            //animationBox se deletea en el propio sprite
            animationBox=NULL;
            _actualAnimation=0;
            }
            else
            {
            sf::IntRect* animationBox = getAnimation(2);
            _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);                  
            //animationBox se deletea en el propio sprite
            animationBox=NULL;
            _actualAnimation=2;
            }   
        }
        else
        {
            if(!_damage&&_actualAnimation!=0)
            {
                sf::IntRect* animationBox = getAnimation(0);
                _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);  
                //animationBox se deletea en el propio sprite
                animationBox=NULL;  
                _actualAnimation=0;
            }
            else if(_damage&&_actualAnimation!=2)
            {
                sf::IntRect* animationBox = getAnimation(2);
                _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);                  
                //animationBox se deletea en el propio sprite
                animationBox=NULL;
                _actualAnimation=2;
            }
        }

        

        _movingAnimationStart=true;
        _idleAnimationStart=false;
    }
    else
    {
        if(_movingAnimationStart)
        {
            //SI EL PERSONAJE SE ESTA MOVIENDO
            if(!_damage)
            {
            sf::IntRect* animationBox = getAnimation(1);
            _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);  
            //animationBox se deletea en el propio sprite
            animationBox=NULL;
            _actualAnimation=1;
            }
            else
            {
            sf::IntRect* animationBox = getAnimation(3);
            _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);                  
            //animationBox se deletea en el propio sprite
            animationBox=NULL;
            _actualAnimation=3;
            }              
        }
        else
        {
            if(!_damage&&_actualAnimation!=1)
            {
                if(_actualAnimation==3)
                {
                    actualFrame = _sprite->getAnimationFrame();
                    sf::IntRect* animationBox = getAnimation(1);
                    _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);  
                    //animationBox se deletea en el propio sprite
                    animationBox=NULL;
                    _sprite->setAnimationFrame(actualFrame);
                    _actualAnimation=1;
                }
            }
            else if(_damage&&_actualAnimation!=3)
            {
                if(_actualAnimation==1)
                {
                    actualFrame = _sprite->getAnimationFrame();
                    sf::IntRect* animationBox = getAnimation(3);
                    _sprite->changeAnimation(animationBox,_animationNumFrames,_animationTime);  
                    //animationBox se deletea en el propio sprite
                    animationBox=NULL;
                    _sprite->setAnimationFrame(actualFrame);
                    _actualAnimation=3;
                }                
            }
        }


                
        if(_clock!=NULL)
        {
            _sprite->setAnimationTime(0.01/4);
            _animationTime=0.001;
        }
        else
        {
            _sprite->setAnimationTime(0.01);            
            _animationTime=0.01;
        }
        
        _idleAnimationStart=true;
        _movingAnimationStart=false;
    }
    keyReleased();
    
}

void Player::render(RenderWindow* window, Clock* clock, float ups)
{
    float actualTime = clock->getClockAsSeconds() / ups;
    interpolate(actualTime);
    window->windowDraw(_sprite);
}

void Player::interpolate(float actualTime)
{
    float x, y, g;
    
    
    x = (((actualTime-0)*(_actualSituation->getPosition().x - _previousSituation->getPosition().x))/(1-0)) + _previousSituation->getPosition().x;
    
    y = (((actualTime-0)*(_actualSituation->getPosition().y - _previousSituation->getPosition().y))/(1-0)) + _previousSituation->getPosition().y;
    
    g = (((actualTime-0)*(_actualSituation->getAngle() - _previousSituation->getAngle()))/(1-0)) + _previousSituation->getAngle();
    
    
    _sprite->setSpritePosition(sf::Vector2f(x,y));
    _sprite->setSpriteRotation(g);
    
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
        
        
        angle = 225;
        
        _sprite->setSpriteRotation(angle);
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
        
    }else
        //abajo derecha
    if(_axis.x==1&&_axis.y==1)
    {

        angle = 315;
        
        
        _sprite->setSpriteRotation(angle);
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //arriba izquierda
    if(_axis.x==-1&&_axis.y==-1)
    {
        
        angle = 135;
        
        _sprite->setSpriteRotation(angle);
    
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //abajo izquierda
    if(_axis.x==-1&&_axis.y==1)
    {
        angle = 45;
        
        _sprite->setSpriteRotation(angle);
        
        _direction.x=_axis.x;
        _direction.y=_axis.y;
    
    }else
        //derecha
    if(_axis.x==1)
    {
        angle = 270;
        
        _sprite->setSpriteRotation(angle);
        
        _direction.x=_axis.x;
        _direction.y=0;
        
        //izquierda
    }else if(_axis.x==-1)
    {
        angle = 90;
         
        _sprite->setSpriteRotation(angle);
        
        _direction.x=_axis.x;
        _direction.y=0;
        
    }else 
        //arriba
    if(_axis.y==-1)
    {
        angle = 180;
        
        _sprite->setSpriteRotation(angle);
        
        _direction.x=0;
        _direction.y=_axis.y;
        
        //abajo
    }else if(_axis.y==1)
    {      
        angle = 0;

        _sprite->setSpriteRotation(angle);
        
        _direction.x=0;
        _direction.y=_axis.y;
    }
}


//Setters
void Player::setColor(sf::Color color)
{
    _color = color;
    _sprite->setSpriteColor(_color.r,_color.g,_color.b,_color.a);
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



void Player::setSpeed(int speed)
{
    _speed = speed;
}

void Player::setStamina(float stamina)
{
    _stamina = stamina;
}

void Player::newSituation(float x, float y, float g)
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

//Duda importante: ¿Produce este metodo un memory leak al generar la nueva animacion?
sf::IntRect* Player::getAnimation(int animationNum)
{
    sf::IntRect* animation;
            int aux=1;            
    
    switch (animationNum)
    {
        case 0: 
            //Animacion quieto
            animation = new sf::IntRect[24];
            
            for(int x=0; x<24; x++){
                if(x==8)aux=0;
                animation[x] = sf::IntRect((0+32*x*aux), 32, 32, 32);
            }

            _animationNumFrames=24;
            _animationTime=0.01;
            return animation;
            
            break;
            
        case 1:
            //Animacion de movimineto
            animation = new sf::IntRect[8];
            
            for(int x=0; x<8; x++)
            {
                animation[x] = sf::IntRect((0+32*x), 0, 32, 32);
            }
            _animationNumFrames=8;
            _animationTime=0.01;
            return animation;
            break;
            
        case 2: 
             //Animacion quieto sufriendo damage
            animation = new sf::IntRect[1];

            
            animation[0] = sf::IntRect(0, 32*3, 32, 32);
            

            _animationNumFrames=1;
            _animationTime=0.01;
            return animation;
            
            break;           
            
        case 3:
            //Animacion de movimineto sufriendo damage
            animation = new sf::IntRect[8];
            for(int x=0; x<8; x++)
            {
                animation[x] = sf::IntRect((0+32*x), 32*2, 32, 32);
            }
            _animationNumFrames=8;
            _animationTime=0.01;
            return animation;
            break;   
    }
    return animation;
}

//Getters
Sprite* Player::getPlayer()
{
    return _sprite;
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

sf::Vector2i Player::getDirection()
{
    return _direction;
}