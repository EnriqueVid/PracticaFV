/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.cpp
 * Author: newman
 * 
 * Created on 24 de marzo de 2018, 19:12
 */

#include "Mapa.h"
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include "Collision.h"
#include "tinyxml2.h"


using namespace std;
using namespace tinyxml2;

Mapa::Mapa(int numMap) 
{
    _numlayers = 0;
    _height = 0;
    _width = 0;
    _tileheight = 0;
    _tilewidth = 0;
    _numtiles = 0;
    
    XMLDocument doc;
    XMLDocument tileDoc;
    doc.LoadFile("mapaPruebas.tmx");
    
    
    XMLElement* map = doc.FirstChildElement("map");
    
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tilewidth);
    map->QueryIntAttribute("tileheight", &_tileheight);
    
    cout<<"width: "<<_width<<endl;
    cout<<"height: "<<_height<<endl;
    cout<<"tilewidth: "<<_tilewidth<<endl;
    cout<<"tileheight: "<<_tileheight<<endl;
    
    XMLElement *aux = map->FirstChildElement("tileset");
    const char *auxname = aux->Attribute("source");
    
    tileDoc.LoadFile(auxname);
    XMLElement *dsa = tileDoc.FirstChildElement("tileset");
    XMLElement *asd = tileDoc.FirstChildElement("tileset")->FirstChildElement("image");
    const char *tilePath = asd->Attribute("source");
    
    dsa->QueryIntAttribute("tilecount", &_numtiles);
    
    cout<<"TileSheet: "<<tilePath<<endl;
    cout<<"TileCount: "<<_numtiles<<endl;
    
    _tilesetSprite = new sf::IntRect[_numtiles];
    
    for(int i=0; i<_numtiles; i++)
    {
        int num =sqrt(_numtiles);
        int x = 0;
        int y = 0;
        int aux = i;
        _tilesetSprite[i].height = _tileheight;
        _tilesetSprite[i].width = _tilewidth;
        cout<<"aux: "<<aux<<endl;
        while(aux!=0)
        {
            if(aux >= num)
            {
                y++;
                aux -= num;
            }
            else
            {
                x = aux;
                aux = 0;
            }
        }
        _tilesetSprite[i].left = _tilewidth*x;
        _tilesetSprite[i].top = _tileheight*y;
        
        cout<<"TilseSetSprite ["<<i<<"] = "<<_tilesetSprite[i].top<<", "<<_tilesetSprite[i].left<<", "<<_tilesetSprite[i].height<<", "<<_tilesetSprite[i].width<<endl;
    }
    
    _tilesetTexture.loadFromFile(tilePath);
    
    XMLElement *layer = map->FirstChildElement("layer");
    while(layer)
    {
        _numlayers++;
        layer = layer->NextSiblingElement("layer");
    }
    
    cout<<"numLayers: "<<_numlayers<<endl;
    
    _tileMap = new int**[_numlayers];
    for(int i=0; i<_numlayers; i++)
    {
        _tileMap[i] = new int*[_height];
    }
    for(int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            _tileMap[l][y] = new int[_width];
        }
    }
    
    _tileMapSprite = new sf::Sprite***[_numlayers];
    for (int l=0; l<_numlayers; l++)
    {
        _tileMapSprite[l] = new sf::Sprite**[_height];
    }
    for (int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            _tileMapSprite[l][y] = new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
            
                _tileMapSprite[l][y][x] = new sf::Sprite();
            }
        }
    }
    
    
    
    XMLElement *data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    
    
    //---------------------------------------SI ALGO EXPLOTA ES CULPA DE ESTO
    for (int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            for(int x=0; x<_width; x++)
            {
                data->QueryIntAttribute("gid", &_tileMap[l][y][x]);
                XMLElement *aux = data->NextSiblingElement("tile");
                data = aux;
            }
        }
    }
    //---------------------------------------
    
    for (int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            for(int x=0; x<_width; x++)
            {
                cout<<_tileMap[l][y][x]-1;
                
            }
            cout<<endl;
            
        }
        cout<<"-------------"<<endl;
    }
    
    for(int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            for(int x=0; x<_width; x++)
            {
                int gid = _tileMap[l][y][x]-1;
                
                if(gid>=_numtiles)
                {
                    cout<<"ERROR: gid at (l, y, x) = ("<< l <<", "<< y <<", "<< x <<") :"<< gid <<" fuera del rango del tileset ("<< _numtiles <<")"<<endl; 
                }
                else if(gid>=0)
                {
                    _tileMapSprite[l][y][x] = new sf::Sprite(_tilesetTexture, _tilesetSprite[gid]);
                    _tileMapSprite[l][y][x]->setPosition(x*_tilewidth, y*_tileheight);
                }
                else
                {
                    _tileMapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
}

void Mapa::dibujar(sf::RenderWindow *window)
{
    for(int y=0; y<_height; y++)
    {
        for(int x=0; x<_width; x++)
        {
            if(_tileMapSprite[0][y][x] != NULL)
            {
                window->draw(*(_tileMapSprite[0][y][x]));
            }
        }
    }
}

int Mapa::getCasilla(float x, float y)
{
    int resul = -1;
    
    int cX = x/32;
    int cY = y/32;
    
    //cout<<_tileMap[0][cY][cX]-1<<endl; 
    resul = _tileMap[0][cY][cX]-1;

    return resul;
}

