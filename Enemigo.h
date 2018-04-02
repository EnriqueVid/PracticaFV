/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.h
 * Author: newman
 *
 * Created on 26 de marzo de 2018, 0:58
 */


#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML/Graphics.hpp>
#include "Estado.h"
#include <math.h>
#include <iostream>
#include <string>
#include "Mapa.h"
#include "Collision.h"
#include "Jugador.h"

using namespace sf;

class Enemigo {
public:
    Enemigo(Texture *tex, Texture *texCono, int x, int y, char t, int rot, IntRect rect, string d);
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();
    
    void input(Mapa *map);
    void update(Jugador *jug, Mapa *map);
    void render(sf::RenderWindow* window, sf::Clock* reloj, float maxTime);
    
    void interpolar(float time);
    void dejarDePulsarTeclas();
    Sprite getCono();
    
    void mirar(float x, float y);
    void perseguir(float x, float y);
    
    
private:
    Sprite spr;
    Sprite *cono;
    float vel;
    char tipo;
    char dir;
    char estado;
    string patron;
    Estado* pasado;
    Estado* futuro;
    int patAct;
    int eje_x;
    int eje_y;
    int dir_x;
    int dir_y;
    Clock clk;
    
};

#endif /* ENEMIGO_H */

