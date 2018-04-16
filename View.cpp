/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.cpp
 * Author: tuba
 * 
 * Created on 13 de abril de 2018, 16:05
 */

#include "View.h"

View::View()
{
}

View::View(const View& orig)
{
}

View::~View()
{
    
}

void View::viewMove(sf::Vector2f position)
{
    _view.move(position);
}

void View::viewRotate(float angle)
{
    _view.rotate(angle);
}

void View::viewReset(sf::FloatRect viewport)
{
    _view.reset(viewport);
}

void View::viewZoom(float zoom)
{
    _view.zoom(zoom);
}

//Métodos set
void View::setViewCenter(sf::Vector2f center)
{
    _view.setCenter(center);
}

void View::setViewRotation(float angle)
{
    _view.setRotation(angle);
}

void View::setViewSize(sf::Vector2f size)
{
    _view.setSize(size);
}

void View::setViewViewport(sf::FloatRect viewport)
{
    _view.setViewport(viewport);
}

void View::setViewView(sf::View view)
{
    _view = view;
}

//Métodos get
float View::getViewRotation()
{
     return _view.getRotation();
}
 
sf::Vector2f View::getViewCenter()
{
     return _view.getCenter();
}
  
sf::Vector2f View::getViewSize()
{
     return _view.getSize();
}
   
sf::FloatRect View::getViewViewport()
{
     return _view.getViewport();
}

sf::View View::getViewView()
{
    return _view;
}