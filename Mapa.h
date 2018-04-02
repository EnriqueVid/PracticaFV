/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.h
 * Author: newman
 *
 * Created on 24 de marzo de 2018, 19:12
 */
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include "Collision.h"
#include "tinyxml2.h"


using namespace std;
using namespace tinyxml2;

#ifndef MAPA_H
#define MAPA_H



class Mapa {
public:
    Mapa(int numMap);
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void borrarTileMap();
    void borrarMapa();
    void dibujar(sf::RenderWindow *window);
    int getCasilla(float x, float y);
    
    
private:
    sf::Sprite ****_tileMapSprite;
    sf::Texture _tilesetTexture;
    sf::IntRect *_tilesetSprite;
    int ***_tileMap;
    int _numlayers;
    int _height;
    int _width;
    int _tileheight;
    int _tilewidth;
    int _numtiles;
};

#endif /* MAPA_H */

