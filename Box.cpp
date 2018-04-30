/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 23:00
 */

#include "Box.h"
#include "Object.h"

Box::Box() {
}

Box::Box(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
        int boxType, int vt, float speed) : 
Object(objectType,  initialPosX,  initialPosY,  initialAngle,  canBeMoved, texture) {
    
    //cout <<"Ejecutando constructor de hijo"<<endl;
    
    _vt = vt;
    _speed=speed;
    _clock=NULL;
    
    _boxType = boxType;
    _breakAnimation=false;
    _breakAnimationFrame=0;
    _clock = new Clock();
    
    _sprite = new Sprite(texture,sf::IntRect(0,0,64,64),sf::Vector2f(32.0f,32.0f),sf::Vector2f(300.0f,300.0f),sf::Vector2f(1.0f,1.0f));
    
    _collisionDesplX=0;
    _collisionDesplY=0;
    _collisionLastUpdate=false;
    
    _collisionWithMap=false;
    //_sprite = new Sprite(texture,sf::IntRect(0,0,64,64));
    //cout << _sprite->getSpriteOrigin().x<<endl;
}

void Box::interact(){
    //interactuacion con la caja
    if(_breakAnimation==false){
        //solo interactuamos si no se esta rompiendo
        //std::cout << "Puedo interactuar con la caja" <<std::endl;
    }
    else{
        //std::cout << "No puedo interactuar" <<std::endl;
    }
}
    
void Box::breakBox(){
            std::cout << "Rompiendo la caja" <<std::endl;
    if(_breakAnimation==false){
             std::cout << "Se rompe. Ponieno a true breakanimation." <<std::endl;
        _breakAnimation=true;
        _clock->clockRestart();        
    }
    else{
                std::cout << "No puedo romper la caja porque ya se esta rompiendo." <<std::endl;
    }
}
    
void Box::impact(){
    //std::cout << "Intentando Impacto a la caja" <<std::endl;
    if(_breakAnimation==false){
            //std::cout << "Hay impacto." <<std::endl;
    _vt = _vt - 1;
        if(_vt<=0){
            //std::cout << "0 de vida. llamando a romper." <<std::endl;
            breakBox();
        }
    }
    else{
        //std::cout << "No puedo haber impacto porque se esta rompiendo." <<std::endl;
    }
}
    

bool Box::getCollisionLastUpdate(){
    return _collisionLastUpdate;
}

//borra el desplazamiento y _collisionPlayer
void Box::collision(){
    
    _collisionDesplX=0;
    _collisionDesplY=0;
    _collisionPlayer=false;
    _collisionLastUpdate=true;
}

void Box::checkMapCollisions(int** _collisionMap, int axisX, int axisY)
{
    cout <<"MAP COLLISIONS"<<endl;
    cout <<"AxisX: "<<axisX << "AxisY: " << axisY<<endl;
    
    if(axisX>0)
    {
        cout <<"ENTRO AQUI A HACER COSAS"<<endl;
        if(_collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()+31)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()+31)/32] == 2)
        {
            _actualSituation->setPosition(_previousSituation->getPositionX(),_actualSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()+32)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()+32)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX()+1,_actualSituation->getPositionY());
            }
            _collisionWithMap=true;
        }
    }
    else if(axisX<0)
    {
        cout <<"ENTRO AQUI A HACER COSAS"<<endl;
        if(_collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()-31)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()-31)/32] == 2)
        {
            _actualSituation->setPosition(_previousSituation->getPositionX(),_actualSituation->getPositionY());
            
            /*
            while(_collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()-32)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()-32)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX()-1,_actualSituation->getPositionY());
            }
             */ 
            _collisionWithMap=true;
        }
    }
    
    if(axisY>0)
    {
        cout <<"ENTRO AQUI A HACER COSAS"<<endl;
        if(_collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()+31)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()+31)/32][int(_actualSituation->getPositionX()-31)/32] == 2)
        {
            _actualSituation->setPosition(_actualSituation->getPositionX(),_previousSituation->getPositionY());
            
            /*
            while(_collisionMap[int(_actualSituation->getPositionY()+32)/32][int(_actualSituation->getPositionX()+31)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()+32)/32][int(_actualSituation->getPositionX()-31)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX(),_actualSituation->getPositionY()+1);
            }
             */ 
            
            _collisionWithMap=true;
        }
    }
    else if(axisY<0)
    {
        cout <<"ENTRO AQUI A HACER COSAS"<<endl;
        if(_collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()+31)/32] == 2 || _collisionMap[int(_actualSituation->getPositionY()-31)/32][int(_actualSituation->getPositionX()-31)/32] == 2)
        {
            _actualSituation->setPosition(_actualSituation->getPositionX(),_previousSituation->getPositionY());
            
            while(_collisionMap[int(_actualSituation->getPositionY()-32)/32][int(_actualSituation->getPositionX()+31)/32] != 2 && _collisionMap[int(_actualSituation->getPositionY()-32)/32][int(_actualSituation->getPositionX()-31)/32] != 2)
            {
                _actualSituation->setPosition(_actualSituation->getPositionX(),_actualSituation->getPositionY()-1);
            }
            
            _collisionWithMap=true;
        }
    }
}


bool Box::getCollisionWithMap()
{
    return _collisionWithMap;
}


void Box::update(int** _collisionMap){
    
    
    _collisionWithMap=false;
    if(_collisionLastUpdate)_collisionLastUpdate=false;
    
    float auxPrevX=_previousSituation->getPositionX();
    float auxPrevY=_previousSituation->getPositionY();
    
    if((_collisionPlayer&&_collisionObject)||(_collisionPlayer&&_collisionEnemy)||(_collisionEnemy&&_collisionObject))
    {
        //cout <<"Colision con objeto Y JUGADOR"<<endl;
        _previousSituation->setPosition(auxPrevX,auxPrevY);
        _actualSituation->setPosition(auxPrevX,auxPrevY);
        _collisionObject=false;
        collision();
    }
    
    if(_collisionEnemy)impact(); //el impacto enemigo baja la vida de la caja.
    
    
    
    newSituation(_actualSituation->getPosition().x+_collisionDesplX*_speed,
            _actualSituation->getPosition().y+_collisionDesplY*_speed,
            _actualSituation->getAngle());

    checkMapCollisions(_collisionMap,_collisionDesplX,_collisionDesplY);

    
    if(_collisionPlayer){
        //cout <<"Colision con el jugador"<<endl;
        collision(); //borra el desplazamiento y _collisionPlayer
    }
    else if(_collisionObject){
        //cout <<"Colision con objeto"<<endl;
        _previousSituation->setPosition(auxPrevX,auxPrevY);
        _actualSituation->setPosition(auxPrevX,auxPrevY);
        _collisionObject=false;
        _collisionLastUpdate=true;
    }
    
    
    

    if(_breakAnimation==true){
        _ignoreCollisions=true;
        //avanzar los frames de la animacion acorde al reloj interno.
            //cuando la animacion haya acabado:
            if(_clock->getClockAsSeconds()>0.2){
                    //std::cout << "La caja deberia borrarse" <<std::endl;
                _erase=true;            
            }
    }
    else{
        //realizar acciones normales de update.
    }

    checkMapCollisions(_collisionMap,_collisionDesplX,_collisionDesplY);
    
    _collisionEnemy=false;    

}


void Box::setCollisionPlayerDirection(bool b, float direcX, float direcY){
    _collisionPlayer=b;
    _collisionDesplX=direcX;
    _collisionDesplY=direcY;
}


        
int Box::getVt(){
    return _vt;
}
    
int Box::getBoxType(){
    return _boxType;
}
    
float Box::getSpeed(){
    return _speed;
}
    
bool Box::getBreakAnimation(){
    return _breakAnimation;
}   

int Box::getBreakAnimationFrame(){
    return _breakAnimationFrame;
}
Clock* Box::getClock(){
    return _clock;
}

Box::Box(const Box& orig) {
    
}

Box::~Box() {
    std::cout <<"Deleting Box" << std::endl;

    if(_clock!=NULL){
    delete _clock;
    _clock = NULL;        
    }

    /*
    delete _clock; 
    _clock = NULL;*/
    
    //se llama automaticamente al destructor de objeto (padre).
}