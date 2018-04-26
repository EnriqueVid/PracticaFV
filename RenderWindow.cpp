/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RenderWindow.cpp
 * Author: dsm58
 * 
 * Created on 11 de abril de 2018, 14:30
 */

#include "RenderWindow.h"
#include "Event.h"
#include "Message.h"

RenderWindow::RenderWindow(int width, int height, std::string title)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    //_view = new View();
    //_view->setViewView(_window->getView());
}

RenderWindow::RenderWindow(const RenderWindow& orig) 
{
}

RenderWindow::~RenderWindow()
{
}

void RenderWindow::windowClear()
{
    _window->clear();
}

void RenderWindow::windowDisplay()
{
    _window->display();
}

void RenderWindow::windowClose()
{
    _window->close();
}

void RenderWindow::windowDraw(Sprite* sprite)
{
    _window->draw(sprite->getSpriteSprite());
}

void RenderWindow::windowDraw(Message* message)
{
    _window->draw(message->getSpriteMessage()->getSpriteSprite());
    _window->draw(message->getTextMessage()->getText());                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}

bool RenderWindow::windowIsOpen()
{
    return _window->isOpen();
}

bool RenderWindow::windowPollEvent(Event* ev)
{
    return _window->pollEvent(*ev->getEventEvent());
}

sf::Vector2i RenderWindow::windowMapCoordsToPixel(sf::Vector2f position, View* view)
{
    return _window->mapCoordsToPixel(position,view->getViewView());
}

sf::Vector2f RenderWindow::windowMapPixelToCoords(sf::Vector2i position, View* view)
{
    return _window->mapPixelToCoords(position,view->getViewView());
}

void RenderWindow::setWindowFramerateLimit(int fps)
{
    _window->setFramerateLimit(fps);
}

void RenderWindow::setWindowView(View* view)
{
    _window->setView(view->getViewView());
}

View* RenderWindow::getWindowView()
{
    return _view;
}

sf::RenderWindow* RenderWindow::getWindowWindow()
{
    return _window;
}