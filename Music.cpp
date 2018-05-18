/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Music.cpp
 * Author: carlos
 * 
 * Created on 17 de mayo de 2018, 21:02
 */

#include "Music.h"

Music::Music() 
{
    _music = new sf::Music;
    _loop = false;
    _volume = 0;
    _pitch = 0; 
}


bool Music::musicLoadSong(const std::string& filename)
{
    if(_music!=NULL){
        delete _music;
        _music=NULL;
    }
    _music = new sf::Music;
    
    return _music->openFromFile(filename);
    
}
void Music::musicPlay()
{
    if(_music!=NULL)
    {
        _music->play();
    }
}
void Music::musicPause()
{
    if(_music!=NULL)
    {
        _music->pause();
    }    
}
void Music::musicStop()
{
    if(_music!=NULL)
    {
        _music->stop();
    }      
}
void Music::musicSetVolume(float volume)
{
    if(_music!=NULL)
    {
        _music->setVolume(volume);
    }      
}
void Music::musicSetPitch(float pitch)
{
    if(_music!=NULL)
    {
        _music->setPitch(pitch);
    }      
}
void Music::musicSetLoop(bool loop)
{
    if(_music!=NULL)
    {
        _music->setLoop(loop);
    }      
}
    
float Music::musicGetVolume()
{
    if(_music!=NULL){
        return _music->getVolume();
    }
    return -1;
}
float Music::musicGetPitch()
{
    if(_music!=NULL){
        return _music->getPitch();
    }
    return -1;    
}
    
void Music::restartActualSong()
{
    if(_music!=NULL){
        _music->stop();
        _music->play();
    }
}

bool Music::musicGetStopped()
{
    if(_music!=NULL){
        return _music->Stopped;
    }
}

Music::Music(const Music& orig)
{
}

Music::~Music() 
{
    if(_music!=NULL){
        delete _music;        
    }
    _music=NULL;
}

