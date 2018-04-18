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
            return 1;

        default:
            return 0;
            
   
    }
}
