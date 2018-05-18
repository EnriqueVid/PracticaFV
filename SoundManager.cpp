/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SoundManager.cpp
 * Author: carlos
 * 
 * Created on 17 de mayo de 2018, 1:53
 */



#include "SoundManager.h"
#include <iostream>

SoundManager* SoundManager::_pinstance = 0;
SoundManager* SoundManager::Instance()
{    
    if(_pinstance == 0)
    {
        _pinstance = new SoundManager;
    }
    return _pinstance;
}

SoundManager::SoundManager() {
    
    std::cout <<"INICIALIZANDO TODOOO"<<std::endl;
    
    _actualMusic = -1;
    
    _soundBufferLength = 2;
    _soundLength = 2;
    
    _music = new Music();
    
    
    _sound = new Sound*[_soundLength];
    _buffer = new SoundBuffer*[_soundBufferLength];
    
    for(int x=0; x<_soundBufferLength; x++)
    {
        _buffer[x] = new SoundBuffer();
    }
    
    
    for(int i=0 ; i<_soundLength; i++)
    {
        _sound[i] = new Sound();
    }
    
    
    //Cargando los buffer de los sonidos
    int z =0;
    if(!_buffer[0]->soundBufferLoadFromFile("sounds/disparo.wav")){
        std::cout <<"Error al cargar el buffer de audio" <<std::endl;
    }
    else{
        _sound[z]->setBuffer(_buffer[z]);      
        std::cout <<"SONIDO CARGADO"<<std::endl;
    }
    z++;
    
    if(!_buffer[1]->soundBufferLoadFromFile("sounds/disparo.wav")){
        std::cout <<"Error al cargar el buffer de audio" <<std::endl;
    }
    else{
        _sound[1]->setBuffer(_buffer[1]);        
    }
    /*
    z++;
    if(!_buffer[2]->soundBufferLoadFromFile("sounds/heridoVerde.wav")){
        std::cout <<"Error al cargar el buffer de audio" <<std::endl;
        _sound[2]->setBuffer(_buffer[2]);
    }    
    else{
        _sound[z]->setBuffer(_buffer[z]);        
    }
    */
    
    
    
}
void SoundManager::loadSoundsAndBuffers()
{
    
}
void SoundManager::eraseSoundsAndBuffers()
{
    
}
    
void SoundManager::playSound(int number)
{
                std::cout <<"Linea 1."<<std::endl;
    if(_sound!=NULL)
    {
                std::cout <<"Linea 2."<<std::endl;
        if(number<_soundLength)
        {
                std::cout <<"Linea 3."<<std::endl;
            if(_sound[number]!=NULL)
            {
                std::cout <<"ESTOY EJECUTANDO ESTE SONIDO."<<std::endl;
                _sound[number]->soundPlay();
            }
        }
    }
}
void SoundManager::pauseSound(int number)
{
    if(_sound!=NULL)
    {
        if(number<_soundLength)
        {
            if(_sound[number]!=NULL)
            {
                _sound[number]->soundPause();
            }
        }
    }
}

Sound* SoundManager::getSound(int number)
{
    if(_sound!=NULL)
    {
        if(number<_soundLength)
        {
            if(_sound[number]!=NULL)
            {
                return _sound[number];
            }
        }
    }  
    return NULL;
}


SoundBuffer* SoundManager::getSoundBuffer(int number)
{
    if(_buffer!=NULL)
    {
        if(number<_soundBufferLength)
        {
            if(_buffer[number]!=NULL)
            {
                return _buffer[number];
            }
        }
    }  
    return NULL;
}


void SoundManager::playMusic(int numeroCancion)
{

    if(_music!=NULL || _actualMusic==-1 || _actualMusic!=numeroCancion)
    {
        
        if(_music!=NULL && _actualMusic!=numeroCancion){
        _music->musicStop();
            delete _music;
            _music=NULL;
            _music = new Music();
        }

        if(numeroCancion==_actualMusic)
        {
            //Sigue la reproduccion.
        }
        
        else if(numeroCancion==0)
        {
            if(_music->musicGetStopped()==false){
                _music->musicStop();
            }
            std::cout<<"Allevoy"<<std::endl;
            _music->musicLoadSong("music/ocean.ogg");
            _music->musicPlay();
        }
        
        
        
        
    }


}
void SoundManager::pauseMusic()
{
    if(_music!=NULL){
        _music->musicPause();
    }
}
void SoundManager::resumeMusic()
{
    if(_music!=NULL){
        _music->musicPlay();
    }
}
void SoundManager::stopMusic()
{
    if(_music!=NULL){
        _music->musicStop();
    }
}
    
void SoundManager::setMusicPitch(float pitch)
{
    if(_music!=NULL)
    {
        _music->musicSetPitch(pitch);
    }
}

void SoundManager::setMusicVolume(float volume)
{
    if(_music!=NULL)
    {
        _music->musicSetVolume(volume);
    }
}

Music* SoundManager::getMusic()
{
    if(_music!=NULL){
        return _music;
    }
    else{
        return NULL;
    }
}
int SoundManager::getSoundLength()
{
    return _soundLength;
}
int SoundManager::getSoundBufferLength()
{
    return _soundBufferLength;
}

SoundManager::SoundManager(const SoundManager& orig) {
}

SoundManager::~SoundManager() {
    for(int x=0; x<_soundLength; x++)
    {
        if(_sound!=NULL){
            if(_sound[x]!=NULL)
            {
                delete[] _sound[x];
                _sound[x]=NULL;   
            }
        }
    }
    if(_sound!=NULL)delete _sound;
    
    _sound = NULL;
    
    for(int i=0; i<_soundBufferLength; i++)
    {
        if(_buffer!=NULL){
            if(_buffer[i]!=NULL)
            {
            delete[] _buffer[i];
            _buffer[i]=NULL;            
            }
        }
    }
    if(_buffer!=NULL){
        delete _buffer;        
    }
    _buffer=NULL;
    
    if(_music!=NULL)
    {
        delete _music;
    }
    _music=NULL;
}

