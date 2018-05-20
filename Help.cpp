/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Help.cpp
 * Author: carlos
 * 
 * Created on 20 de mayo de 2018, 2:45
 */

#include "Help.h"

Help::Help(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
            int number,sf::Font* font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition)
: Object(objectType, initialPosX, initialPosY, initialAngle, canBeMoved, texture)
{
    _sprite = new Sprite(texture,sf::IntRect(96,64,32,32),sf::Vector2f(16.0f,16.0f),sf::Vector2f(400.0f,400.0f),sf::Vector2f(1.0f,1.0f));  
    _sprite->setSpritePosition(sf::Vector2f(initialPosX,initialPosY));
    _show=false;
    _showLastUpdate=false;
    _message = new Message(number,font,texturebg,pjbounds,pjposition);
    _messageNumber=number;
}

void Help::update()
{
    if(_showLastUpdate&&_show==false){
        _show=false;
        _showLastUpdate=false;
    }
    else{
        _message->update();
    }

    if(_show){
        //actualizacion del mensaje.
        _showLastUpdate=true;
        //std::cout<<"Deberia mostrar el mensaje"<<std::endl;
        _show=false;
        
        if(_message!=NULL){
            _message->update();
        }
    }
}

void Help::setShowMessage(bool b)
{
    _show=b;
}
bool Help::getShowMessage()
{
    return _show;
}
    
Message* Help::getMessage()
{
    if(_message!=NULL)return _message;
    else{
        return NULL;
    }
}

Help::Help(const Help& orig) {
}

Help::~Help() {
    if(_message!=NULL){
        delete _message;
    }
    _message=NULL;
}

