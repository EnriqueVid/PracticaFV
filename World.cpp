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
    _levelFactory = NULL;
    _bullet=NULL;
    
    _collisionMap=NULL;
    _advancedCollisionMap=NULL;
    
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
    
    
    _levelFactory = LevelFactory::Instance();
    
    _levelFactory->setLevelFactoryStates(0);

    _collisionMap = _levelFactory->getLevelFactoryCollisionMap();
    
    _clock = new Clock();
    
    _input = Input::Instance();
    
    cout <<" Build test objects."<<endl;
    
    int x;
    
    //_levelFactory->setLevelFactoryStates(0);
    
    _map = _levelFactory->getLevelFactoryTileMapSprite();
    _mapWidth = _levelFactory->getLevelFactoryWidth();
    _mapHeight = _levelFactory->getLevelFactoryHeight();
    _mapLayers = _levelFactory->getLevelFactoryNumLayers();
    

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

    //_player->setPlayer(_texture[0], square,sf::Vector2f(16,16), sf::Vector2f(200.0f,200.0f), sf::Vector2f(1,1));
    //_player->setColor(sf::Color::Cyan);

    
    _boxNumber = 1;
    
    _box = _levelFactory->getLevelFactoryBox();

    //_box[0] = new Box(1, 160.0, 384.0, 0.0, false, _texture[2],
    //                   1, 2, 16.0);
    //_box[1] = new Box(1, 128.0, 300.0, 0.0, false, _texture[2],1, 2, 16.0);
    //_box[2] = new Box(1, 224.0, 260.0, 0.0, false, _texture[2],1, 2, 16.0);    

    _doorNumber = 2;
    _door = _levelFactory->getLevelFactoryDoor();
    //_door[0] = new Door(1, 352.0, 320.0+64, 0.0, false, _texture[2], 0, 4.5, 1.0);
    //_door[1] = new Door(1, 352.0, 352.0+64, 0.0, false, _texture[2],1, 4.5, 1.0);
    
    _switchNumber = 1;
    _switch = _levelFactory->getLevelFactorySwitch();
    //_switch[0] = new Switch(1, 160.0, 200.0, 0.0, false, _texture[2], 1);
    
    //_switch[0]->setDoor(_door[0],_door[1]);
    
    _powerUpNumber = 1;
    _powerUp = _levelFactory->getLevelFactoryPowerUp();
    
    /*
    _powerUp = new PowerUp*[_powerUpNumber];
    
    
    _powerUp[0] = new PowerUp(1, 210.0, 384.0, 0.0, false, _texture[2],
                        1);

    _powerUp[1] = new PowerUp(1, 190.0, 424.0, 0.0, false, _texture[2],
                        2);

    _powerUp[2] = new PowerUp(1, 230.0, 384.0, 0.0, false, _texture[2],
                        3);        
    */
    
    _enemyStandNumber = 1;
    _enemyStand = _levelFactory->getLevelFactoryEnemyStand();
    }


//habra que pasarle _map[0] al update de los enemigos
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
                    //if(_powerUp[x]->getErase())
                    //{
                    //    delete _powerUp[x];
                    //    _powerUp[x]==NULL;
                    //}
                    //else{
                        _powerUp[x]->update();
                    //}
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
        
        if(_bullet!=NULL){
            if(_bullet->getErase())
            {
                delete _bullet;
                _bullet=NULL;
            }
            else{
                _bullet->update();
            }
        }
        else
        {
            if(_player->getFireBullet())
            {
                _bullet = new Bullet(true,false, _player->getPreviousSituation()->getPositionX(),
                        _player->getPreviousSituation()->getPositionY(),
                        _player->getPreviousSituation()->getAngle(),
                        11.0f, 3.5f, 1, _texture[1]);
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
                    _enemyChase[x]->update(_collisionMap);
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
    int x;
    int y;
    
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
                        
                        //Si el jugador puede mover la caja
                        if(_player->getColor()==sf::Color::Red)
                        {
                           sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                    _player->getActualSituation(), _player->getSpeed(), _box[x]->getSprite());

                            _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     

                            _player->getActualSituation()->setPosition(_player->getPreviousSituation()->getPositionX(),
                                    _player->getPreviousSituation()->getPositionY());

                            _box[x]->setCollisionPlayerDirection(true, _player->getDirection().x, _player->getDirection().y);                            
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
                        

                        sf::Vector2f maxDespl = calculateMaxPosition(_player->getPlayer(),_player->getPreviousSituation(),
                                _player->getActualSituation(), _player->getSpeed(), _door[x]->getSprite());
                        
                        _player->getActualSituation()->setPosition(maxDespl.x,maxDespl.y);     
                        
                        _door[x]->setCollisionPlayer(true);

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
                                
                                _box[x]->setCollisionPlayerDirection(false, 0.0f,0.0f);                            

                                //_box[x].set
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
    
    
    //Arreglo de conflicto: Si una caja y choca con un jugador y una puerta.
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
        _renderWindow->windowInterpolateDraw(_player->getPlayer(),_player->getPreviousSituation(),_player->getActualSituation());
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

