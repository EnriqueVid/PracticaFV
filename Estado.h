/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: tuba
 *
 * Created on 19 de marzo de 2018, 20:29
 */

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Estado {
public:
    Estado(float, float, float);
    Estado(const Estado& orig);
    sf::Vector2f getEstado();
    void setEstado(float, float);
    float getGrados();
    void setGrados(float g);
    virtual ~Estado();
private:
    float pos_x;
    float pos_y;
    float grados;
};

#endif /* ESTADO_H */

