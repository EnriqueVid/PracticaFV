/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderWindow.h
 * Author: dsm58
 *
 * Created on 11 de abril de 2018, 14:30
 */

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H
#include <SFML/Graphics.hpp>

class RenderWindow {
public:
    RenderWindow(int x, int y, std::string nombre);
    void clear();
    void draw(Sprite* sprite);
    void display();
    void close();
    void isOpen();
    void setFramerateLimit(int fps);
    void setView(View* view);
    View* getView();
    sf::Vector2i mapCoordsToPixel(sf::Vector2f position, View* view);
    sf::Vector2i mapPixelToCoords(sf::Vector2f position, View* view);
    
    
    RenderWindow(const RenderWindow& orig);
    virtual ~RenderWindow();
private:
    sf::RenderWindow* window;
};

#endif /* RENDERWINDOW_H */

