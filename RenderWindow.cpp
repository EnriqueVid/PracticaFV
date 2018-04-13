/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderWindow.cpp
 * Author: dsm58
 * 
 * Created on 11 de abril de 2018, 14:30
 */

#include "RenderWindow.h"

RenderWindow::RenderWindow(int x, int y, std::string nombre) {
    
    window = new sf::RenderWindow(sf::VideoMode(x,y), nombre);
    
}

RenderWindow::RenderWindow(const RenderWindow& orig) {
}

RenderWindow::~RenderWindow() {
}

