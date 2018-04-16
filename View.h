/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.h
 * Author: tuba
 *
 * Created on 13 de abril de 2018, 16:05
 */

#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

class View 
{
public:
    View();
    View(const View& orig);
    
    void viewMove(sf::Vector2f position);
    void viewRotate(float angle);
    void viewReset(sf::FloatRect viewport);
    void viewZoom(float zoom);
    
    void setViewCenter(sf::Vector2f center);
    void setViewRotation(float angle);
    void setViewSize(sf::Vector2f size);
    void setViewViewport(sf::FloatRect viewport);
    void setViewView(sf::View view);
    
    sf::Vector2f getViewCenter();
    float getViewRotation();
    sf::Vector2f getViewSize();
    sf::FloatRect getViewViewport();
    sf::View getViewView();
    
    virtual ~View();
private:
    
    sf::View _view;

};

#endif /* VIEW_H */

