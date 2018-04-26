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
#include "View.h"
#include "Sprite.h"
#include "Event.h"
#include "Situation.h"

class RenderWindow 
{
public:
    RenderWindow(int width, int height, std::string title);
    RenderWindow(const RenderWindow& orig);
    
    void windowClear();
    void windowDraw(Sprite* sprite);
    void windowInterpolateDraw(Sprite* sprite, Situation* prev, Situation* actual);
    void windowDisplay();
    void windowClose();
    bool windowIsOpen();
    bool windowPollEvent(Event* ev);
    sf::Vector2i windowMapCoordsToPixel(sf::Vector2f position, View* view);
    sf::Vector2f windowMapPixelToCoords(sf::Vector2i position, View* view);
    void updatePercentTick(float pt);
    
    void setWindowFramerateLimit(int fps);
    void setWindowView(View* view);
    
    
    View* getWindowView();
    sf::RenderWindow* getWindowWindow();
    
    virtual ~RenderWindow();
private:
    sf::RenderWindow* _window;
    View* _view;
    float _percentTick;
};

#endif /* RENDERWINDOW_H */

