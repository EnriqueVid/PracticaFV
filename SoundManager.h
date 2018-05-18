/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SoundManager.h
 * Author: carlos
 *
 * Created on 17 de mayo de 2018, 1:53
 */

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>
#include "Sound.h"
#include "SoundBuffer.h"
#include "Music.h"


/**/
class SoundManager {
public:
    static SoundManager* Instance();
    virtual ~SoundManager();
    
    void loadSoundsAndBuffers();
    void eraseSoundsAndBuffers();
    
    void playSound(int number);
    void pauseSound(int number);
    Sound* getSound(int number);
    
    SoundBuffer* getSoundBuffer(int number);
    
    Sound** getSoundArray();
    SoundBuffer** getSoundBufferArray();
    
    
    void playMusic(int numeroCancion);
    void pauseMusic();
    void resumeMusic();
    void stopMusic();
    
    void setMusicPitch(float pitch);   
    void setMusicVolume(float volume);
    
    Music* getMusic();
    int getSoundLength();
    int getSoundBufferLength();
    
    
    
protected:
    SoundManager();
    SoundManager(const SoundManager& orig);
    
private:
    static SoundManager* _pinstance;
    
    SoundBuffer** _buffer;
    Sound** _sound;
    
    Music* _music;
    int _actualMusic;
    
    int _soundBufferLength;
    int _soundLength;
};

#endif /* SOUNDMANAGER_H */

