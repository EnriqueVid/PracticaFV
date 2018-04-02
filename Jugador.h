/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.h
 * Author: tuba
 *
 * Created on 24 de marzo de 2018, 19:30
 */

#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Estado.h"
#include <math.h>
#include "Collision.h"

class Jugador {
public:
    Jugador(sf::Sprite*, int, int);
    
    void input();
    void update();
    void render(sf::RenderWindow*, sf::Clock*, float);
    
    void interpolar(float);
    void dejarDePulsarTeclas();
    int getColor();
    void cambiaColor(sf::Color);
    sf::Sprite* getPersonaje();
    void supervelocidad();
    void bajavida(float f);
    
    void deletear();
private:
    sf::Sprite* personaje;
    Estado* pasado;
    Estado* futuro;
    int vida_max;
    float vida;
    int estamina_max;
    float estamina;
    int color;
    int velocidad;
    
    
    //Recoge el input y determina la dirección en la que se mueve.
    int eje_x;
    int eje_y;
    
    //Determina la dirección a la que mira el jugador en cada momento.
    int dir_x;
    int dir_y;
    
    //Determina si ejecutar la habilidad o no
    bool habilidad;
};

#endif /* JUGADOR_H */

