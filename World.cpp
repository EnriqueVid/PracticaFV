/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   World.cpp
 * Author: carlos
 * 
 * Created on 26 de abril de 2018, 19:30
 */

#include "World.h"


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
    buildWorld(0);
}

World::buildWorld(int lvlNumber)
{
    LevelFactory* lvl = LevelFactory.Instance();
    lvl->setLevelFactoryStates(0);
    
    //_box = lvl.getBox
    //_door = lvl.getDoor...    
}

void World::update()
{
    //UPDATE DE TODOS LOS OBJETOS
    
    checkCollisions();
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

void World::render()
{
    //RENDER DE TODOS LOS OBJETOS
}

World::World(const World& orig)
{
    
}

World::~World()
{
    //DELETE DE TODOS LOS PUNTEROS
            
            
}

