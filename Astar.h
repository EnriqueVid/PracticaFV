/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Astar.h
 * Author: tuba
 *
 * Created on 30 de abril de 2018, 2:46
 */

#ifndef ASTAR_H
#define ASTAR_H

#include <queue>
#include "Node.h"

class Astar {
public:
    
    Astar(int** map, int height, int width, int dir);
    Astar(const Astar& orig);
    virtual ~Astar();
    std::string pathfind(sf::Vector2i start, sf::Vector2i end);
    void reordenar(std::vector<Node*> &list);
    
private:
    int _height;
    int _width;
    int** _map;
    int** _openNodes;
    int** _closedNodes;
    int** _directions;
    int _dir;
    
    int* _dirX;
    int* _dirY;
};

#endif /* ASTAR_H */

