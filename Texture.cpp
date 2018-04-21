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

Texture::Texture()
{
    _path="";
    _texture = NULL;
}

Texture::Texture(std::string path) 
{
    textureLoadFromFile(path);
}

Texture::Texture(const Texture& orig) {
}

void Texture::textureLoadFromFile(std::string path)
{
    path = path;
    if(!_texture->loadFromFile(path))
    {
        std::cout<<"Error al cargar la textura en la ruta: "<< _path <<std::endl;
    }
}

sf::Vector2u Texture::getTextureSize()
{
    return(_texture->getSize());
}

sf::Texture* Texture::getTextureTexture()
{
    return _texture;
}

std::string Texture::getTexturePath()
{
    return _path;
}

bool Texture::loadFromImage(const sf::Image& image, const sf::IntRect& area)
{
    return _texture->loadFromImage(image,area);
}

sf::Image Texture::copyToImage()
{
    return _texture->copyToImage();
}

Texture::~Texture() {
    delete _texture;
}



