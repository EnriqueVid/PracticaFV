/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SoundBuffer.h
 * Author: carlos
 *
 * Created on 17 de mayo de 2018, 2:16
 */

#ifndef SOUNDBUFFER_H
#define SOUNDBUFFER_H
#include <SFML/Audio.hpp>

class SoundBuffer {
public:
    SoundBuffer();
    SoundBuffer(const SoundBuffer& orig);
    virtual ~SoundBuffer();
    
    bool soundBufferLoadFromFile(const std::string& filename);
    sf::SoundBuffer* getSoundBuffer();
private:
    sf::SoundBuffer* _soundBuffer;
};

#endif /* SOUNDBUFFER_H */

