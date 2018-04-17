/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: newman
 *
 * Created on 17 de abril de 2018, 18:00
 */

#ifndef EVENT_H
#define EVENT_H
#include <SFML/Graphics.hpp>

class Event {
public:
    Event();
    Event(const Event& orig);
    virtual ~Event();
    
    sf::Event* getEventEvent();
    int getEventType();
    int getEventKeyPressed();
    int getEventKeyReleased();
    
private:
    sf::Event* _event;
};

#endif /* EVENT_H */

