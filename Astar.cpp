/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Astar.cpp
 * Author: tuba
 * 
 * Created on 30 de abril de 2018, 2:46
 */



#include "Astar.h"


Astar::Astar(int** map, int height, int width, int dir)
{
    _height = height;
    _width = width;
    
    _path = NULL;
    
    _start.x = 0;
    _start.y = 0;
    
    _end.x = 0;
    _end.y = 0;
    
    _meh = "";
    
    _dir = dir;
    if(_dir == 8)
    {
        _dirX = new int[8];
        _dirY = new int[8];
        
        _dirX[0] = 1;
        _dirY[0] = 0;
        
        _dirX[1] = 1;
        _dirY[1] = 1;
        
        _dirX[2] = 0;
        _dirY[2] = 1;
        
        _dirX[3] = -1;
        _dirY[3] = 1;
        
        _dirX[4] = -1;
        _dirY[4] = 0;
        
        _dirX[5] = -1;
        _dirY[5] = -1;
        
        _dirX[6] = 0;
        _dirY[6] = -1;
        
        _dirX[7] = 1;
        _dirY[7] = -1;
        
    }
    else if(_dir == 4)
    {
        _dirX = new int[4];
        _dirY = new int[4];
        
        _dirX[0] = 1;
        _dirY[0] = 0;
        
        _dirX[1] = 0;
        _dirY[1] = 1;
        
        _dirX[2] = -1;
        _dirY[2] = 0;
        
        _dirX[3] = 0;
        _dirY[3] = -1;
    }
    
    _map = new int*[_height];
    _closedNodes = new int*[_height];
    _openNodes = new int*[_height];
    _directions = new int*[_height];
    
    for(int i=0;i<_height;i++)
    {
        _map[i] = new int[_width];
        _closedNodes[i] = new int[_width];
        _openNodes[i] = new int[_width];
        _directions[i] = new int[_width];
        for(int j=0;j<_width;j++)
        {
            _map[i][j] = map[i][j];
        }
    }
}

Astar::Astar(const Astar& orig)
{
}

Astar::~Astar()
{
    for(int i = 0;i<_height;i++)
    {
        delete [] _map[i];
    }
    delete[] _map;
    _map = NULL;
    
    for(int i = 0;i<_height;i++)
    {
        delete [] _openNodes[i];
    }
    delete[] _openNodes;
    _openNodes = NULL;
    
    for(int i = 0;i<_height;i++)
    {
        delete [] _closedNodes[i];
    }
    delete[] _closedNodes;
    _closedNodes = NULL;
    
    for(int i = 0;i<_height;i++)
    {
        delete [] _directions[i];
    }
    delete[] _directions;
    _directions = NULL;
    
    delete[] _dirX;
    _dirX = NULL;
    
    delete[] _dirY;
    _dirY = NULL;
    
    if(_path !=NULL){
        delete[] _path;
        _path = NULL;
    }
}

std::string Astar::pathfind(sf::Vector2i start, sf::Vector2i end)
{
    //¡Plis end mai laif!
    std::vector<Node*> pq[2]; // Nodos a los que puedo ir, pero no he pasado por ellos.
    int pqi; // Índice de la lista de prioridad
    Node* n0;
    Node* m0;
    int i, j, x, y, xdx, ydy;
    char c;
    
    pqi=0;
    
    _start.x = start.x;
    _start.y = start.y;
    
    _end.x = end.x;
    _end.y = end.y;
    
    //Inicializamos todos los nodos posibles a 0
    for(y=0;y<_height;y++)
    {
        for(x=0;x<_width;x++)
        {
            _closedNodes[x][y]=0;
            _openNodes[x][y]=0;
        }
    }
    
    //Creamos el nodo en el que empezamos y lo añadimos a la lista de prioridad
    n0=new Node(start, 0, 0);
    n0->updatePriority(end);
    pq[pqi].push_back(n0);
    _openNodes[start.y][start.x]=n0->getPriority(); // Marcamos el nodo en el mapa de nodos que podemos visitar pero no hemos pasado aún
    
    // A* search
    while(!pq[pqi].empty())
    {
        // Obtener el nodo con la mayor prioridad de la lista de los Nodos aún no visitados
        n0=new Node(pq[pqi].back()->getPos(),pq[pqi].back()->getLevel(), pq[pqi].back()->getPriority());

        x=n0->getPos().x;
        y=n0->getPos().y;

        pq[pqi].pop_back(); 
        
        // Quitarlo de los nodos aún por visitar
        _openNodes[y][x]=0;
        // Marcarlo como ya visitado
        _closedNodes[y][x]=1;
        
        
        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==end.x && y==end.y) 
        {
            // generate the path from finish to start
            // by following the directions
            _meh="";
            while(!(x==start.x && y==start.y))
            {
                j=_directions[y][x];
                c='0'+(j+_dir/2)%_dir;
                _meh=c+_meh;
                x+=_dirX[j];
                y+=_dirY[j];
            }

            // garbage collection
            delete n0;
            
            // empty the leftover nodes ?¿?¿?¿?¿?
            while(!pq[pqi].empty())
            {
                pq[pqi].pop_back();
            }
            return _meh;
        }
        
        // generate moves (child nodes) in all possible directions
        for(i=0;i<_dir;i++)
        {
            xdx = x + _dirX[i];
            ydy = y + _dirY[i];
            
            if(!(xdx<0 || xdx>_width-1 || ydy<0 || ydy>_height-1 || _map[ydy][xdx]==2 || _closedNodes[ydy][xdx]==1))
            {
                // generate a child node
                m0=new Node(sf::Vector2i(xdx, ydy), n0->getLevel(), n0->getPriority());
                m0->nextLevel(i, _dir);
                m0->updatePriority(end);
                
                
                
                // if it is not in the open list then add into that
                if(_openNodes[ydy][xdx]==0)
                {
                    _openNodes[ydy][xdx]=m0->getPriority();
                    pq[pqi].push_back(m0);
                    
                    // mark its parent node direction
                    _directions[ydy][xdx]=(i + (_dir/2))%_dir;
                }
                else if(_openNodes[ydy][xdx]>m0->getPriority())
                {
                    // update the priority info
                    _openNodes[ydy][xdx]=m0->getPriority();
                    // update the parent direction info
                    _directions[ydy][xdx]=(i + (_dir/2))%_dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].back()->getPos().x==xdx && pq[pqi].back()->getPos().y==ydy))
                    {                
                        pq[1-pqi].push_back(pq[pqi].back());
                        pq[pqi].pop_back();
                    }
                    pq[pqi].pop_back(); // remove the wanted node
                    
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size())
                    {
                        pqi=1-pqi;
                    }
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push_back(pq[pqi].back());
                        pq[pqi].pop_back();
                    }
                    pqi=1-pqi;
                    pq[pqi].push_back(m0); // add the better node instead
                }
                else
                {
                    delete m0;
                }
            }
        }
        reordenar(pq[0]);
        reordenar(pq[1]);
        delete n0;
    }
    _meh = "";
    return _meh;
}


void Astar::reordenar(std::vector<Node*> &list)
{
    //Ordenación en burbuja de los vectores
    int tam = list.size();
    Node* nodo;
    
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam-1;j++)
        {
            if(list.at(j)->getPriority()<list.at(j+1)->getPriority())
            {
                nodo = new Node(list.at(j)->getPos(), list.at(j)->getLevel(), list.at(j)->getPriority());
                list.insert(list.begin()+j+2,nodo);
                list.erase(list.begin()+j);
            }
        }
    }
}

sf::Vector2i* Astar::getAbsoluto(std::string path)
{
    _path = new sf::Vector2i[path.size()];
    for(int i=0;i<path.size();i++)
    {
        if(i==0)
        {
            int m = path.at(i);
            std::cout<<m<<std::endl;
            _path[i].x = _dirX[path.at(i)-48] + _start.x;
            _path[i].y = _dirY[path.at(i)-48] + _start.y;
        }else
        {
            _path[i].x = _dirX[path.at(i)-48] + _path[i-1].x;
            _path[i].y = _dirY[path.at(i)-48] + _path[i-1].y;
        }
    }
    return _path;
}