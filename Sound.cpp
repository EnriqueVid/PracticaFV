/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sound.cpp
 * Author: carlos
 * 
 * Created on 17 de mayo de 2018, 2:16
 */

#include "Sound.h"
#include <iostream>

Sound::Sound() {
    _sound = new sf::Sound();
}

void Sound::soundPlay()
{
    std::cout <<"EH, DEBERIA ESTAR REPRODUCIENDOME"<< std::endl;
    _sound->play();
}
void Sound::soundPause()
{
    _sound->pause();
}
sf::Sound* Sound::getSound()
{
    return _sound;
}
void Sound::setBuffer(SoundBuffer* buffer)
{
    //es posible que haya un error aqui:
    _sound->setBuffer(*buffer->getSoundBuffer());
}

Sound::Sound(const Sound& orig) {
    
}

Sound::~Sound() {
    if(_sound!=NULL){
        delete _sound;
        _sound=NULL;
    }
}

