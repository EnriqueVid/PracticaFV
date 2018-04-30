/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: tuba
 * 
 * Created on 30 de abril de 2018, 2:36
 */

#include "Node.h"

Node::Node(sf::Vector2i pos, int level, int priority)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
    
    _level = level;
    
    _priority = priority;
}

Node::Node(const Node& orig)
{
}

Node::~Node()
{
}

void Node::updatePriority(sf::Vector2i end)
{
    _priority=_level+estimate(end)*10;
}

//Hacemos que las diagonales tengan más coste.
void Node::nextLevel(int i, int dir) // i: direction
{
    //Dir es la cantidad de direcciones en las que se puede mover el enemigo
    if(dir==8)
    {
        if((i%2)==0)
        {
            _level+=10;
        }else{
            _level+=14;
        }
    }else{
        _level+=10;
    }
}

int Node::estimate(sf::Vector2i end)
    {
        int xd, yd, d;
        
        xd=end.x + _pos.x;
        yd=end.y + _pos.y;

        // Euclidian Distance
        d = sqrt(xd*xd+yd*yd);

        return(d);
    }


void Node::setPos(sf::Vector2i pos)
{
    _pos.x = pos.x;
    _pos.y = pos.y;
}

sf::Vector2i Node::getPos()
{
    return _pos;
}

int Node::getLevel()
{
    return _level;
}

int Node::getPriority()
{
    return _priority;
}