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
    _fontTexture = new Texture("./textures/fondotexto.png");
    _textFont = new sf::Font();
    _textFont->loadFromFile("./textures/Pixeled.ttf");
    
    _mapName = "";
    
    _player = NULL;
    _eBounce = NULL;
    _eStand = NULL;
    _eChase = NULL;
    _oBox = NULL;
    _oSwitch = NULL;
    _oDoor = NULL;
    _oPowerUp = NULL;
    _oStairs = NULL;
    _oHelp=NULL;
    
    _countenemystand = 0;
    _countenemybounce = 0;
    _countenemychase = 0;
    _countbox = 0;
    _countbutton = 0;
    _countpowerup = 0;
    _countdoor = 0;
    _countstairs = 0;
    _counthelp = 0;
    
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
        case -2:
            _mapName = "./Maps/LevelC.tmx";
            break;
            
        case -1:
            _mapName = "./Maps/Level-P.tmx";
            break;
            
        case 0:
            _mapName = "./Maps/Level-0.tmx";
            break;
        
        case 1:
            _mapName = "./Maps/Level-1.tmx";
            break;
            
        case 2:
            _mapName = "./Maps/Level-2.tmx";
            break;
            
        case 3:
            _mapName = "./Maps/Level-3.tmx";
            break;
            
        case 4:
            _mapName = "./Maps/Level-4.tmx";
            break;
            
        case 5:
            _mapName = "./Maps/Level-5.tmx";
            break;
            
        case 6:
            _mapName = "./Maps/Level-6.tmx";
            break;
            
        case 7:
            _mapName = "./Maps/Level-7.tmx";
            break;
            
        default:
            _mapName = "./Maps/Level-0.tmx";
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
    _numpowerup = 0;
    _numbox = 0;
    _numbutton = 0;
    _numstairs = 0;
    _numhelp = 0;
    
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
                _numstairs++;
                break;
                
            case 238:// Help
                cout<<"Help"<<endl;
                _numhelp++;
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
    cout<<"numstairs: "<<_numstairs<<endl;
    cout<<"numpowerup: "<<_numpowerup<<endl;
    cout<<"numhelp: "<<_numhelp<<endl;
    
    _eBounce=NULL;
    _eStand=NULL;
    _eChase=NULL;
    _oBox=NULL;
    _oSwitch=NULL;
    _oDoor=NULL;
    _oPowerUp=NULL;
    _oStairs=NULL;
    _oHelp=NULL;
    
    _player = Player::Instance();
    if(_numenemybounce > 0)_eBounce = new EnemyBounce*[_numenemybounce];
    if(_numenemystand > 0)_eStand = new EnemyStand*[_numenemystand];
    if(_numenemychase > 0)_eChase = new EnemyChase*[_numenemychase];
    if(_numbox > 0)_oBox = new Box*[_numbox];
    if(_numbutton > 0)_oSwitch = new Switch*[_numbutton];
    if(_numbutton > 0)_oDoor = new Door*[_numbutton*2];
    if(_numpowerup > 0)_oPowerUp = new PowerUp*[_numpowerup];
    if(_numstairs > 0)_oStairs = new Stairs*[_numstairs];
    if(_numhelp > 0)_oHelp = new Help*[_numhelp];
    
    XMLElement *object = map->FirstChildElement("objectgroup")->FirstChildElement("object");
    for(int i=0; i<_numobjects; i++)
    {
        int gid = 0;
        int doorPos = 0;
        float oX = 0;
        float oY = 0;
        float timer = 0.0;
        float doorVel = 0.0;
        string str = "";
        XMLElement* auxDoor;
        
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
                cout<<"Player x,y: "<<oX<<", "<<oY<<endl;
                break;
            
            case 182:// EnemyBounce
                cout<<"EnemyBounce"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                str = object->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
                _eBounce[_countenemybounce] = new EnemyBounce(_enemyTexture, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(oX, oY), sf::Vector2f(1.0f, 1.0f), str);
                _countenemybounce++;
                break;
                
            case 198:// EnemyStand
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                str = object->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
                timer = object->FirstChildElement("properties")->LastChildElement("property")->FloatAttribute("value");
                _eStand[_countenemystand] = new EnemyStand(_enemyTexture, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(oX, oY), sf::Vector2f(1.0f, 1.0f), str, timer); 
                _countenemystand++;
                cout<<"EnemyStand Bieeeeeen"<<endl;
                break;
                
            case 214:// EnemyChase
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                str = object->FirstChildElement("properties")->FirstChildElement("property")->Attribute("value");
                timer = object->FirstChildElement("properties")->LastChildElement("property")->FloatAttribute("value");
                _eChase[_countenemychase] = new EnemyChase(_enemyTexture, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(oX, oY), sf::Vector2f(1.0f, 1.0f), str, timer); 
                _countenemychase++;
                cout<<"EnemyChase"<<endl;
                break;
                
            case 225:// Button
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                _oSwitch[_countbutton] = new Switch(2, oX, oY, 0.0f, false, _objectTexture, 1);
                auxDoor = object->FirstChildElement("properties")->FirstChildElement("property");
                auxDoor->QueryFloatAttribute("value", &oX);
                auxDoor = auxDoor->NextSiblingElement("property");
                auxDoor->QueryFloatAttribute("value", &oY);
                auxDoor = auxDoor->NextSiblingElement("property");
                auxDoor->QueryIntAttribute("value", &doorPos);
                auxDoor = auxDoor->NextSiblingElement("property");
                auxDoor->QueryFloatAttribute("value", &doorVel);
                auxDoor = auxDoor->NextSiblingElement("property");
                auxDoor->QueryFloatAttribute("value", &timer);
                
                cout<<"X: "<<oX<<endl;
                cout<<"Y: "<<oY<<endl;
                cout<<"pos: "<<doorPos<<endl;
                cout<<"vel: "<<doorVel<<endl;
                cout<<"timer: "<<timer<<endl;
                
                oX += 16;
                oY += 16;
                
                if(doorPos == 0)// Vertical
                {
                    _oDoor[_countdoor] = new Door(3, oX, oY, 0, false, _objectTexture, 0, timer, doorVel);
                    _countdoor++;
                    _oDoor[_countdoor] = new Door(3, oX, oY+32, 0, false, _objectTexture, 1, timer, doorVel);
                    _oSwitch[_countbutton]->setDoor(_oDoor[_countdoor-1], _oDoor[_countdoor]);
                    _countdoor++;
                }
                else // Horizontal
                {
                    _oDoor[_countdoor] = new Door(3, oX, oY-32, 0, false, _objectTexture, 2, timer, doorVel);
                    _countdoor++;
                    _oDoor[_countdoor] = new Door(3, oX, oY, 0, false, _objectTexture, 3, timer, doorVel);
                    _oSwitch[_countbutton]->setDoor(_oDoor[_countdoor-1], _oDoor[_countdoor]);
                    _countdoor++;
                }
                
                auxDoor = NULL;
                _countbutton++;
                cout<<"Button"<<endl;
                break;
                
            case 237:// NextLevel
                cout<<"NextLevel"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                doorPos = object->FirstChildElement("properties")->FirstChildElement("property")->IntAttribute("value");
                _oStairs[_countstairs] = new Stairs(5, oX, oY, 0, false, _objectTexture, 0, doorPos);
                _countstairs++;
                break;
                
            case 238:// Help
                cout<<"Help"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                doorPos = object->FirstChildElement("properties")->FirstChildElement("property")->IntAttribute("value");
                _oHelp[_counthelp] = new Help(6, oX, oY, 0, false, _objectTexture, doorPos, _textFont, _fontTexture, sf::FloatRect(0,0,0,0), sf::Vector2f(0,0));
                _counthelp++;
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
                _countpowerup++;
                break;
                
            case 254:// PowerUpGreen
                cout<<"PowerUpGreen"<<endl;
                object->QueryFloatAttribute("x", &oX);
                object->QueryFloatAttribute("y", &oY);
                oX += 16;
                oY -= 16;
                _oPowerUp[_countpowerup] = new PowerUp(4, oX, oY, 0, true, _objectTexture, 3);
                _countpowerup++;
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

void LevelFactory::levelFactoryClear()
{
    
    if(_tilesetSprite != NULL)
    {
        delete _tilesetSprite;
        _tilesetSprite = NULL;
    }
    
    if(_player != NULL)
    {
        _player->resetPlayer();
        _player = NULL;
    }
    
    if(_eBounce != NULL){
        for(int i=0; i<_numenemybounce; i++)
        {
            if(_eBounce[i] != NULL)
            {
                delete _eBounce[i];
                _eBounce[i] = NULL;
            }
        }
        delete[] _eBounce;
        _eBounce = NULL;
    }
    
    if(_eStand != NULL)
    {
        for(int i=0; i<_numenemystand; i++)
        {
            if(_eStand[i] != NULL)
            {
               delete _eStand[i];
                _eStand[i] = NULL;
            }
        }
        delete[] _eStand;
        _eStand = NULL;
    }
    
    if(_eChase != NULL)
    {
        for(int i=0; i<_numenemychase; i++)
        {
            if(_eChase[i] != NULL)
            {
                delete _eChase[i];
                _eChase[i] = NULL;
            }
        }
        delete[] _eChase;
        _eChase = NULL;
    }
    
    if(_oBox != NULL)
    {
        for(int i=0; i<_numbox; i++)
        {
            if(_oBox[i] != NULL)
            {
                delete _oBox[i];
                _oBox[i] = NULL;
            }
        }
        delete[] _oBox;
        _oBox = NULL;
    }
    
    if(_oSwitch != NULL)
    {
        for(int i=0; i<_numbutton; i++)
        {
            if(_oSwitch[i] != NULL)
            {
                delete _oSwitch[i];
                _oSwitch[i] = NULL;
            }
        }
        delete[] _oSwitch;
        _oSwitch = NULL;
    }
    
    if(_oPowerUp != NULL)
    {
    for(int i=0; i<_numpowerup; i++)
    {
        if(_oPowerUp[i] != NULL)
        {
            delete _oPowerUp[i];
            _oPowerUp[i] = NULL;
        }
    }
    delete[] _oPowerUp;
    _oPowerUp = NULL;
    }
    
    if(_oStairs != NULL)
    {
    for(int i=0; i<_numstairs; i++)
    {
        if(_oStairs[i] != NULL)
        {
            delete _oStairs[i];
            _oStairs[i] = NULL;
        }
    }
    delete[] _oStairs;
    _oStairs = NULL;
    }
    
    if(_oDoor != NULL)
    {
        delete[] _oDoor;
        _oDoor = NULL;
    }
    
    if(_oHelp != NULL)
    {
        for(int i=0; i<_numhelp;i++){
            delete _oHelp[i];
            _oHelp[i]=NULL;
        }
        
        delete[] _oHelp;
        _oHelp = NULL;
        
    }
    
    if(_tileMapSprite != NULL)
    {
        for(int l=0; l<_numlayers; l++)
        {
            for(int y=0; y<_height; y++)
            {
                for(int x=0; x<_width; x++)
                {
                    if(_tileMapSprite[l][y][x] != NULL)
                    {
                       delete _tileMapSprite[l][y][x];
                        _tileMapSprite[l][y][x] = NULL;
                    }
                }
                if(_tileMapSprite[l][y] != NULL)
                    {
                        delete[] _tileMapSprite[l][y];
                        _tileMapSprite[l][y] = NULL;
                    }
            }
            if(_tileMapSprite[l] != NULL)
            {
                delete[] _tileMapSprite[l];
                _tileMapSprite[l] = NULL;
            }
        }
        if(_tileMapSprite != NULL)
        {
            delete[] _tileMapSprite;
            _tileMapSprite = NULL;
        }
    }
    
    if(_tileMap != NULL)
    {
        for(int l=0; l<_numlayers; l++)
        {
            for(int y=0; y<_height; y++)
            {
                if(_tileMap[l][y] != NULL)
                    {
                        delete[] _tileMap[l][y];
                        _tileMap[l][y] = NULL;
                    }
            }
            if(_tileMap[l] != NULL)
            {
                delete[] _tileMap[l];
                _tileMap[l] = NULL;
            }
        }

        if(_tileMap != NULL)
        {
            delete[] _tileMap;
            _tileMap = NULL;
        }
    }
    
    if(_tilesetTexture != NULL)
    {
        delete _tilesetTexture;
        _tilesetTexture = NULL;
    }
    
    if(_playerTexture != NULL)
    {
        delete _playerTexture;
        _playerTexture = NULL;
    }
    
    if(_enemyTexture != NULL)
    {
        delete _enemyTexture;
        _enemyTexture = NULL;
    }
    
    if(_objectTexture != NULL)
    {
        delete _objectTexture;
        _objectTexture = NULL;
    }
    
    if(_fontTexture != NULL)
    {
        delete _fontTexture;
        _fontTexture = NULL;
    }
    
    if(_textFont != NULL)
    {
        delete _textFont;
        _textFont = NULL;
    }
    
    
    _numMap = 0;
    _mapName = "";
    _numlayers = 0;
    _numobjects = 0;
    
    _numenemystand = 0;
    _numenemybounce = 0;
    _numenemychase = 0;
    _numbox = 0;
    _numbutton = 0;
    _numpowerup = 0;
    _numstairs = 0;
    
    _countenemystand = 0;
    _countenemybounce = 0;
    _countenemychase = 0;
    _countbox = 0;
    _countbutton = 0;
    _countdoor = 0;
    _countpowerup = 0;
    _countstairs = 0;
    
    _height = 0;
    _width = 0;
    _tileheight = 0;
    _tilewidth = 0;
    _numtiles = 0;
    
    _pinstance = 0;
    
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

EnemyChase** LevelFactory::getLevelFactoryEnemyChase()
{
    return _eChase;
}

EnemyStand** LevelFactory::getLevelFactoryEnemyStand()
{
    return _eStand;
}

EnemyBounce** LevelFactory::getLevelFactoryEnemyBounce()
{
    return _eBounce;
}

Switch** LevelFactory::getLevelFactorySwitch()
{
    return _oSwitch;
}

Door** LevelFactory::getLevelFactoryDoor()
{
    return _oDoor;
}

Help** LevelFactory::getLevelFactoryHelp()
{
    return _oHelp;
}

Stairs**  LevelFactory::getLevelFactoryStairs()
{
    return _oStairs;
}

Texture* LevelFactory::getTileSetTexture()
{
    return _tilesetTexture;
}

Texture* LevelFactory::getPlayerTexture()
{
    return _playerTexture;
}

Texture* LevelFactory::getEnemyTexture()
{
    return _enemyTexture;
}

Texture* LevelFactory::getObjectTexture()
{
    return _objectTexture;
}
    
int LevelFactory::getEnemyStandnumber()
{
    return _numenemystand;
}

int LevelFactory::getEnemyBounceNumber()
{
    return _numenemybounce;
}

int LevelFactory::getEnemyChaseNumber()
{
    return _numenemychase;
}

int LevelFactory::getBoxNumber()
{
    return _numbox;
}

int LevelFactory::getSwitchNumber()
{
    return _numbutton;
}

int LevelFactory::getDoorNumber()
{
    return _numbutton*2;
}

int LevelFactory::getPowerUpNumber()
{
    return _numpowerup;
}

int LevelFactory::getStairsNumber()
{
    return _numstairs;
}

int LevelFactory::getHelpNumber()
{
    return _numhelp;
}
