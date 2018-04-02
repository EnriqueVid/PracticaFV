/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.cpp
 * Author: tuba
 * 
 * Created on 19 de marzo de 2018, 20:29
 */

#include "Estado.h"

Estado::Estado(float x, float y, float g) {
    pos_x=x;
    pos_y=y;
    grados=g;
}

Estado::Estado(const Estado& orig) {
}

sf::Vector2f Estado::getEstado(){
    return sf::Vector2f(pos_x, pos_y);
}

void Estado::setEstado(float x, float y) {
    pos_x=x;
    pos_y=y;
}

void Estado::setGrados(float g) {
    grados=g;
}

float Estado::getGrados(){
    return grados;
}

Estado::~Estado() {
}



