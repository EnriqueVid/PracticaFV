/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.h
 * Author: carlos
 *
 * Created on 26 de abril de 2018, 19:30
 */

#ifndef WORLD_H
#define WORLD_H
#include "Text.h"
#include "Player.h"
#include "Box.h"
#include "Door.h"
#include "PowerUp.h"
#include "Switch.h"
#include "RenderWindow.h"
#include "Sprite.h"
#include "Message.h"
#include "LevelFactory.h"
#include "EnemyBounce.h"
#include "EnemyStand.h"
#include "EnemyChase.h"
#include "Clock.h"
#include "Input.h"
#include "Bullet.h"
#include "Hud.h"
#include "Stairs.h"

#include <SFML/System/Vector2.hpp>

#define UPS 1.0f/15.0f


class World {
public:
    static World* Instance();
    
    void update(); //ejecuta el update de todos los objetos
    
    void checkCollisions(); //comprueba las colisiones
    
    void buildWorld(int lvlNumber);
    
    void buildTestObjects();
    
    sf::Vector2f calculateMaxPosition(Sprite* obj1, Situation* previousSituation1, Situation* actualSituation1, float speed, 
        Sprite* obj2); //devuelve la posicion maxima donde no se colisiona
        
    void render(RenderWindow* _renderWindow); //ejecuta el render de todos los objetos
    void resetWorld();
    void calculateAdvancedCollisionMap();
    
    bool getLevelDone();
    bool getDestroyTheWorld();
    int getNextLevel();
    
protected:
    World();
    World(const World& orig);
    virtual ~World();
    
private:
    static World* _pinstance;
    //World tendra a todos los objetos de la escena.
    Texture** _texture;
    Player* _player;
    Box** _box;
    Door** _door;
    PowerUp** _powerUp;
    Switch** _switch;
    Sprite**** _map;
    Message** _message;
    
    EnemyBounce** _enemyBounce;
    EnemyChase** _enemyChase;
    EnemyStand** _enemyStand;
    
    Bullet* _bullet; //Bala del jugador.
    Hud* _HUD; //HUD del jugador.
    Stairs* _stairs; //escaleras al siguiente nivel
    
    Input* _input;
    
    LevelFactory* _levelFactory;
    
    int** _collisionMap;
    int** _advancedCollisionMap;
    
    Clock* _clock;
    float _percentTick;
    
    int _textureNumber;
    int _boxNumber;
    int _doorNumber;
    int _powerUpNumber;
    int _switchNumber;
    int _messageNumber;
    
    
    int _enemyBounceNumber;
    int _enemyChaseNumber;
    int _enemyStandNumber;
    
    int _mapWidth;
    int _mapHeight;
    int _mapLayers;
    
    
    bool _destroytheworld;
    bool _nextLevel;
    bool _levelDone;
    
    int _nextLevelCount;
};

#endif /* WORLD_H */

