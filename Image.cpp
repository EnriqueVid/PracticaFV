/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.cpp
 * Author: carlos
 * 
 * Created on 19 de abril de 2018, 10:07
 */

#include "Image.h"

Image::Image() 
{
    _image = new sf::Image();
}

Image::Image(const std::string& filename)
{
    imageLoadFromFile(filename);
}

Image::Image(const Image& orig) 
{
    _image = new sf::Image();
}

sf::Color Image::imageGetPixel(unsigned int x, unsigned int y)
{
    return _image->getPixel(x,y);
}

bool Image::imageLoadFromFile(const std::string& filename)
{
    return _image->loadFromFile(filename);
}

sf::Vector2u Image::imageGetSize()
{
    return _image->getSize();
}

sf::Image* Image::getImageImage(){
    
    return _image;
}

Image::~Image() 
{
    delete _image;
}

