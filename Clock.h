/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.h
 * Author: newman
 *
 * Created on 18 de abril de 2018, 17:47
 */

#ifndef CLOCK_H
#define CLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Clock {
public:
    Clock();
    Clock(const Clock& orig);
    virtual ~Clock();
    
    void clockRestart();
    
    float getClockAsSeconds();
    float getClockAsMilliseconds();
    float getClockAsMicroseconds();
    
private:
    sf::Clock* _clock;

};

#endif /* CLOCK_H */

