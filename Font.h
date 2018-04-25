#ifndef FONT_H
#define FONT_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <cstdlib>
#include <iostream>


class Font{

public:
    Font(std::string file);
    virtual ~Font();
    void loadFromFile(std::string file);
    sf::Font getFont();
    
private:
    
    sf::Font _font;

};

#endif /* FONT_H */
