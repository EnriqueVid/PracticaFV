/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.h
 * Author: newman
 *
 * Created on 10 de abril de 2018, 18:05
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Texture {
public:
    Texture();
    Texture(std::string path);
    Texture(const Texture& orig);
    virtual ~Texture();

    void textureLoadFromFile(std::string path);
    sf::Vector2u getTextureSize();
    sf::Texture* getTextureTexture();
    std::string getTexturePath();


private:
    sf::Texture* _texture;
    std::string _path;


};

#endif /* TEXTURE_H */

