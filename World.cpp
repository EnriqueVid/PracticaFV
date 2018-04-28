/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.cpp
 * Author: calros
 * 
 * Created on 26 de abril de 2018, 19:30
 */

#include "World.h"
#include "Enemy.h"
#include "EnemyBounce.h"
#include "Input.h"


World* World::_pinstance = 0;
World* World::Instance()
{
    if(_pinstance == 0)
    {
        _pinstance = new World;
    }
    return _pinstance;
}

World::World() 
{
    _box=NULL;
    _powerUp=NULL;
    _door=NULL;
    _texture=NULL;
    _player=NULL;
    _powerUp=NULL;
    _switch=NULL;
    //_renderWindow=NULL;
    _map=NULL;
    _message=NULL;
    _enemyBounce=NULL;
    _enemyChase=NULL;
    _enemyStand=NULL;
    _clock=NULL;
    cout <<"World created."<<endl;
}

void World::buildWorld(int lvlNumber)
{
    
    
    buildTestObjects();
    
    //LevelFactory::Instance();
    
    //_box = lvl.getBox
    //_door = lvl.getDoor...    
}

void World::buildTestObjects()
{
    
    _clock = new Clock();
    
    _input = Input::Instance();
    
    cout <<" Build test objects."<<endl;
    
    
    int x;
    
    LevelFactory* lf = LevelFactory::Instance();
    lf->setLevelFactoryStates(0);
    
    _map = lf->getLevelFactoryTileMapSprite();
    _mapWidth = lf->getLevelFactoryWidth();
    _mapHeight = lf->getLevelFactoryHeight();
    _mapLayers = lf->getLevelFactoryNumLayers();

    _textureNumber=4;
    _texture = new Texture*[_textureNumber];
    
    std::string path = "textures/PlayerTiles.png";
    std::string pathBullet = "textures/BulletTiles.png";
    std::string pathObject = "textures/ObjectTiles.png";
    std::string pathButton = "textures/TexturaBotonTemporal.png";
    
    
    _texture[0] = new Texture(path);
    _texture[1] = new Texture(pathBullet);
    _texture[2] = new Texture(pathObject);
    _texture[3] = new Texture(pathButton);
    
    sf::IntRect* square = new sf::IntRect(0,0,32,32);
    
    _player = Player::Instance();
    _player->setPlayer(_texture[0], square,sf::Vector2f(16,16), sf::Vector2f(200.0f,200.0f), sf::Vector2f(1,1));
    _player->setColor(sf::Color::Cyan);
    
    _boxNumber = 3;
    _box = new Box*[_boxNumber];
    
    for(x=0;x<_boxNumber;x++)
    {
        _box[x] = new Box(1, 160.0, 360.0, 0.0, false, _texture[2],
                        1, 2, 3.0);
    }

    _doorNumber = 2;
    _door = new Door*[_doorNumber];
    _door[0] = new Door(1, 352.0, 320.0+64, 0.0, false, _texture[2],
                            0, 4.5, 1.0);
    _door[1] = new Door(1, 352.0, 352.0+64, 0.0, false, _texture[2],
                            1, 4.5, 1.0);
    
    _switchNumber = 1;
    _switch = new Switch*[_switchNumber];
    _switch[0] = new Switch(1, 160.0, 200.0, 0.0, false, _texture[3],
                                1);
}

void World::update()
{
    
    //UPDATE DE TODOS LOS OBJETOS

if(_player!=NULL)_player->input();

    
    if(_clock->getClockAsSeconds()>=float(UPS)){
        
        _input->inputInput();

        if(_input->inputCheck(0)) cout<<"UP"<<endl;
        if(_input->inputCheck(1)) cout<<"DOWN"<<endl;
        if(_input->inputCheck(2)) cout<<"LEFT"<<endl;
        if(_input->inputCheck(3)) cout<<"RIGHT"<<endl;
        //if(_input->inputCheck(10)) _renderWindow->windowClose();
        
        if(_player!=NULL){
            _player->update();
            
        }
        
        int x;
        
        if(_box!=NULL)
        {
            for(x=0;x<_boxNumber;x++)
            {
                if(_box[x]!=NULL)
                {
                    _box[x]->update();
                }
            }
        }

        if(_powerUp!=NULL)
        {
            for(x=0;x<_powerUpNumber;x++)
            {
                if(_powerUp[x]!=NULL)
                {
                    _powerUp[x]->update();
                }
            }
        }

        if(_door!=NULL)
        {
            for(x=0;x<_doorNumber;x++)
            {
                if(_door[x]!=NULL)
                {
                    _door[x]->update();
                }
            }
        }

        if(_switch!=NULL)
        {
            for(x=0;x<_switchNumber;x++)
            {
                if(_switch[x]!=NULL)
                {
                    _switch[x]->update();
                }
            }
        }


        if(_enemyBounce!=NULL)
        {
            for(x=0;x<_enemyBounceNumber;x++)
            {
                if(_enemyBounce[x]!=NULL)
                {
                    //_enemyBounce[x]->update();
                }
            }
        }

        if(_enemyChase!=NULL)
        {
            for(x=0;x<_enemyChaseNumber;x++)
            {
                if(_enemyChase[x]!=NULL)
                {
                    //_enemyChase[x]->update();
                }
            }
        }

        /*
         if(_enemyStand!=NULL)
          {
        for(x=0;x<_enemyStandNumber;x++)
        {
            if(_enemyStand[x]!=NULL)
          {

                 }
        }
         }
        */

        checkCollisions();

            _clock->clockRestart();    
    }
        _percentTick=_clock->getClockAsSeconds()/float(UPS);        
    
}

//Metodo usado para corregir la posicion de los objetos tras todos sus updates, para comprobar que nadie se mete
//donde no le corresponde.
//Tambien activa determinados eventos en estos objetos en caso de haber colisiones.
void World::checkCollisions()
{
    
}

//Metodo usado para calcular el maximo desplazamiento de un sprite frente a otro.
sf::Vector2f World::calculateMaxPosition(Sprite* obj1, Situation* previousSituation1, Situation* actualSituation1 , Sprite* obj2)
{
    return sf::Vector2f(0.0f,0.0f);
}

void World::render(RenderWindow* _renderWindow)
{
    //RENDER DE TODOS LOS OBJETOS
        
    
    _renderWindow->updatePercentTick(_percentTick);

        
    int x;
    

    for (int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            if(_map[1][y][x] != NULL)
            _renderWindow->windowDraw(_map[1][y][x]);
        }
    }
    
    if(_player!=NULL){
        _renderWindow->windowInterpolateDraw(_player->getPlayer(),_player->getPreviousSituation(),_player->getActualSituation());
    }

    
    if(_box!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
                _renderWindow->windowInterpolateDraw(_box[x]->getSprite(),_box[x]->getPreviousSituation(),_box[x]->getActualSituation());
            }
        }
    }
    
    if(_powerUp!=NULL)
    {
        for(x=0;x<_powerUpNumber;x++)
        {
            if(_powerUp[x]!=NULL)
            {
                _renderWindow->windowDraw(_powerUp[x]->getSprite());
            }
        }
    }

    if(_door!=NULL)
    {
        for(x=0;x<_doorNumber;x++)
        {
            if(_door[x]!=NULL)
            {
                _renderWindow->windowInterpolateDraw(_door[x]->getSprite(),_door[x]->getPreviousSituation(),_door[x]->getActualSituation());
            }
        }
    }

    if(_switch!=NULL)
    {
        for(x=0;x<_switchNumber;x++)
        {
            if(_switch[x]!=NULL)
            {
                _renderWindow->windowDraw(_switch[x]->getSprite());
            }
        }
    }

    if(_message!=NULL)
    {
        for(x=0;x<_messageNumber;x++)
        {
            if(_message[x]!=NULL)
            {
                _renderWindow->windowDraw(_message[x]);
            }
        }
    }

    if(_enemyBounce!=NULL)
    {
        for(x=0;x<_enemyBounceNumber;x++)
        {
            if(_enemyBounce[x]!=NULL)
            {
                _renderWindow->windowInterpolateDraw(_enemyBounce[x]->getEnemySprite(),_enemyBounce[x]->getEnemyPreviousSituation(),_enemyBounce[x]->getEnemyActualSituation());
            }
        }
    }

    if(_enemyChase!=NULL)
    {
        for(x=0;x<_enemyChaseNumber;x++)
        {
            if(_enemyChase[x]!=NULL)
            {
                _renderWindow->windowInterpolateDraw(_enemyChase[x]->getEnemySprite(),_enemyChase[x]->getEnemyPreviousSituation(),_enemyChase[x]->getEnemyActualSituation());
            }
        }
    }
    
    /*
     if(_enemyStand!=NULL)
     * {
    for(x=0;x<_enemyStandNumber;x++)
    {
        if(_enemyStand[x]!=NULL)
      {
            _renderWindow->windowDraw(_enemyStandNumber[x]->getEnemySprite());
        }
    }
     }
    */
    
    for (int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            if(_map[2][y][x] != NULL)
            _renderWindow->windowDraw(_map[2][y][x]);
        }
    }
}

World::World(const World& orig)
{
    
}

World::~World()
{
    //DELETE DE TODOS LOS PUNTEROS
    int x=0;
    int y=0;
    int z=0;
    
    if(_texture!=NULL)
    {
        for(x=0;x<_textureNumber;x++)
        {
            if(_texture[x]!=NULL)
            {
                delete _texture[x];
                _texture[x]=NULL;
            }
        }
        delete[] _texture;
        _texture=NULL;
    }

    if(_box!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
                delete _box[x];
                _box[x]=NULL;
            }
        }
        delete[] _box;
        _box=NULL;
    }
    
    if(_powerUp!=NULL)
    {
        for(x=0;x<_powerUpNumber;x++)
        {
            if(_powerUp[x]!=NULL)
            {
                delete _powerUp[x];
                _powerUp[x]=NULL;
            }
        }
        delete[] _powerUp;
        _powerUp=NULL;
    }

    if(_door!=NULL)
    {
        for(x=0;x<_doorNumber;x++)
        {
            if(_door[x]!=NULL)
            {
                delete _door[x];
                _door[x]=NULL;
            }
        }
        delete[] _door;
        _door=NULL;
    }

    if(_switch!=NULL)
    {
        for(x=0;x<_switchNumber;x++)
        {
            if(_switch[x]!=NULL)
            {
                delete _switch[x];
                _switch[x]=NULL;
            }
        }
        delete[] _switch;
        _switch=NULL;
    }


    if(_enemyBounce!=NULL)
    {
        for(x=0;x<_enemyBounceNumber;x++)
        {
            if(_enemyBounce[x]!=NULL)
            {
                delete _enemyBounce[x];
                _enemyBounce[x]=NULL;
            }
        }
        delete[] _enemyBounce;
        _enemyBounce=NULL;
    }

    if(_enemyChase!=NULL)
    {
        for(x=0;x<_enemyChaseNumber;x++)
        {
            if(_enemyChase[x]!=NULL)
            {
                delete _enemyChase[x];
                _enemyChase[x]=NULL;
            }
        }
        delete[] _enemyChase;
        _enemyChase=NULL;
    }
    
    if(_enemyStand!=NULL)
    {
        for(x=0;x<_enemyStandNumber;x++)
        {
            if(_enemyStand[x]!=NULL)
            {
                delete _enemyStand[x];
                _enemyStand[x]=NULL;
            }
        }
        delete[] _enemyStand;
        _enemyStand=NULL;
    }
    
    
    if(_map!=NULL){
        for(x=0;x<_mapLayers;x++)
        {
            if(_map[x]!=NULL){
                for(y=0;y<_mapHeight;y++)
                {
                    if(_map[x][y]!=NULL){
                        for(z=0;z<_mapWidth;z++)
                        {
                            if(_map[x][y][z]!=NULL){
                                delete _map[x][y][z];
                                _map[x][y][z]=NULL;
                            }
                        }
                        delete[] _map[x][y];
                        _map[x][y]=NULL;
                    }
                }
                delete[] _map[x];
                _map[x]=NULL;
            }
        }
        delete _map;
        _map=NULL;
    }
    
    /*
    if(_player!=NULL){
        delete _player; //??????????????????
        _player=NULL;
    }*/
    
    if(_pinstance!=NULL){
        delete _pinstance; //??????
        _pinstance=NULL;
    }
    
    delete _clock;
    _clock=NULL;

}

