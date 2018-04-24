/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.cpp
 * Author: emiliosello
 * 
 * Created on 22 de abril de 2018, 17:58
 */
#include "Text.h"

Text::Text(std::string file)
{
    _text->setString(file);
}

Text::Text()
{
    _text = NULL;
}

Text::~Text()
{
    delete _text;
}

int Text::getCharacterSize()
{
   return _text->getCharacterSize(); 
}

sf::Color Text::getColor()
{
    return _text->getColor();
}
    
Font Text::getFont()
{
    _text->getFont();
}
    
sf::FloatRect Text::getGlobalBounds()
{
    return _text->getGlobalBounds();
}

sf::Vector2f Text::getPosition()
{
    return _text->getPosition();
}
    
sf::String Text::getString()
{
    return _text->getString();
}
    
void Text::rotate(float angle)
{
    _text->rotate(angle);
}
    
void Text::setCharacterSize(int size)
{
    _text->setCharacterSize(size);
}
    
void Text::setColor(sf::Color color)
{
   _text->setColor(color);
}
    
void Text::setFont(Font* font)
{
    _text->setFont(font);
}
    
void Text::setPosition(float x, float y)
{
    _text->setPosition(x,y);
}
    
void Text::scale(sf::Vector2f factor)
{
    _text->scale(factor);
}
    
void Text::setString(std::string texto)
{
    _text->setString(texto);
}

    