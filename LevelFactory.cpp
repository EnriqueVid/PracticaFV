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
    _playerTexture = new Texture("./textures/PlayerTiles.png");
    _enemyTexture = new Texture("./textures/EnemyTiles.png");
    _objectTexture = new Texture("./textures/ObjectTiles.png");
    
    _mapName = "";
    
    _player = NULL;
    _eBounce = NULL;
    _eStand = NULL;
    _eChase = NULL;
    _oBox = NULL;
    _oSwitch = NULL;
    _oDoor = NULL;
    _oPowerUp = NULL;
    
    _countenemystand = 0;
    _countenemybounce = 0;
    _countenemychase = 0;
    _countbox = 0;
    _countbutton = 0;
    _countpowerup = 0;
    
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
        //cout<<"aux: "<<aux<<endl;
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
    XMLElement* auxd = map->FirstChildElement("layer");
    data[0] = auxd->FirstChildElement("data")->FirstChildElement("tile");
    for (int i=1; i<_numlayers; i++)
    {
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
                //cout<<_tileMap[l][y][x]<<endl;
            }
        }
        //cout<<"================"<<endl;
    }
    //---------------------------------------
    /*
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
    */
    
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
    
    _numobjects = 0;
    _numenemystand = 0;
    _numenemybounce = 0;
    _numenemychase = 0;
    _numbox = 0;
    _numbutton = 0;
    
    XMLElement *obj = map->FirstChildElement("objectgroup")->FirstChildElement("object");
    while(obj)
    {
        _numobjects++;
        int o = 0;
        obj->QueryIntAttribute("gid", &o);
        
        switch(o)
        {
            case 161://Player
                cout<<"Player"<<endl;
                break;
            
            case 182:// EnemyBounce
                _numenemybounce++;
                cout<<"EnemyBounce"<<endl;
                break;
                
            case 198:// EnemyStand
                _numenemystand++;
                cout<<"EnemyStand"<<endl;
                break;
                
            case 214:// EnemyChase
                _numenemychase++;
                cout<<"EnemyChase"<<endl;
                break;
                
            case 225:// Button
                _numbutton++;
                cout<<"Button"<<endl;
                break;
                
            case 237:// NextLevel
                cout<<"NextLevel"<<endl;
                break;
                
            case 238:// Help
                cout<<"Help"<<endl;
                break;
                
            case 239:// TextScript
                cout<<"TextScript"<<endl;
                break;
                
            case 253:// PowerUpBlue
                _numpowerup++;
                cout<<"PowerUpBlue"<<endl;
                break;
                
            case 254:// PowerUpGreen
                cout<<"PowerUpGreen"<<endl;
                _numpowerup++;
                break;
                
            case 255:// PowerUpRed
                _numpowerup++;
                cout<<"PowerUpRed"<<endl;
                break;
            
            case 256:// Box
                _numbox++;
                cout<<"Box"<<endl;
                break;
             
        }
        
        obj = obj->NextSiblingElement("object");
        
    }
    
    cout<<"objects: "<<_numobjects<<endl;
    cout<<"numenemystand: "<<_numenemystand<<endl;
    cout<<"numenemybounce: "<<_numenemybounce<<endl;
    cout<<"numenemychase: "<<_numenemychase<<endl;
    cout<<"numbox: "<<_numbox<<endl;
    cout<<"numbutton: "<<_numbutton<<endl;
    
    _player = Player::Instance();
    if(_numenemybounce > 0)_eBounce = new EnemyBounce*[_numenemybounce];
    if(_numenemystand > 0)_eStand = new EnemyStand*[_numenemystand];
    if(_numenemychase > 0)_eChase = new EnemyChase*[_numenemychase];
    if(_numbox > 0)_oBox = new Box*[_numbox];
    if(_numbutton > 0)_oSwitch = new Switch*[_numbutton];
    if(_numbutton > 0)_oDoor = new Door*[_numbutton*2];
    if(_numpowerup > 0)_oPowerUp = new PowerUp*[_numpowerup];
    
    XMLElement *object = map->FirstChildElement("objectgroup")->FirstChildElement("object");
    for(int i=0; i<_numobjects; i++)
    {
        int gid = 0;
        int count = 0;
        float oX = 0;
        float oY = 0;
        string str = "";
        object->QueryIntAttribute("gid", &gid);
        sf::IntRect* rect;
        
        switch(gid)
        {
            case 161://Player
                cout<<"Player"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                rect = new sf::IntRect(0, 0, 32, 32);
                _player->setPlayer(_playerTexture, rect, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(oX, oY), sf::Vector2f(1.0f, 1.0f));
                break;
            
            case 182:// EnemyBounce
                cout<<"EnemyBounce"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                rect = new sf::IntRect(0, 0, 32, 32);
                str = object->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
                //_eBounce[_countenemybounce] = new EnemyBounce();
                _countenemybounce++;
                break;
                
            case 198:// EnemyStand
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                rect = new sf::IntRect(0, 0, 32, 32);
                str = object->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
                _eStand[_countenemystand] = new EnemyStand(_enemyTexture, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(oX, oY), sf::Vector2f(1.0f, 1.0f), str, 5.0f); 
                cout<<"EnemyStand Bieeeeeen"<<endl;
                break;
                
            case 214:// EnemyChase
                _numenemychase++;
                cout<<"EnemyChase"<<endl;
                break;
                
            case 225:// Button
                _numbutton++;
                cout<<"Button"<<endl;
                break;
                
            case 237:// NextLevel
                cout<<"NextLevel"<<endl;
                break;
                
            case 238:// Help
                cout<<"Help"<<endl;
                break;
                
            case 239:// TextScript
                cout<<"TextScript"<<endl;
                break;
                
            case 253:// PowerUpBlue
                cout<<"PowerUpBlue"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                _oPowerUp[_countpowerup] = new PowerUp(4, oX, oY, 0, true, _objectTexture, 2);
                break;
                
            case 254:// PowerUpGreen
                cout<<"PowerUpGreen"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                _oPowerUp[_countpowerup] = new PowerUp(4, oX, oY, 0, true, _objectTexture, 3);
                break;
                
            case 255:// PowerUpRed
                cout<<"PowerUpRed"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                _oPowerUp[_countpowerup] = new PowerUp(4, oX, oY, 0, true, _objectTexture, 1);
                _countpowerup++;
                break;
            
            case 256:// Box
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                rect = new sf::IntRect(0, 0, 32, 32);
                _oBox[_countbox] = new Box(1, oX, oY, 0, true, _objectTexture, 1, 5, 16);
                cout<<"Box"<<endl;
                _countbox++;
                break;
             
        }
        
        object = object->NextSiblingElement("object");
        
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

int** LevelFactory::getLevelFactoryCollisionMap()
{
    return _tileMap[0];
}

Box** LevelFactory::getLevelFactoryBox()
{
    return _oBox;
}

PowerUp** LevelFactory::getLevelFactoryPowerUp()
{
    return _oPowerUp;
}

