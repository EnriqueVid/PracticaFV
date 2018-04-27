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
    _tilesetTexture = new Texture("./textures/TileSet.png");
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
    
    XMLElement* aux = map->FirstChildElement("tileset");
    string auxn= aux->Attribute("source");
    string auxname = "./Maps/";
    auxname.append(auxn);
    tileDoc.LoadFile(auxname.data());
    XMLElement* dsa = tileDoc.FirstChildElement("tileset");
    XMLElement* asd = tileDoc.FirstChildElement("tileset")->FirstChildElement("image");
    const char* tilePath = asd->Attribute("source");
    
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
        
        //cout<<"TilseSetSprite ["<<i<<"] = "<<_tilesetSprite[i].top<<", "<<_tilesetSprite[i].left<<", "<<_tilesetSprite[i].height<<", "<<_tilesetSprite[i].width<<endl;
    }
    
    string tilePathAux = tilePath;
    cout<<tilePathAux<<endl;
    _tilesetTexture->textureLoadFromFile(tilePathAux);
    
    _numlayers = 0;
    
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
    
    _tileMapSprite = new Sprite***[_numlayers];
    for (int l=0; l<_numlayers; l++)
    {
        _tileMapSprite[l] = new Sprite**[_height];
    }
    for (int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            _tileMapSprite[l][y] = new Sprite*[_width];
            for(int x=0; x<_width; x++){
            
                _tileMapSprite[l][y][x] = new Sprite();
            }
        }
    }
    
    
            
    XMLElement** data = new XMLElement*[_numlayers]; 
    cout<<"pipo"<<endl;
    XMLElement* auxd = map->FirstChildElement("layer");
    data[0] = auxd->FirstChildElement("data")->FirstChildElement("tile");
    cout<<"pipo"<<endl;
    for (int i=1; i<_numlayers; i++)
    {
        cout<<"pipo"<<endl;
        data[i] = auxd->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
        
        if(i+1<_numlayers) auxd = auxd->NextSiblingElement("layer");
    }
    
    
    
    //---------------------------------------SI ALGO EXPLOTA ES CULPA DE ESTO
    for (int l=0; l<_numlayers; l++)
    {
        for(int y=0; y<_height; y++)
        {
            for(int x=0; x<_width; x++)
            {
                data[l]->QueryIntAttribute("gid", &_tileMap[l][y][x]);
                data[l] = data[l]->NextSiblingElement("tile");
                cout<<_tileMap[l][y][x]<<endl;
            }
        }
        cout<<"================"<<endl;
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
                    _tileMapSprite[l][y][x] = new Sprite(_tilesetTexture, _tilesetSprite[gid]);
                    _tileMapSprite[l][y][x]->setSpritePosition(sf::Vector2f(x*_tilewidth, y*_tileheight));
                }
                else
                {
                    _tileMapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}


Sprite**** LevelFactory::getLevelFactoryTileMapSprite()
{
    return _tileMapSprite;
}
int LevelFactory::getLevelFactoryNumLayers()
{
    return _numlayers;
}
int LevelFactory::getLevelFactoryWidth()
{
    return _width;
}
int LevelFactory::getLevelFactoryHeight()
{
    return _height;
}

