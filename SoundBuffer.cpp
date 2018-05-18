/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SoundBuffer.cpp
 * Author: carlos
 * 
 * Created on 17 de mayo de 2018, 2:16
 */

#include "SoundBuffer.h"

SoundBuffer::SoundBuffer() 
{
    _soundBuffer = new sf::SoundBuffer;
}

bool SoundBuffer::soundBufferLoadFromFile(const std::string& filename)
{
    return _soundBuffer->loadFromFile(filename);
}

sf::SoundBuffer* SoundBuffer::getSoundBuffer()
{
    return _soundBuffer;
}
    

SoundBuffer::SoundBuffer(const SoundBuffer& orig) 
{
    
}

SoundBuffer::~SoundBuffer() 
{
    if(_soundBuffer!=NULL){
        delete _soundBuffer;
        _soundBuffer=NULL;
    }
}

