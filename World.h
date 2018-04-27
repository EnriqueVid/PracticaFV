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


#include <SFML/System/Vector2.hpp>


class World {
public:
    static World* Instance();
    
    void update(); //ejecuta el update de todos los objetos
    
    void checkCollisions(); //comprueba las colisiones
    
    void buildWorld(int lvlNumber);
    
    //Jugador - Objetos Inmoviles (impedir paso)
    //Jugador - Enemigos
    //Jugador - Radares enemigos
    //Jugador - Cajas
    //Jugador - Switches
    //Jugador - Puertas
    
    //Lo mismo para las cajas y los enemigos
    
    sf::Vector2f calculateMaxPosition(Sprite* obj1, Situation* previousSituation1, 
    Situation* actualSituation1 , Sprite* obj2); //devuelve la posicion maxima donde no se colisiona
        
    void render(); //ejecuta el render de todos los objetos
    
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
    RenderWindow* _renderWindow;
    Sprite**** _map;
    Message** _message;
    
    int _textureNumber;
    int _boxNumber;
    int _powerUpNumber;
    int _switchNumber;
    int _messageNumber;
};

#endif /* WORLD_H */

