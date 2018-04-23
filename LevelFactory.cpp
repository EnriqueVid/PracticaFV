/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelFactory.cpp
 * Author: newman
 * 
 * Created on 22 de abril de 2018, 23:19
 */

#include "LevelFactory.h"



LevelFactory* LevelFactory::_pinstance = 0;
LevelFactory* LevelFactory::Instance()
{
    if(_pinstance == 0)
    {
        _pinstance = new LevelFactory;
    }
    return _pinstance;
}

LevelFactory::LevelFactory() 
{
    _numMap = -1;
    _tilesetTexture = new Texture();
    _tilesetTexture->textureLoadFromFile("./textures/TileSet.png");
    _mapName = "";
    
}

LevelFactory::LevelFactory(const LevelFactory& orig) 
{
     
}

LevelFactory::~LevelFactory() 
{
    
}

void LevelFactory::setLevelFactoryStates(int i)
{
    _numMap = i;
    levelFactoryMapSelector();
    levelFactoryMapCreator();
}

void LevelFactory::levelFactoryMapSelector()
{
    switch(_numMap)
    {
        case 0:
            _mapName = "./Maps/Level-0.tmx";
            break;
            
        default:
            _mapName = "";
    }
}

void LevelFactory::levelFactoryMapCreator()
{
    XMLDocument doc;
    XMLDocument tileDoc;
    doc.LoadFile(_mapName.data());
    
    XMLElement* map = doc.FirstChildElement("map");
    
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tilewidth);
    map->QueryIntAttribute("tileheight", &_tileheight);
    
    cout<<"width: "<<_width<<endl;
    cout<<"height: "<<_height<<endl;
    cout<<"tilewidth: "<<_tilewidth<<endl;
    cout<<"tileheight: "<<_tileheight<<endl;
}

