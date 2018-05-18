/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Music.h
 * Author: carlos
 *
 * Created on 17 de mayo de 2018, 21:02
 */

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>


class Music {
public:
    Music();
    Music(const Music& orig);
    virtual ~Music();
    
    bool musicLoadSong(const std::string& filename);
    void musicPlay();
    void musicPause();
    void musicStop();
    void musicSetVolume(float volume);
    void musicSetPitch(float pitch);
    void musicSetLoop(bool loop);
    
    float musicGetVolume();
    float musicGetPitch();
    
    bool musicGetStopped();
    
    void restartActualSong();
    
private:

    sf::Music* _music;
    bool _loop;
    float _volume;
    float _pitch;
};

#endif /* MUSIC_H */

