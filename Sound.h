/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sound.h
 * Author: carlos
 *
 * Created on 17 de mayo de 2018, 2:16
 */

#ifndef SOUND_H
#define SOUND_H
#include <SFML/Audio.hpp>
#include "SoundBuffer.h"

class Sound {
public:
    Sound();
    Sound(const Sound& orig);
    virtual ~Sound();
    
    void soundPlay();
    void soundPause();
    sf::Sound* getSound();
    void setBuffer(SoundBuffer* buffer);
private:
    sf::Sound* _sound;
};

#endif /* SOUND_H */

