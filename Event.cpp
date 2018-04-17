/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: newman
 * 
 * Created on 17 de abril de 2018, 18:00
 */

#include "Event.h"

Event::Event() {
    _event = new sf::Event();
}

Event::Event(const Event& orig) {
}

Event::~Event() {
}

sf::Event* Event::getEventEvent()
{
    return _event;
}

int Event::getEventType()
{
    int resul;
    switch(_event->type)
    {
        case sf::Event::Closed: //Close siempre valor 0
            return 666;
            
        
        case sf::Event::KeyPressed:
            resul = getEventKeyPressed();
            return resul;
            
        
        case sf::Event::KeyReleased:
            resul = getEventKeyReleased();
            return resul;
            
            
        default:
            return 0;
            
   
    }
}

int Event::getEventKeyPressed()
{
    int resul = 1; //Valor por defecto. NO debe hacer nada
    
    if(_event->key.code == sf::Keyboard::Up) resul = 2;
    if(_event->key.code == sf::Keyboard::Down) resul = 3;
    if(_event->key.code == sf::Keyboard::Left) resul = 4;
    if(_event->key.code == sf::Keyboard::Right) resul = 5;
    if(_event->key.code == sf::Keyboard::Up &&  == sf::Keyboard::Right) resul = 6;
    if(_event->key.code == sf::Keyboard::Right && _event->key.code == sf::Keyboard::Down) resul = 7;
    if(_event->key.code == sf::Keyboard::Down && _event->key.code == sf::Keyboard::Left) resul = 8;
    if(_event->key.code == sf::Keyboard::Left && _event->key.code == sf::Keyboard::Up) resul = 9;
    if(_event->key.code == sf::Keyboard::Up && _event->key.code == sf::Keyboard::Down) resul = 1;
    if(_event->key.code == sf::Keyboard::Left && _event->key.code == sf::Keyboard::Right) resul = 1;
    
    return resul;
}

int Event::getEventKeyReleased()
{
    int resul = -1;  //Valor por defecto. NO debe hacer nada
    
    return resul;
}
