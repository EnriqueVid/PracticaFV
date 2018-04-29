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
#include "Player.h"
#include "EnemyBounce.h"
#include "EnemyChase.h"
#include "EnemyStand.h"
#include "Box.h"
#include "Switch.h"
#include "Door.h"
#include "PowerUp.h"

using namespace tinyxml2;

class LevelFactory {

public:
    static LevelFactory* Instance();
    void setLevelFactoryStates(int i);
    
    Sprite**** getLevelFactoryTileMapSprite();
    int** getLevelFactoryCollisionMap();
    int getLevelFactoryNumLayers();
    int getLevelFactoryWidth();
    int getLevelFactoryHeight();
    
    Box** getLevelFactoryBox();
    
    
    
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
    Texture* _playerTexture;
    Texture* _enemyTexture;
    Texture* _objectTexture;
    Sprite ****_tileMapSprite;
    sf::IntRect *_tilesetSprite;
    int ***_tileMap;
    string _mapName;
    
    Player* _player;
    EnemyBounce** _eBounce;
    EnemyStand** _eStand;
    EnemyChase** _eChase;
    Box** _oBox;
    Switch** _oSwitch;
    Door** _oDoor;
    PowerUp** _oPowerUp;
    
    int _numlayers;
    int _numobjects;
    
    int _numenemystand;
    int _numenemybounce;
    int _numenemychase;
    int _numbox;
    int _numbutton;
    int _numpowerup;
    
    int _height;
    int _width;
    int _tileheight;
    int _tilewidth;
    int _numtiles;
    
    
};

#endif /* LEVELFACTORY_H */

