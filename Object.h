/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 10:22
 */

#ifndef OBJECT_H
#define OBJECT_H
#include "Sprite.h"
#include "Situation.h"
#include "Texture.h"
#include "RenderWindow.h"

class Object {
public:
    Object();
    Object(const Object& orig);
    Object(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture* texture);

    void interact();
    
    void newSituation(float, float, float);
    void setActualSituation(float, float, float);
    void setPreviousSituation(float, float, float);
    
    Sprite* getSprite();
    int getObjectType();
    bool getCanBeMoved();
    Situation* getActualSituation();
    Situation* getPreviousSituation();
    
    bool getIgnoreCollisions();
    bool getErase();
    bool getCollision();
    
    bool getCollisionPlayer();
    bool getCollisionEnemy();
    bool getCollisionBox();
    bool getCollisionObject();    
    
    void setCollisionPlayer(bool b);
    void setCollisionEnemy(bool b);
    void setCollisionBox(bool b);
    void setCollisionObject(bool b);
    
    void update();
    void render(RenderWindow* window, Clock* clock, float ups);
    void interpolate(float actualTime);
    
    virtual ~Object();
    
protected:
    Sprite* _sprite;
    Situation* _actualSituation; //Posicion y angulos actuales (interpolacion).
    Situation* _previousSituation; //Posicion y angulo anteriores (interpolacion).
    bool _canBeMoved; //Nos indica si el objeto se podra mover o no.
    int _objectType; //Nos indica el tipo de objeto del que se trata.
    bool _ignoreCollisions; //Indica si le afectaran o no las colisiones.
    bool _erase; //Boolean usado para indicar al mundo si debe borrar este objeto.

    bool _collisionPlayer; //Ojo: depende mucho de la implementacion.
    //En box, por ejemplo, nos sirve para controlar el update de Box, pero luego se hace =false, por lo que no podemos usarla en
    //checkCollisions, en su lugar usamos _collisionLastUpdate de caja, el cual no se hace false hasta la siguiente iteracion.
    bool _collisionEnemy;
    bool _collisionBox;
    bool _collisionObject;
    
    
};

#endif /* OBJECT_H */