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
    _text.setString(file);
}

Text::Text()
{
    _text.setString("");
    _font = NULL;
}

Text::~Text()
{
}

void Text::setOrigin(float x, float y){
    _text.setOrigin(x, y);
}

sf::Text Text::getText()
{
    return _text;
}


int Text::getCharacterSize()
{
    return _text.getCharacterSize();
}

sf::Color Text::getColor()
{
    return _text.getColor();
}
    
sf::FloatRect Text::getGlobalBounds()
{
    return _text.getGlobalBounds();
}

sf::Vector2f Text::getPosition()
{
    return _text.getPosition();
}
    
std::string Text::getString()
{
    return _text.getString();
}
    
void Text::rotate(float angle)
{
    _text.rotate(angle);
}
    
void Text::setCharacterSize(int size)
{
    _text.setCharacterSize(size);
}
    
void Text::setColor(sf::Color color)
{
   _text.setColor(color);
}
    
void Text::setFont(Font* font)
{
    _font = font;
    _text.setFont(_font->getFont());
}
    
void Text::setPosition(float x, float y)
{
    _text.setPosition(x,y);
}
    
void Text::scale(sf::Vector2f factor)
{
    _text.scale(factor);
}
    
void Text::setString(std::string texto)
{
    _text.setString(texto);
}

Font* Text::getFont()
{
    return _font;
}
    