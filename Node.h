/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: tuba
 *
 * Created on 30 de abril de 2018, 2:36
 */

#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>
#include <math.h>

class Node {
public:
    Node(sf::Vector2i pos, int level, int priority);
    Node(const Node& orig);
    virtual ~Node();
    void updatePriority(sf::Vector2i end);
    void nextLevel(int i, int dir);
    int estimate(sf::Vector2i end);
    
    void setPos(sf::Vector2i pos);
    
    sf::Vector2i getPos();
    int getLevel();
    int getPriority();
    
private:
    sf::Vector2i _pos;
    int _level;
    int _priority;
};

#endif /* NODE_H */

