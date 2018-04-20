/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 10:07
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>


class Image {
public:
    Image();
    Image(const std::string& filename);
    Image(const Image& orig);
    virtual ~Image();
        
    sf::Color imageGetPixel(unsigned int x, unsigned int y);
    bool imageLoadFromFile(const std::string& filename);
    sf::Vector2u imageGetSize();
  
    sf::Image* getImageImage();

private:
    
    sf::Image* _image;

};

#endif /* IMAGE_H */

