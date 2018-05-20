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
#include "Bullet.h"
#include "Hud.h"
#include "Stairs.h"


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
    _help=NULL;
    _enemyBounce=NULL;
    _enemyChase=NULL;
    _enemyStand=NULL;
    _clock=NULL;
    _levelFactory = NULL;
    _bullet=NULL;
    
    _collisionMap=NULL;
    _advancedCollisionMap=NULL;
    
    _HUD=NULL;
    _stairs=NULL;
    
    _destroytheworld = false;
    _nextLevel = false;
    _nextLevelCount = 0;
    _levelDone = false;
    cout <<"World created."<<endl;
}

void World::buildWorld(int lvlNumber)
{
    //Playing music
    SoundManager* soundmanager = SoundManager::Instance();
    soundmanager->playMusic(0);
    //end music
        
    //buildTestObjects();
    
    _levelFactory = LevelFactory::Instance();
    _levelFactory->setLevelFactoryStates(lvlNumber);
    
    _mapWidth = _levelFactory->getLevelFactoryWidth();
    _mapHeight = _levelFactory->getLevelFactoryHeight();
    _mapLayers = _levelFactory->getLevelFactoryNumLayers();
    
    _collisionMap = _levelFactory->getLevelFactoryCollisionMap();
    _map = _levelFactory->getLevelFactoryTileMapSprite();
    
    if(_clock != NULL) delete _clock;
    _clock = new Clock();
    _input = Input::Instance();
    
    _player = Player::Instance();
    
    _textureNumber = 4;
    _texture = new Texture*[4];
    _texture[0] = _levelFactory->getPlayerTexture();
    _texture[1] = _levelFactory->getTileSetTexture();
    _texture[2] = _levelFactory->getObjectTexture();
    _texture[3] = _levelFactory->getEnemyTexture();
     
    
    _boxNumber = _levelFactory->getBoxNumber();
    _doorNumber = _levelFactory->getDoorNumber();
    _powerUpNumber = _levelFactory->getPowerUpNumber();
    _switchNumber = _levelFactory->getSwitchNumber();
    _helpNumber = _levelFactory->getHelpNumber();
    _messageNumber = 0;
    
    _enemyBounceNumber = _levelFactory->getEnemyBounceNumber();
    _enemyChaseNumber = _levelFactory->getEnemyChaseNumber();
    _enemyStandNumber = _levelFactory->getEnemyStandnumber();
    
    _box = _levelFactory->getLevelFactoryBox();
    _switch = _levelFactory->getLevelFactorySwitch();
    _door = _levelFactory->getLevelFactoryDoor();
    _powerUp = _levelFactory->getLevelFactoryPowerUp();
    _enemyStand = _levelFactory->getLevelFactoryEnemyStand();
    _enemyBounce = _levelFactory->getLevelFactoryEnemyBounce();
    _enemyChase = _levelFactory->getLevelFactoryEnemyChase();
    _stairs = _levelFactory->getLevelFactoryStairs();
    _help= _levelFactory->getLevelFactoryHelp();
    
    
    //_player->unlockAllPowerUps();
    
    _HUD = Hud::Instance();
    _HUD->setSprites(_texture[0]);
    
    //if(_enemyChaseNumber > 0)
    //{
        calculateAdvancedCollisionMap();
    //}
    //RenderWindow::Instance()->setViewCenter(_player->getPlayer()->getSpritePosition());
    
    RenderWindow::Instance()->setViewCenter(_player->getPlayer()->getSpritePosition());
    
    
    /*
    //PRUEBA DE BOTON DE AYUDA
    _helpNumber=1;
                Texture* _texturePipes = new Texture("./textures/fondotexto.png");
            
            int _number = 1;
            
            sf::Font* _font = new sf::Font();
            _font->loadFromFile("./textures/Pixeled.ttf");
            
            sf::FloatRect _box;
            _box.height = 100;
            _box.width = 100;
            _box.left = 300;
            _box.top = 300;
            
            sf::Vector2f _pos;
            _pos.x = 300;
            _pos.y = 300;
                
    _help = new Help*[1];
    _help[0] = new Help(1, _player->getActualSituation()->getPositionX()+30, _player->getActualSituation()->getPositionY(), 0.0, 
            false, _texture[2], _number, _font, _texturePipes, _box, _pos);
    */
    //----------------------------------------
}

void World::buildTestObjects()
{
    
    
    _levelFactory = LevelFactory::Instance();
    
    _levelFactory->setLevelFactoryStates(0);

    _collisionMap = _levelFactory->getLevelFactoryCollisionMap();
    
    _clock = new Clock();
    
    _input = Input::Instance();
    
    //cout <<" Build test objects."<<endl;
    
    int x;
    
    //_levelFactory->setLevelFactoryStates(0);
    
    _map = _levelFactory->getLevelFactoryTileMapSprite();
    _mapWidth = _levelFactory->getLevelFactoryWidth();
    _mapHeight = _levelFactory->getLevelFactoryHeight();
    _mapLayers = _levelFactory->getLevelFactoryNumLayers();
    

    _textureNumber=5;
    _texture = new Texture*[_textureNumber];
    
    std::string path = "textures/PlayerTiles.png";
    std::string pathBullet = "textures/BulletTiles.png";
    std::string pathObject = "textures/ObjectTiles.png";
    std::string pathEnemy = "textures/EnemyTiles.png";
    
    _texture[0] = new Texture(path);
    _texture[1] = new Texture(pathBullet);
    _texture[2] = new Texture(pathObject);
    _texture[3] = new Texture(pathEnemy);
    
    sf::IntRect* square = new sf::IntRect(0,0,32,32);
    
    _player = Player::Instance();
    
    //_player->setPlayer(_texture[0], square,sf::Vector2f(16,16), sf::Vector2f(200.0f,200.0f), sf::Vector2f(1,1));
    //_player->setColor(sf::Color::Cyan);

    
    _boxNumber = 1;
    
    //_box = _levelFactory->getLevelFactoryBox();

    //_box[0] = new Box(1, 160.0, 384.0, 0.0, false, _texture[2],
    //                   1, 2, 16.0);
    //_box[1] = new Box(1, 128.0, 300.0, 0.0, false, _texture[2],1, 2, 16.0);
    //_box[2] = new Box(1, 224.0, 260.0, 0.0, false, _texture[2],1, 2, 16.0);    

    //_doorNumber = 2;
    //_door = _levelFactory->getLevelFactoryDoor();
    //_door[0] = new Door(1, 352.0, 320.0+64, 0.0, false, _texture[2], 0, 4.5, 1.0);
    //_door[1] = new Door(1, 352.0, 352.0+64, 0.0, false, _texture[2],1, 4.5, 1.0);
    
    //_switchNumber = 1;
    //_switch = _levelFactory->getLevelFactorySwitch();
    //_switch[0] = new Switch(1, 160.0, 200.0, 0.0, false, _texture[2], 1);
    
    //_switch[0]->setDoor(_door[0],_door[1]);
    
    //_powerUpNumber = 1;
    //_powerUp = _levelFactory->getLevelFactoryPowerUp();
    
    /*
    _powerUp = new PowerUp*[_powerUpNumber];
    
    
    _powerUp[0] = new PowerUp(1, 210.0, 384.0, 0.0, false, _texture[2],
                        1);

    _powerUp[1] = new PowerUp(1, 190.0, 424.0, 0.0, false, _texture[2],
                        2);

    _powerUp[2] = new PowerUp(1, 230.0, 384.0, 0.0, false, _texture[2],
                        3);  
    
    
    _box[0]->setActualSituation(_box[x]->getActualSituation()->getPositionX(),400.0f,_box[x]->getActualSituation()->getAngle());


                        3);        
    */
    
    //_enemyStandNumber = 1;
    //_enemyStand = _levelFactory->getLevelFactoryEnemyStand();
    
    
    
    //_HUD = Hud::Instance();
    
    //_HUD->setSprites(_texture[0]);
    
    
    
    //COMANDOS DE PRUEBA
    /*
    _stairs = new Stairs(1, 320.0+16.0, 128.0+16.0, 0.0, false, _texture[2],
            1,2);
    
     */ 
    //_stairs = _levelFactory->getlevelFactoryStairs();
    //_player->unlockAllPowerUps();
    
    //_enemyBounceNumber=1;
    //_enemyBounce = new EnemyBounce*[1];
    
    //_enemyBounce[0] = new EnemyBounce
    //            (_texture[3], sf::Vector2f(16.0f,16.0f), sf::Vector2f (224.0f,384.0f), sf::Vector2f(1.0f,1.0f), "uldr");

    }


//habra que pasarle _map[0] al update de los enemigos
void World::update()
{
    
    //UPDATE DE TODOS LOS OBJETOS

if(_player!=NULL)_player->input();

    
    if(_clock->getClockAsSeconds()>=float(UPS)){
        
        _input->inputInput();

        if(_input->inputCheck(0));
        if(_input->inputCheck(1));
        if(_input->inputCheck(2));
        if(_input->inputCheck(3));
        
        if(_player!=NULL){
            _player->update(_collisionMap);
        }
        
        int x;
        
        if(_box!=NULL)
        {
            for(x=0;x<_boxNumber;x++)
            {
                if(_box[x]->getErase())
                {
                    
                    delete _box[x];
                    _box[x]==NULL;
                }
                else{
                    _box[x]->update(_collisionMap);
                }
            }
        }

        if(_powerUp!=NULL)
        {
            for(x=0;x<_powerUpNumber;x++)
            {
                if(_powerUp[x]!=NULL)
                {
                    if(_powerUp[x]->getErase())
                    {
                        delete _powerUp[x];
                        _powerUp[x]=NULL;
                    }
                    else{
                        _powerUp[x]->update();
                    }
                }
            }
        }
        
        /*
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
        */
        
        if(_door!=NULL)
        {
            for(x=0;x<_doorNumber;x++)
            {
                if(_door[x]!=NULL)
                {
                    _door[x]->update();
                    //cout<<"puerta-------"<<endl;
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

        if(_help!=NULL)
        {
            for(x=0;x<_helpNumber;x++)
            {
                if(_help[x]!=NULL)
                {
                    _help[x]->update();
                }
            }
        }
        
        if(_bullet!=NULL){
            if(_bullet->getErase())
            {
                delete _bullet;
                _bullet=NULL;
            }
            else{
                _bullet->update(_collisionMap);
            }
        }
        else
        {
            if(_player->getFireBullet())
            {
                _bullet = new Bullet(true,false, _player->getPreviousSituation()->getPositionX(),
                        _player->getPreviousSituation()->getPositionY(),
                        _player->getPreviousSituation()->getAngle(),
                        11.0f, 3.5f, 1, _texture[2]);
            }
        }        

        if(_enemyBounce!=NULL)
        {
            for(x=0;x<_enemyBounceNumber;x++)
            {
                if(_enemyBounce[x]!=NULL)
                {
                    _enemyBounce[x]->update(_collisionMap);
                }
            }
        }

        if(_enemyChase!=NULL)
        {
            for(x=0;x<_enemyChaseNumber;x++)
            {
                if(_enemyChase[x]!=NULL)
                {
                    _enemyChase[x]->update(_advancedCollisionMap, _mapHeight, _mapWidth);
                }
            }
        }

        if(_enemyStand!=NULL)
        {
            for(x=0;x<_enemyStandNumber;x++)
            {
                if(_enemyStand[x]!=NULL)
                {
                    _enemyStand[x]->update(_player->getActualSituation()->getPosition());
                }
            }
        }
        
        if(_HUD!=NULL&&_player!=NULL){
            _HUD->update(_player->getHealth(),_player->getStamina(),
                    _player->getColor().r, _player->getColor().g,
            _player->getColor().b, _player->getColor().a);
        }
        checkCollisions();
        _clock->clockRestart();    
    }
    _percentTick=_clock->getClockAsSeconds()/float(UPS);        
    //if(_enemyChaseNumber > 0)
    //{
    //    calculateAdvancedCollisionMap();
    //}
}

//Metodo usado para corregir la posicion de los objetos tras todos sus updates, para comprobar que nadie se mete
//donde no le corresponde.
//Tambien activa determinados eventos en estos objetos en caso de haber colisiones.
void World::checkCollisions()
{
    int x;
    int y;
    
    //Colision EnemyBounce - Cajas
    if(_box!=NULL&&_enemyBounce!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            
            if(_box[x]!=NULL)
            {
                for(y=0;y<_enemyBounceNumber;y++)
                {
                    if(_enemyBounce[y]!=NULL)
                    {
                        
                        _box[x]->getSprite()->setSpritePosition(sf::Vector2f(_box[x]->getActualSituation()->getPositionX(),
                                _box[x]->getActualSituation()->getPositionY()));
                        _enemyBounce[y]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyBounce[y]->getEnemyActualSituation()->getPositionX(),
                                _enemyBounce[y]->getEnemyActualSituation()->getPositionY()));
                        
                        if(_box[x]->getSprite()->spriteIntersectsBounds(_enemyBounce[y]->getEnemySprite()))
                        {
                                sf::Vector2f  maxDespl = calculateMaxPosition(_enemyBounce[y]->getEnemySprite(),_enemyBounce[y]->getEnemyPreviousSituation(),                                
                                _enemyBounce[y]->getEnemyActualSituation(), _enemyBounce[y]->getEnemySpeed(), _box[x]->getSprite());
                                
                                
                                if(maxDespl.x!=_enemyBounce[y]->getEnemyActualSituation()->getPositionX() && 
                                        maxDespl.y!=_enemyBounce[y]->getEnemyActualSituation()->getPositionY())
                                {
                                    _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x-2*_enemyBounce[y]->getEnemyAxis().x,
                                            maxDespl.y-2*_enemyBounce[y]->getEnemyAxis().y);                                    
                                }
                                else if(maxDespl.x!=_enemyBounce[y]->getEnemyActualSituation()->getPositionX())
                                {
                                    _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x-2*_enemyBounce[y]->getEnemyAxis().x,
                                        maxDespl.y);   
                                }
                                else if(maxDespl.y!=_enemyBounce[y]->getEnemyActualSituation()->getPositionY())
                                {
                                    _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x,
                                            maxDespl.y-2*_enemyBounce[y]->getEnemyAxis().y);                                       
                                }
                                else{
                                    _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x,maxDespl.y);                                    
                                }
                                
                                _box[x]->setCollisionEnemy(true);
                                _enemyBounce[y]->setCollisionObject(true);
                        }
                    }
                }
            }
        }
    }    
        
    
    
    //Colision Jugador con el entorno
    
    //Colision Jugador - Cajas
    
    if(_player!=NULL&&_box!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
             _player->getPlayer()->setSpritePosition(sf::Vector2f(_player->getActualSituation()->getPositionX(),
             _player->getActualSituation()->getPositionY()));
            
              _box[x]->getSprite()->setSpritePosition(sf::Vector2f(_box[x]->getActualSituation()->getPositionX(),
             _box[x]->getActualSituation()->getPositionY()));
                
                if(_player->getPlayer()->spriteIntersectsBounds(_box[x]->getSprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_box[x]->getSprite()->getSpriteSprite(),0))
                    {
                        //si la caja no se esta chocando contra la pared.
                        if(_box[x]->getCollisionWithMap()==false){
                        
                            //Si el jugador puede mover la caja
                            if(_player->getColor()==sf::Color::Red&&_box[x]->getCollisionEnemyLastUpdate()==false
                                    &&_box[x]->getCollisionEnemy()==false)
                            {
                                
                                
                                if(_player->getPreviousSituation()->getPositionY()>=(_box[x]->getActualSituation()->getPositionY()+32+15))
                                {
                                    if(_player->getDirection().y!=0){
                                        if(_player->getDirection().x==0){
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                            _player->getActualSituation()->setPosition(_player->getPreviousSituation()->getPositionX(),
                                                    _player->getPreviousSituation()->getPositionY());

                                            _box[x]->setCollisionPlayerDirection(true, _player->getDirection().x, _player->getDirection().y);
                                        }
                                        else{
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                            _box[x]->setCollisionObject(true);                                                        
                                        }
                                    }
                                }
                                else if(_player->getPreviousSituation()->getPositionY()<=(_box[x]->getActualSituation()->getPositionY()-32-15))
                                {
                                    if(_player->getDirection().y!=0){
                                        if(_player->getDirection().x==0){
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                            _player->getActualSituation()->setPosition(_player->getPreviousSituation()->getPositionX(),
                                                    _player->getPreviousSituation()->getPositionY());

                                            _box[x]->setCollisionPlayerDirection(true, _player->getDirection().x, _player->getDirection().y);
                                        }
                                        else
                                        {
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                            _box[x]->setCollisionObject(true);                                                        
                                        }
                                    }
                                }                                                                
                                else if(_player->getPreviousSituation()->getPositionX()>=(_box[x]->getActualSituation()->getPositionX()+32+15))
                                {
                                    if(_player->getDirection().x!=0){
                                        if(_player->getDirection().y==0){
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                            _player->getActualSituation()->setPosition(_player->getPreviousSituation()->getPositionX(),
                                                    _player->getPreviousSituation()->getPositionY());

                                            _box[x]->setCollisionPlayerDirection(true, _player->getDirection().x, _player->getDirection().y);
                                        }
                                        
                                        else{
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                            _box[x]->setCollisionObject(true);                                                        
                                        }
                                    }
                                }   
                                else if(_player->getPreviousSituation()->getPositionX()<=(_box[x]->getActualSituation()->getPositionX()-32-15))
                                {
                                    if(_player->getDirection().x!=0){
                                        if(_player->getDirection().y==0){
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                            _player->getActualSituation()->setPosition(_player->getPreviousSituation()->getPositionX(),
                                                    _player->getPreviousSituation()->getPositionY());

                                            _box[x]->setCollisionPlayerDirection(true, _player->getDirection().x, _player->getDirection().y);
                                        }
                                        
                                        else{
                                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                                _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                            _box[x]->setCollisionObject(true);                                                        
                                        }
                                    }
                                }   
                                else{
                                    sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                        _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                    _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                    _box[x]->setCollisionObject(true);                                     
                                }
                            
                            }
                            //Si el jugador no puede mover la caja.
                            else
                            {
                                sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                _box[x]->setCollisionObject(true);                           
                            }
                        
                        }
                        else{
                                sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                                _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                                _box[x]->setCollisionObject(true);    
                        }
                    }
                }
            }
        }
    }
    
    //Colision Jugador - Puertas
    if(_player!=NULL&&_door!=NULL)
    {
        for(x=0;x<_doorNumber;x++)
        {
            if(_door[x]!=NULL)
            {
                if(_player->getPlayer()->spriteIntersectsBounds(_door[x]->getSprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_door[x]->getSprite()->getSpriteSprite(),0))
                    {        
                        
                        if(_door[x]->getClosing()==true){
                            
                            //Colision con una puerta que se esta cerrando. --> Hacer danyo y abrirse.

                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                    _player->getActualSituation(), _player->getSpeed(), _door[x]->getSprite());

                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                            _door[x]->setCollisionPlayer(true);
                            _door[x]->setActualSituation(_door[x]->getPreviousSituation()->getPositionX(), 
                                    _door[x]->getPreviousSituation()->getPositionY(),
                                    _door[x]->getPreviousSituation()->getAngle());


                            if(_door[x]->getClosing()){
                                _player->setHealth(_player->getHealth()-40);                            
                            }
                            
                            if(_door[x]->getJustClosed()==true){
                                std::cout << "RETRACTANDO" << std::endl;
                            }
                        
                        }
                        else if(_door[x]->getJustClosed()==true)
                        {
                            
                            //Colision con una puerta que acaba de cerrarse. --> Hacer danyo y abrirse.
                            
                            std::cout<<"This is happening."<<std::endl;
                            
                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                            _player->getActualSituation(), _player->getSpeed(), _door[x]->getSprite());

                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                            _door[x]->setCollisionPlayer(true);
                            _door[x]->setActualSituation(_door[x]->getPreviousSituation()->getPositionX(), 
                            _door[x]->getPreviousSituation()->getPositionY(),
                            _door[x]->getPreviousSituation()->getAngle());  
                            
                            _player->setHealth(_player->getHealth()-40);                            

                            _door[x]->open();
                            
                        }
                        else if(_door[x]->getClose()==true){   
                            
                            //Colision con una puerta cerrada --> impedir el paso.
                            
                            sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                            _player->getActualSituation(), _player->getSpeed(), _door[x]->getSprite());

                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                            _door[x]->setCollisionPlayer(true);
                            _door[x]->setActualSituation(_door[x]->getPreviousSituation()->getPositionX(), 
                            _door[x]->getPreviousSituation()->getPositionY(),
                            _door[x]->getPreviousSituation()->getAngle());                              
                        }
                        
                        
                    }
                }
            }
        }
    }
    
    //Colision Jugador - Interruptores
    if(_player!=NULL&&_switch!=NULL)
    {
        for(x=0;x<_switchNumber;x++)
        {
            if(_switch[x]!=NULL)
            {
                if(_player->getPlayer()->spriteIntersectsBounds(_switch[x]->getSprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_switch[x]->getSprite()->getSpriteSprite(),0))
                    {                        
                                                
                        _switch[x]->activate();

                    }
                }
            }
        }
    }

    //Colision Jugador - Botones de ayuda (help)
    if(_player!=NULL&&_help!=NULL)
    {
        for(x=0;x<_helpNumber;x++)
        {
            if(_help[x]!=NULL)
            {
                if(_player->getPlayer()->spriteIntersectsBounds(_help[x]->getSprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_help[x]->getSprite()->getSpriteSprite(),0))
                    {                        
                                                
                        _help[x]->setCollisionPlayer(true);
                        _help[x]->setShowMessage(true);

                    }
                }
            }
        }
    }    
    
     //Colision Jugador - PowerUps
   if(_player!=NULL&&_powerUp!=NULL)
    {
        for(x=0;x<_powerUpNumber;x++)
        {
            if(_powerUp[x]!=NULL)
            {
                if(_player->getPlayer()->spriteIntersectsBounds(_powerUp[x]->getSprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_powerUp[x]->getSprite()->getSpriteSprite(),0))
                    {                        
                        _powerUp[x]->setCollisionPlayer(true);
                        //el propio powerUp activa el poder en el jugador.
                    }
                }
            }
        }
    }
    
    //Colision Jugador - Enemigos Stand
    if(_player!=NULL&&_enemyStand!=NULL)
    {
        for(x=0;x<_enemyStandNumber;x++)
        {
            if(_enemyStand[x]!=NULL)
            {
                //choque con el enemigostand
                if(_player->getPlayer()->spriteIntersectsBounds(_enemyStand[x]->getEnemySprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_enemyStand[x]->getEnemySprite()->getSpriteSprite(),0))
                    {         
                        //cout <<"Colision con el enemigo directamente"<<endl;
                        
                        sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                _player->getActualSituation(), _player->getSpeed(), _enemyStand[x]->getEnemySprite());
                        
                        _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                        _player->setCollisionEnemy(true, _enemyStand[x]->getEnemyDamage(),0.1f);
                        
                        _enemyStand[x]->setCollisionPlayer(true);
                    }
                }
                //choque con su cono de vision
                if(_player->getPlayer()->spriteIntersectsBounds(_enemyStand[x]->getConeSprite()))
                {
                    if(!_player->getHidden()){
                        if(_player->getPlayer()->spriteIntersectsPixel(_enemyStand[x]->getConeSprite()->getSpriteSprite(),0))
                        {                   
                            //cout <<"Colision con el CONO directamente"<<endl;
                            _enemyStand[x]->setCollisionPlayerCone(true);

                            _player->setCollisionCone(true, _enemyStand[x]->getEnemyDamage(), 0.1f);

                        }                        
                    }
                }
            }
        }
    }
    
    //Colision Jugador - Enemigos Chase
    if(_player!=NULL&&_enemyChase!=NULL)
    {
        for(x=0;x<_enemyChaseNumber;x++)
        {
            if(_enemyChase[x]!=NULL)
            {
                //choque con el enemigostand
                if(_player->getPlayer()->spriteIntersectsBounds(_enemyChase[x]->getEnemySprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_enemyChase[x]->getEnemySprite()->getSpriteSprite(),0))
                    {         
                        cout <<"Colision con el enemigo directamente"<<endl;
                        
                        sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                _player->getActualSituation(), _player->getSpeed(), _enemyChase[x]->getEnemySprite());
                        
                        _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                        _player->setCollisionEnemy(true, _enemyChase[x]->getEnemyDamage(),0.1f);
                        
                        _enemyChase[x]->setCollisionPlayer(true);
                    }
                }
                //choque con su cono de vision
                if(_player->getPlayer()->spriteIntersectsBounds(_enemyChase[x]->getConeSprite()))
                {
                    if(!_player->getHidden()){
                        if(_player->getPlayer()->spriteIntersectsPixel(_enemyChase[x]->getConeSprite()->getSpriteSprite(),0))
                        {                   
                            cout <<"Colision con el CONO directamente"<<endl;
                            _enemyChase[x]->setCollisionPlayer(true);

                            _player->setCollisionCone(true, _enemyChase[x]->getEnemyDamage(), 0.1f);

                        }                        
                    }
                }
            }
        }
    } 
    
     //Colision Jugador - EnemyBounce
    if(_player!=NULL&&_enemyBounce!=NULL)
    {
        for(x=0;x<_enemyBounceNumber;x++)
        {
            if(_enemyBounce[x]!=NULL)
            {
                if(_player->getPlayer()->spriteIntersectsBounds(_enemyBounce[x]->getEnemySprite()))
                {
                    if(_player->getPlayer()->spriteIntersectsPixel(_enemyBounce[x]->getEnemySprite()->getSpriteSprite(),0))
                    {                       
                        
                        //cout <<"Colision con el enemigo directamente"<<endl;
                        

                        sf::Vector2f  maxDespl = calculateMaxPosition(_enemyBounce[x]->getEnemySprite(),_enemyBounce[x]->getEnemyPreviousSituation(),
                            _enemyBounce[x]->getEnemyActualSituation(), _enemyBounce[x]->getEnemySpeed(), _player->getPlayer());
                        
                        _enemyBounce[x]->getEnemyActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                        _player->setCollisionEnemy(true, _enemyBounce[x]->getEnemyDamage(),0.2f);
                        
                        _enemyBounce[x]->setCollisionPlayer(true);
                                                
                        maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                _player->getActualSituation(), _player->getSpeed(), _enemyBounce[x]->getEnemySprite());
                        
                        _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                        _player->setCollisionEnemy(true, _enemyBounce[x]->getEnemyDamage(),0.2f);
                        
                        _player->setPushedBack(true, sf::Vector2f(6.0f*_enemyBounce[x]->getEnemyAxis().x,6.0f*_enemyBounce[x]->getEnemyAxis().y));
                        

                    }
                }
            }
        }
    }
    
    //Colision Player y Stairs.
    if(_player!=NULL&&_stairs!=NULL)
    {
        if(_player->getPlayer()->spriteIntersectsBounds(_stairs->getSprite()))
        {
            if(_player->getPlayer()->spriteIntersectsPixel(_stairs->getSprite()->getSpriteSprite(),0))
            {            
                //PASAMOS AL SIGUIENTE NIVEL
                //cout<<"Hola"<<endl;
                _nextLevel = true;
            }
        }
    }
    

    /*
    //Colision Enemy Bounce con otros Enemy bounce
    if(_enemyBounce!=NULL)
    {
        for(x=0;x<_enemyBounceNumber;x++)
        {
            
            if(_enemyBounce[x]!=NULL)
            {
                for(y=0;y<_enemyBounceNumber;y++)
                {
                    if(x!=y){
                        if(_enemyBounce[y]!=NULL)
                        {

                            _enemyBounce[x]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyBounce[x]->getEnemyActualSituation()->getPositionX(),
                                    _enemyBounce[x]->getEnemyActualSituation()->getPositionY()));
                            _enemyBounce[y]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyBounce[y]->getEnemyActualSituation()->getPositionX(),
                                    _enemyBounce[y]->getEnemyActualSituation()->getPositionY()));

                            if(_enemyBounce[x]->getEnemySprite()->spriteIntersectsBounds(_enemyBounce[y]->getEnemySprite()))
                            {
                                    sf::Vector2f  maxDespl = calculateMaxPosition(_enemyBounce[y]->getEnemySprite(),_enemyBounce[y]->getEnemyPreviousSituation(),                                
                                    _enemyBounce[y]->getEnemyActualSituation(), _enemyBounce[y]->getEnemySpeed(), _enemyBounce[x]->getEnemySprite());

                                    _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                    _enemyBounce[x]->setCollisionObject(true);

                                    _enemyBounce[y]->setCollisionObject(true);
                            }
                        }
                    }
                }
            }
        }
    }  
    */
    //Colision EnemyBounce - EnemyStand
    if(_enemyStand!=NULL&&_enemyBounce!=NULL)
    {
        for(x=0;x<_enemyStandNumber;x++)
        {
            
            if(_enemyStand[x]!=NULL)
            {
                for(y=0;y<_enemyBounceNumber;y++)
                {
                    if(_enemyBounce[y]!=NULL)
                    {
                        _enemyStand[x]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyStand[x]->getEnemyActualSituation()->getPositionX(),
                                _enemyStand[x]->getEnemyActualSituation()->getPositionY()));
                        _enemyBounce[y]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyBounce[y]->getEnemyActualSituation()->getPositionX(),
                                _enemyBounce[y]->getEnemyActualSituation()->getPositionY()));
                        
                        if(_enemyStand[x]->getEnemySprite()->spriteIntersectsBounds(_enemyBounce[y]->getEnemySprite()))
                        {
                                sf::Vector2f  maxDespl = calculateMaxPosition(_enemyBounce[y]->getEnemySprite(),_enemyBounce[y]->getEnemyPreviousSituation(),                                
                                _enemyBounce[y]->getEnemyActualSituation(), _enemyBounce[y]->getEnemySpeed(), _door[x]->getSprite());
                                
                                _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                                _enemyStand[x]->setCollisionObject(true);
                        
                                _enemyBounce[y]->setCollisionObject(true);
                        }
                    }
                }
            }
        }
    }  
    
    //Colision EnemyBounce - Puertas
    if(_door!=NULL&&_enemyBounce!=NULL)
    {
        for(x=0;x<_doorNumber;x++)
        {
            
            if(_door[x]!=NULL)
            {
                for(y=0;y<_enemyBounceNumber;y++)
                {
                    if(_enemyBounce[y]!=NULL)
                    {
                        
                        _door[x]->getSprite()->setSpritePosition(sf::Vector2f(_door[x]->getActualSituation()->getPositionX(),
                                _door[x]->getActualSituation()->getPositionY()));
                        _enemyBounce[y]->getEnemySprite()->setSpritePosition(sf::Vector2f(_enemyBounce[y]->getEnemyActualSituation()->getPositionX(),
                                _enemyBounce[y]->getEnemyActualSituation()->getPositionY()));
                        
                        if(_door[x]->getSprite()->spriteIntersectsBounds(_enemyBounce[y]->getEnemySprite()))
                        {
                                sf::Vector2f  maxDespl = calculateMaxPosition(_enemyBounce[y]->getEnemySprite(),_enemyBounce[y]->getEnemyPreviousSituation(),                                
                                _enemyBounce[y]->getEnemyActualSituation(), _enemyBounce[y]->getEnemySpeed(), _door[x]->getSprite());
                                
                                _enemyBounce[y]->getEnemyActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                        
                                _door[x]->setCollisionEnemy(true);
                        
                                _enemyBounce[y]->setCollisionObject(true);
                        }
                    }
                }
            }
        }
    }    
    
    
    //Colision Balas - Puertas
    if(_bullet!=NULL&&_door!=NULL)
    {
        for(x=0;x<_doorNumber;x++)
        {
            if(_door[x]!=NULL)
            {
                if(!_door[x]->getOpen()){
                    if(_bullet->getSprite()->spriteIntersectsBounds(_door[x]->getSprite()))
                    {
                        if(_bullet->getSprite()->spriteIntersectsPixel(_door[x]->getSprite()->getSpriteSprite(),0))
                        {              
                            _bullet->impact();
                        }
                    }
                }
            }
        }
    }
     

    
    //Colision Balas - Cajas
    if(_bullet!=NULL&&_box!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
                if(_bullet->getSprite()->spriteIntersectsBounds(_box[x]->getSprite()))
                {
                    if(_bullet->getSprite()->spriteIntersectsPixel(_box[x]->getSprite()->getSpriteSprite(),0))
                    {              
                        _bullet->impact();
                    }
                }
            }
        }
    }
    
    
    //Colision Balas - EnemyBounce
    if(_enemyBounce!=NULL&&_bullet!=NULL)
    {
        for(x=0;x<_enemyBounceNumber;x++)
        {
            if(_enemyBounce[x]!=NULL)
            {
                if(_bullet->getSprite()->spriteIntersectsBounds(_enemyBounce[x]->getEnemySprite()))
                {
                    if(_bullet->getSprite()->spriteIntersectsPixel(_enemyBounce[x]->getEnemySprite()->getSpriteSprite(),0))
                    {              
                        _bullet->impact();
                        _enemyBounce[x]->setCollisionBullet(true);
                    }
                }
            }
        }
    }
     
    
    //Colision Balas - EnemyStand
    if(_enemyStand!=NULL&&_bullet!=NULL)
    {
        for(x=0;x<_enemyStandNumber;x++)
        {
            if(_enemyStand[x]!=NULL)
            {
                if(_bullet->getSprite()->spriteIntersectsBounds(_enemyStand[x]->getEnemySprite()))
                {
                    if(_bullet->getSprite()->spriteIntersectsPixel(_enemyStand[x]->getEnemySprite()->getSpriteSprite(),0))
                    {              
                        _bullet->impact();
                        _enemyStand[x]->setCollisionBullet(true);
                    }
                }
            }
        }
    } 
    
    //Colision Balas - EnemyChase
    if(_enemyChase!=NULL&&_bullet!=NULL)
    {
        for(x=0;x<_enemyChaseNumber;x++)
        {
            if(_enemyChase[x]!=NULL)
            {
                if(_bullet->getSprite()->spriteIntersectsBounds(_enemyChase[x]->getEnemySprite()))
                {
                    if(_bullet->getSprite()->spriteIntersectsPixel(_enemyChase[x]->getEnemySprite()->getSpriteSprite(),0))
                    {              
                        _bullet->impact();
                        _enemyChase[x]->setCollisionBullet(true);
                    }
                }
            }
        }
    }
    
    //Colision Cajas - Puertas
    if(_box!=NULL&&_door!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            
            if(_box[x]!=NULL)
            {
                for(y=0;y<_doorNumber;y++)
                {
                    if(_door[y]!=NULL)
                    {
                        
                        _box[x]->getSprite()->setSpritePosition(sf::Vector2f(_box[x]->getActualSituation()->getPositionX(),
                                _box[x]->getActualSituation()->getPositionY()));
                        
                        if(_box[x]->getSprite()->spriteIntersectsBounds(_door[y]->getSprite()))
                        {
                            if(_box[x]->getSprite()->spriteIntersectsPixel(_door[y]->getSprite()->getSpriteSprite(),0))
                            {
                                
                                sf::Vector2f maxDespl = calculateMaxPosition(_box[x]->getSprite(),_box[x]->getPreviousSituation(),
                                _box[x]->getActualSituation(), _box[x]->getSpeed(), _door[y]->getSprite());
                                                                
                                //cout << maxDespl.x <<" , "<<maxDespl.y <<endl;
                                
                                _box[x]->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);
                                
                                _box[x]->getActualSituation()->setPosition(
                                _box[x]->getPreviousSituation()->getPositionX(),
                                _box[x]->getPreviousSituation()->getPositionY());   
                                
                                _box[x]->setCollisionObject(true);
                                
                                _door[y]->setCollisionObject(true);
                                
                                if(_door[y]->getClosing() || _door[y]->getJustClosed()){
                                    _door[y]->open(); //forzamos la apertura;                                
                                }
                                
                                _box[x]->setCollisionPlayerDirection(false, 0.0f,0.0f);                            

                                //_box[x].set
                            }
                        }
                    }
                }
            }
        }
    }
    
    
        //Colision Cajas - otras cajas
    if(_box!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            
            if(_box[x]!=NULL)
            {
                for(y=0;y<_boxNumber;y++)
                {
                    if(_box[y]!=NULL)
                    {
                        if(x!=y)
                        {
                        
                            _box[x]->getSprite()->setSpritePosition(sf::Vector2f(_box[x]->getActualSituation()->getPositionX(),
                                    _box[x]->getActualSituation()->getPositionY()));

                            if(_box[x]->getSprite()->spriteIntersectsBounds(_box[y]->getSprite()))
                            {
                                if(_box[x]->getSprite()->spriteIntersectsPixel(_box[y]->getSprite()->getSpriteSprite(),0))
                                {

                                    sf::Vector2f maxDespl = calculateMaxPosition(_box[x]->getSprite(),_box[x]->getPreviousSituation(),
                                    _box[x]->getActualSituation(), _box[x]->getSpeed(), _box[y]->getSprite());

                                    //cout << maxDespl.x <<" , "<<maxDespl.y <<endl;

                                    _box[x]->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);

                                    _box[x]->getActualSituation()->setPosition(
                                    _box[x]->getPreviousSituation()->getPositionX(),
                                    _box[x]->getPreviousSituation()->getPositionY());   

                                    _box[x]->setCollisionObject(true);

                                    _box[y]->setCollisionObject(true);

                                    _box[x]->setCollisionPlayerDirection(false, 0.0f,0.0f);                            

                                    //_box[x].set
                                }
                            }
                        
                        }
                    }
                }
            }
        }
    }
    
    //Colision Cajas - Interruptores
    if(_box!=NULL&&_switch!=NULL)
    {
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
                for(y=0;y<_switchNumber;y++)
                {
                    if(_switch[y]!=NULL)
                    {
                        _box[x]->getSprite()->setSpritePosition(sf::Vector2f(_box[x]->getActualSituation()->getPositionX(),
                                _box[x]->getActualSituation()->getPositionY()));
                        if(_box[x]->getSprite()->spriteIntersectsBounds(_switch[y]->getSprite()))
                        {
                            _switch[y]->activate();
                        }                        
                    }
                }
            }
        }
    }
    
    
    //Arreglo de conflicto: Si una caja y choca con un jugador y una puerta. o Jugador empuja caja - caja
    if(_box!=NULL){
        for(x=0;x<_boxNumber;x++)
        {
            if(_box[x]!=NULL)
            {
                if(_box[x]->getCollisionLastUpdate()&&_box[x]->getCollisionObject())
                {
                    //cout <<"REAJUSTE"<<endl;

                        _player->setActualSituation(
                        _player->getPreviousSituation()->getPositionX(),
                        _player->getPreviousSituation()->getPositionY(),
                        _player->getPreviousSituation()->getAngle()
                        );

                        _box[x]->getActualSituation()->setPosition(
                        _box[x]->getPreviousSituation()->getPositionX(),
                        _box[x]->getPreviousSituation()->getPositionY());                    
                }
                
                  if(_box[x]->getCollisionLastUpdate()&&_box[x]->getCollisionEnemy())
                {
                    //cout <<"REAJUSTE"<<endl;

                        _player->setActualSituation(
                        _player->getPreviousSituation()->getPositionX(),
                        _player->getPreviousSituation()->getPositionY(),
                        _player->getPreviousSituation()->getAngle()
                        );

                        _box[x]->getActualSituation()->setPosition(
                        _box[x]->getPreviousSituation()->getPositionX(),
                        _box[x]->getPreviousSituation()->getPositionY());                    
                }              
                
                
            }
        }
    }
    
    
    
}

//Metodo usado para calcular el maximo desplazamiento de un sprite frente a otro.
sf::Vector2f World::calculateMaxPosition(Sprite* obj1, Situation* previousSituation1, Situation* actualSituation1, float speed, 
        Sprite* obj2)
{
    bool stop=false;
    
    //Calcular la direccion 1 0 o -1 a la que va en X.
    float directionX=actualSituation1->getPositionX()-previousSituation1->getPositionX();
    if(directionX>0) directionX=1;
    else if(directionX<0) directionX=-1;
    else directionX=0;
    
    //Calcular la direccion 1 0 o -1 a la que va en Y.
    float directionY=actualSituation1->getPositionY()-previousSituation1->getPositionY();
    if(directionY>0) directionY=1;
    else if(directionY<0) directionY=-1;
    else directionY=0;
    
    //Calcular maximo desplazamiento (posicion maxima a la que puede estar)
    //float desplFinalX=previousSituation1->getPositionX()+directionX*(speed1);
    //float desplFinalY=previousSituation1->getPositionY()+directionY*(speed1);
    
    float originObjectX=previousSituation1->getPositionX(); //¿Donde estaba el objeto antes de moverse?
    float originObjectY=previousSituation1->getPositionY();
    
    float desplFinalX=actualSituation1->getPositionX(); //¿Donde estará en la posición definitiva, donde no se choca?
    float desplFinalY=actualSituation1->getPositionY();
    
    for(float a=0.0; (desplFinalX!=previousSituation1->getPositionX()||desplFinalY!=previousSituation1->getPositionY())&&stop==false; a=a+1.0)
    {     
        if(directionX!=0)desplFinalX=originObjectX+directionX*(speed)-a*directionX;
        if(directionY!=0)desplFinalY=originObjectY+directionY*(speed)-a*directionY;
        
        if(desplFinalX<0.0)desplFinalX=originObjectX; //Comprobacion de seguridad para no ir mas atras del origen.
        if(desplFinalY<0.0)desplFinalY=originObjectY; //Comprobacion de seguridad para no ir mas atras del origen.

        obj1->setSpritePosition(sf::Vector2f(desplFinalX,desplFinalY));
        
        if(obj1->spriteIntersectsBounds(obj2))
        {
            if(!obj1->spriteIntersectsPixel(obj2->getSpriteSprite(),0))
            {
                stop = true; //Ya no hay choque. Hemos encontrado la pos. maxima.
            }
        }
        else
        {
            stop = true; //Ya no hay choque. Hemos encontrado la pos. maxima.
        }
    }
    //objeto1->setPosition(posOrigenXObjeto1,posOrigenYObjeto1); //devolvemos el objeto al origen
    //obj1->setSpritePosition(sf::Vector2f(desplFinalX,desplFinalY));
    sf::Vector2f maxDespl(desplFinalX,desplFinalY);
    return maxDespl;
}



void World::render(RenderWindow* renderWindow)
{
    //RENDER DE TODOS LOS OBJETOS
    RenderWindow* _renderWindow = RenderWindow::Instance();
 
    _renderWindow->updatePercentTick(_percentTick);
    //RenderWindow::Instance()->setViewCenter(_player->getPlayer()->getSpritePosition())
    //_renderWindow->windowClear();

    

    
    int x;
    
    if(_nextLevel == true)
    {
        if(_nextLevelCount < 1000)
        {
            _renderWindow->setViewZoom(1.005);
            _renderWindow->setViewRotate(0.3);
            _nextLevelCount++;
        }
        else
        {
            _levelDone = true;
        }
    }

    for (int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            if(_map[1][y][x] != NULL)
            _renderWindow->windowDraw(_map[1][y][x]);
        }
    }
    
    if(_stairs!=NULL)
    {
        _renderWindow->windowDraw(_stairs->getSprite());
    }
    

    if(_help!=NULL)
    {
        for(x=0;x<_helpNumber;x++)
        {
            if(_help[x]!=NULL)
            {
                _renderWindow->windowDraw(_help[x]->getSprite());
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
    
    if(_player!=NULL){
        _renderWindow->windowInterpolateDrawView(_player->getPlayer(),_player->getPreviousSituation(),_player->getActualSituation());
    }
    
    if(_bullet!=NULL){
        _renderWindow->windowInterpolateDraw(_bullet->getSprite(),_bullet->getPreviousSituation(),_bullet->getActualSituation());
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
                if(_enemyChase[x]->getConeSprite() != NULL)_renderWindow->windowInterpolateDraw(_enemyChase[x]->getConeSprite(),_enemyChase[x]->getEnemyPreviousSituation(),_enemyChase[x]->getEnemyActualSituation());
                _renderWindow->windowInterpolateDraw(_enemyChase[x]->getEnemySprite(),_enemyChase[x]->getEnemyPreviousSituation(),_enemyChase[x]->getEnemyActualSituation());
            }
        }
    }
        
   
     if(_enemyStand!=NULL)
     {
        for(x=0;x<_enemyStandNumber;x++)
        {
            if(_enemyStand[x]!=NULL)
            {
                if(_enemyStand[x]->getConeSprite() != NULL)_renderWindow->windowInterpolateDraw(_enemyStand[x]->getConeSprite(),_enemyStand[x]->getEnemyPreviousSituation(),_enemyStand[x]->getEnemyActualSituation());
                _renderWindow->windowInterpolateDraw(_enemyStand[x]->getEnemySprite(),_enemyStand[x]->getEnemyPreviousSituation(),_enemyStand[x]->getEnemyActualSituation());
                
            }
        }
     }
    
    
    if(_bullet!=NULL)
    {
        _renderWindow->windowInterpolateDraw(_bullet->getSprite(),
                _bullet->getPreviousSituation(), _bullet->getActualSituation());
    }
    
    for (int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            if(_map[2][y][x] != NULL)
            _renderWindow->windowDraw(_map[2][y][x]);
        }
    }
    
    
    if(_help!=NULL)
    {
        for(x=0;x<_helpNumber;x++)
        {
            if(_help[x]!=NULL)
            {
                if(_help[x]->getShowMessage()){
                    _renderWindow->windowDraw(_help[x]->getMessage());                
                }
            }
        }
    }
    
    if(_HUD!=NULL){
        _renderWindow->windowDraw(_HUD->getHUDBOX());
        _renderWindow->windowDraw(_HUD->getLife());
        _renderWindow->windowDraw(_HUD->getRectangle());
        _renderWindow->windowDraw(_HUD->getStamina());
    }
    
    //_renderWindow->windowDisplay();
    
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
                _door[x]=NULL;
            }
        }
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
    if(_help!=NULL)
    {
        for(x=0;x<_helpNumber;x++)
        {
            if(_help[x]!=NULL)
            {
                delete _help[x];
                _help[x]=NULL;
            }
        }
        delete[] _help;
        _help=NULL;
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
    
    if(_bullet!=NULL){
        delete _bullet;
        _bullet=NULL;
    }
    
    if(_stairs!=NULL){
        delete _stairs;
        _stairs=NULL;
    }
    
    if(_HUD!=NULL){
        //delete _HUD; //?????????????????????
        _HUD=NULL;
    }
    
    
    
    if(_player!=NULL){
        //delete _player; //??????????????????
        _player=NULL;
    }
    
    if(_pinstance!=NULL){
        //delete _pinstance; //??????
        _pinstance=NULL;
    }
    
    delete _clock;
    _clock=NULL;

}

bool World::getLevelDone()
{
    return _levelDone;
}

bool World::getDestroyTheWorld()
{
    return _destroytheworld;
}

void World::resetWorld()
{
    if(_levelFactory != NULL){
        _levelFactory->levelFactoryClear();
        _levelFactory = NULL;
    }
    
    if(_texture != NULL)
    {
        delete[] _texture;
        _texture = NULL;
    }
    
    if(_player != NULL)
    {
        _player = NULL;
    }
    
    if(_help != NULL)
    {
        _help = NULL;
    }
    
    if(_box != NULL)
    {
        _box = NULL;
    }
    
    if(_door != NULL)
    {
        _door = NULL;
    }
    
    if(_powerUp != NULL)
    {
        _powerUp = NULL;
    }
    
    if(_switch != NULL)
    {
        _switch = NULL;
    }
    
    if(_map != NULL)
    {
        _map = NULL;
    }
    
    if(_collisionMap != NULL)
    {
        _collisionMap = NULL;
    }
    
    if(_advancedCollisionMap != NULL)
    {
        for(int y=0; y<_mapHeight; y++)
        {
            delete[] _advancedCollisionMap[y];
            _advancedCollisionMap[y] = NULL;
        }
        delete[] _advancedCollisionMap;
        _advancedCollisionMap = NULL;
    }
        
    if(_enemyBounce != NULL)
    {
        _enemyBounce = NULL;
    }
    
    if(_enemyChase != NULL)
    {
        _enemyChase = NULL;
    }
    
    if(_enemyStand != NULL)
    {
        _enemyStand = NULL;
    }
    
    if(_bullet != NULL)
    {
        delete _bullet;
        _bullet = NULL;
    }
    
    if(_HUD != NULL)
    {
        _HUD = NULL;
    }
    
    if(_stairs != NULL)
    {
        _stairs = NULL;
    }
    
    if(_clock != NULL)
    {
        delete _clock;
        _clock = NULL;
    }
    
    _pinstance = 0;
    
    
}

int World::getNextLevel()
{
    return _stairs->getNextLevel();
}

void World::calculateAdvancedCollisionMap()
{
    _advancedCollisionMap = new int*[_mapHeight];
    for(int y=0; y<_mapHeight; y++)
    {
        _advancedCollisionMap[y] = new int[_mapWidth];
    }
     
    for(int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            _advancedCollisionMap[y][x] = _collisionMap[y][x];
        }
    }
        
    for(int i=0; i<_doorNumber; i++)
    {
        _advancedCollisionMap[int((_door[i]->getActualSituation()->getPositionY()-16)/32)][int((_door[i]->getActualSituation()->getPositionX()-16)/32)] = 2;
    }
        
    for(int i=0; i<_boxNumber; i++)
    {
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()-31)/32)][int((_box[i]->getActualSituation()->getPositionX()-31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()-31)/32)][int((_box[i]->getActualSituation()->getPositionX()+31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()+31)/32)][int((_box[i]->getActualSituation()->getPositionX()-31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()+31)/32)][int((_box[i]->getActualSituation()->getPositionX()+31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()-31)/32)][int((_box[i]->getActualSituation()->getPositionX())/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY()+31)/32)][int((_box[i]->getActualSituation()->getPositionX())/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY())/32)][int((_box[i]->getActualSituation()->getPositionX()-31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY())/32)][int((_box[i]->getActualSituation()->getPositionX()+31)/32)] = 2;
        _advancedCollisionMap[int((_box[i]->getActualSituation()->getPositionY())/32)][int((_box[i]->getActualSituation()->getPositionX())/32)] = 2;
    }
    
    for(int y=0; y<_mapHeight; y++)
    {
        for(int x=0; x<_mapWidth; x++)
        {
            cout<<_advancedCollisionMap[y][x]-1;
        }
        cout<<endl;
    }
}