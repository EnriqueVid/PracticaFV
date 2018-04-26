/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Font.cpp
 * Author: emiliosello
 * 
 * Created on 22 de abril de 2018, 18:19
 */

#include "Font.h"

Font::Font(std::string file)
{
    _font.loadFromFile(file);
}

void Font::loadFromFile(std::string filename)
{
    _font.loadFromFile(filename);
}

sf::Font Font::getFont()
{
    return _font;
}

Font::~Font()
{
}