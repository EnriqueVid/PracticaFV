/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.cpp
 * Author: newman
 * 
 * Created on 18 de abril de 2018, 17:47
 */

#include <SFML/System/Clock.hpp>

#include "Clock.h"

Clock::Clock() 
{
    _clock = new sf::Clock();
}

Clock::Clock(const Clock& orig) {
}

Clock::~Clock() {
    delete _clock;
    _clock = NULL;
}

void Clock::clockRestart()
{
    _clock->restart();
}

float Clock::getClockAsMicroseconds()
{
    return _clock->getElapsedTime().asMicroseconds();
}

float Clock::getClockAsMilliseconds()
{
    return _clock->getElapsedTime().asMilliseconds();
}

float Clock::getClockAsSeconds()
{
    return _clock->getElapsedTime().asSeconds();
}

