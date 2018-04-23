/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelFactory.h
 * Author: newman
 *
 * Created on 22 de abril de 2018, 23:19
 */

#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <math.h>
#include "tinyxml2.h"
#include "Sprite.h"
#include "Texture.h"

using namespace tinyxml2;

class LevelFactory {

public:
    static LevelFactory* Instance();
    void setLevelFactoryStates(int i);
    Sprite**** getLevelFactoryTileMapSprite();
    int getLevelFactoryNumLayers();
    int getLevelFactoryWidth();
    int getLevelFactoryHeight();
    
protected:
    LevelFactory();
    LevelFactory(const LevelFactory& orig);
    virtual ~LevelFactory();
    
    void levelFactoryMapSelector();
    void levelFactoryMapCreator();
    
private:
    static LevelFactory* _pinstance;
    int _numMap;
    Texture* _tilesetTexture;
    Sprite ****_tileMapSprite;
    sf::IntRect *_tilesetSprite;
    int ***_tileMap;
    string _mapName;
    
    int _numlayers;
    int _height;
    int _width;
    int _tileheight;
    int _tilewidth;
    int _numtiles;
    
    
};

#endif /* LEVELFACTORY_H */

