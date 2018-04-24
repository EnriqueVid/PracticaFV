#ifndef TEXT_H
#define TEXT_H


#include <SFML/Graphics.hpp>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include "Font.h"


class Text {

public:
    Text(std::string file);
    Text();
    virtual ~Text();
         
    int getCharacterSize();
    sf::Color getColor();
    Font getFont();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    sf::String getString();
    void rotate(float angle);
    void setCharacterSize(int size);
    void setColor(sf::Color color);
    void setFont(Font* font);
    void setPosition(float x, float y);
    void scale(sf::Vector2f factor);
    void setString(std::string texto);
    
private:
    
    Text* _text;

};
#endif /* TEXT_H */
