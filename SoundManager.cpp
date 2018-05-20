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
    
    _soundBufferLength = 18;
    _soundLength = 18;
    
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
    if(!_buffer[0]->soundBufferLoadFromFile("sounds/changeColor.wav")){
        std::cout <<"Error al cargar el buffer de audio 0" <<std::endl;
    }
    else{
        _sound[z]->setBuffer(_buffer[z]);      
        std::cout <<"SONIDO CARGADO"<<std::endl;
    }
    z++;
    
    if(!_buffer[1]->soundBufferLoadFromFile("sounds/changeColor2.wav")){
        std::cout <<"Error al cargar el buffer de audio 1" <<std::endl;
    }
    else{
        _sound[1]->setBuffer(_buffer[1]);        
    }

    if(!_buffer[2]->soundBufferLoadFromFile("sounds/collision.wav")){
        std::cout <<"Error al cargar el buffer de audio 2" <<std::endl;
    }
    else{
        _sound[2]->setBuffer(_buffer[2]);        
    }
    if(!_buffer[3]->soundBufferLoadFromFile("sounds/damage.wav")){
        std::cout <<"Error al cargar el buffer de audio 3" <<std::endl;
    }
    else{
        _sound[3]->setBuffer(_buffer[3]);        
    }
        if(!_buffer[4]->soundBufferLoadFromFile("sounds/damage2.wav")){
        std::cout <<"Error al cargar el buffer de audio 4" <<std::endl;
    }
    else{
        _sound[4]->setBuffer(_buffer[4]);        
    }
        if(!_buffer[5]->soundBufferLoadFromFile("sounds/damage3.wav")){
        std::cout <<"Error al cargar el buffer de audio 5" <<std::endl;
    }
    else{
        _sound[5]->setBuffer(_buffer[5]);        
    }
        if(!_buffer[6]->soundBufferLoadFromFile("sounds/door.wav")){
        std::cout <<"Error al cargar el buffer de audio 6" <<std::endl;
    }
    else{
        _sound[6]->setBuffer(_buffer[6]);        
    }
        if(!_buffer[7]->soundBufferLoadFromFile("sounds/door2.wav")){
        std::cout <<"Error al cargar el buffer de audio 7" <<std::endl;
    }
    else{
        _sound[7]->setBuffer(_buffer[7]);        
    }
        if(!_buffer[8]->soundBufferLoadFromFile("sounds/endLevel.wav")){
        std::cout <<"Error al cargar el buffer de audio 8" <<std::endl;
    }
    else{
        _sound[8]->setBuffer(_buffer[8]);        
    }
        if(!_buffer[9]->soundBufferLoadFromFile("sounds/enemyStop.wav")){
        std::cout <<"Error al cargar el buffer de audio 9" <<std::endl;
    }
    else{
        _sound[9]->setBuffer(_buffer[9]);        
    }
        if(!_buffer[10]->soundBufferLoadFromFile("sounds/exit.wav")){
        std::cout <<"Error al cargar el buffer de audio 10" <<std::endl;
    }
    else{
        _sound[10]->setBuffer(_buffer[10]);        
    }
    if(!_buffer[11]->soundBufferLoadFromFile("sounds/jingle.wav")){
        std::cout <<"Error al cargar el buffer de audio 11" <<std::endl;
    }
    else{
        _sound[11]->setBuffer(_buffer[11]);        
    }
    if(!_buffer[12]->soundBufferLoadFromFile("sounds/laser.wav")){
        std::cout <<"Error al cargar el buffer de audio 12" <<std::endl;
    }
    else{
        _sound[12]->setBuffer(_buffer[12]);        
    }
    if(!_buffer[13]->soundBufferLoadFromFile("sounds/manaCharge.wav")){
        std::cout <<"Error al cargar el buffer de audio 13" <<std::endl;
    }
    else{
        _sound[13]->setBuffer(_buffer[13]);        
    }
    if(!_buffer[14]->soundBufferLoadFromFile("sounds/powerUp.wav")){
        std::cout <<"Error al cargar el buffer de audio 14" <<std::endl;
    }
    else{
        _sound[14]->setBuffer(_buffer[14]);        
    }
    if(!_buffer[15]->soundBufferLoadFromFile("sounds/pressButton.wav")){
        std::cout <<"Error al cargar el buffer de audio 15" <<std::endl;
    }
    else{
        _sound[15]->setBuffer(_buffer[15]);        
    }
    if(!_buffer[16]->soundBufferLoadFromFile("sounds/speed.wav")){
        std::cout <<"Error al cargar el buffer de audio 16" <<std::endl;
    }
    else{
        _sound[16]->setBuffer(_buffer[16]);        
    }
    if(!_buffer[17]->soundBufferLoadFromFile("sounds/start.wav")){
        std::cout <<"Error al cargar el buffer de audio 17" <<std::endl;
    }
    else{
        _sound[17]->setBuffer(_buffer[17]);        
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
    if(_sound!=NULL)
    {
        if(number<_soundLength)
        {
            if(_sound[number]!=NULL)
            {
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

    std::cout<<"Me pides que reproduzca "<<numeroCancion<<"y yo estoy con"<<_actualMusic<<std::endl;
    
    if(_music!=NULL || _actualMusic==-1 || _actualMusic!=numeroCancion)
    {
        std::cout<<"Cumple los parametros previos"<<std::endl;
        
        if(_music!=NULL && _actualMusic!=numeroCancion){
            std::cout<<"Cancion distinta. Borrando..."<<std::endl;
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
            std::cout<<"Reproduciendo la cancion 0"<<std::endl;
            if(_music->musicGetStopped()==false){
                _music->musicStop();
            }
            _music->musicLoadSong("music/artofsilence.wav");
            _music->musicPlay();
            
            _actualMusic=0;
        }
        else if(numeroCancion==1)
        {
            std::cout<<"Reproduciendo la cancion 1"<<std::endl;
            if(_music->musicGetStopped()==false){
                _music->musicStop();
            }
            _music->musicLoadSong("music/leap.wav");
            _music->musicPlay();
            _actualMusic=1;
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

