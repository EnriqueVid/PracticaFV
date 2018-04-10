/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.cpp
 * Author: newman
 * 
 * Created on 10 de abril de 2018, 18:05
 */

#include "Texture.h"

Texture::Texture(std::string path) 
{
    _path = path;
    if(!_texture.loadFromFile(path))
    {
        cout<<"Error al cargar la textura en la ruta: "<< _path <<endl;
    }
}

Texture::Texture(const Texture& orig) {
}

Texture::~Texture() {
}

