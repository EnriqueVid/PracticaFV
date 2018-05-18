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
#include "Hud.h"

RenderWindow* RenderWindow::_pinstance = 0;
RenderWindow* RenderWindow::Instance()
{
    if(_pinstance == 0)
    {
        _pinstance = new RenderWindow;
    }
    return _pinstance;
}

RenderWindow::RenderWindow()
{
    _window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Color of Fate");
    _percentTick = 1;
}

RenderWindow::RenderWindow(int width, int height, std::string title)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    _percentTick = 1;
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


void RenderWindow::windowInterpolateDraw(Sprite* sprite, Situation* prev, Situation* actual)
{
    float x = prev->getPositionX()*(1-_percentTick) + actual->getPositionX()*_percentTick;
    float y = prev->getPositionY()*(1-_percentTick) + actual->getPositionY()*_percentTick;
    float degPrev = prev->getAngle();
    float degActu = actual->getAngle();
    
    if((degActu >= 0 && degActu <= 90) && degPrev > (degActu + 180))
    {
        degPrev -= 360;
    }
    if((degActu <360 && degActu >= 270) && degPrev < (degActu - 180))
    {
        degPrev += 360;
    }
    
    float g = (((_percentTick-0)*(degActu - degPrev))/(1-0)) + degPrev;
    
    sprite->setSpritePosition(sf::Vector2f(x, y));
    sprite->setSpriteRotation(g);
    
    _window->draw(sprite->getSpriteSprite());
}

void RenderWindow::windowInterpolateDrawView(Sprite* sprite, Situation* prev, Situation* actual)
{
    float x = prev->getPositionX()*(1-_percentTick) + actual->getPositionX()*_percentTick;
    float y = prev->getPositionY()*(1-_percentTick) + actual->getPositionY()*_percentTick;
    float degPrev = prev->getAngle();
    float degActu = actual->getAngle();
    
    if((degActu >= 0 && degActu <= 90) && degPrev > (degActu + 180))
    {
        degPrev -= 360;
    }
    if((degActu <360 && degActu >= 270) && degPrev < (degActu - 180))
    {
        degPrev += 360;
    }
    
    float g = (((_percentTick-0)*(degActu - degPrev))/(1-0)) + degPrev;
    
    sprite->setSpritePosition(sf::Vector2f(x, y));
    sprite->setSpriteRotation(g);
    
    setViewCenter(sf::Vector2f(x, y));
    Hud::Instance()->setPosition();
    
    _window->draw(sprite->getSpriteSprite());
}

void RenderWindow::windowDraw(Message* message)
{
    //_window->draw(message->getSpriteMessage()->getSpriteSprite());
    sf::Text t = *message->getTextMessage();
    t.setColor(sf::Color::Yellow);
    t.setCharacterSize(12);
    
    cout<<"Ancho del texto: "<<t.getGlobalBounds().width<<endl;
    cout<<"Size texto: "<<t.getCharacterSize()<<endl;
    cout<<"Fuente texto: "<<t.getFont()->getInfo().family<<endl;
    cout<<"String texto: "<<message->getStringMessage()<<endl;
    
    sf::RectangleShape rect(sf::Vector2f(t.getGlobalBounds().width, t.getGlobalBounds().height));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(sf::Vector2f(t.getGlobalBounds().left, t.getGlobalBounds().top));
    
    _window->draw(rect);
    _window->draw(t);
}

bool RenderWindow::windowIsOpen()
{
    return _window->isOpen();
}

bool RenderWindow::windowPollEvent(Event* ev)
{
    return _window->pollEvent(*ev->getEventEvent());
}

sf::Vector2i RenderWindow::windowMapCoordsToPixel(sf::Vector2f position)
{
    return _window->mapCoordsToPixel(position,_window->getView());
}

sf::Vector2f RenderWindow::windowMapPixelToCoords(sf::Vector2i position)
{
    return _window->mapPixelToCoords(position,_window->getView());
}

void RenderWindow::updatePercentTick(float pt)
{
    _percentTick = pt;
}

void RenderWindow::setWindowFramerateLimit(int fps)
{
    _window->setFramerateLimit(fps);
}

void RenderWindow::setWindowView(View* view)
{
    _window->setView(view->getViewView());
}

sf::Vector2i RenderWindow::getWindowPosition()
{
   return _window->getPosition();
}

sf::RenderWindow* RenderWindow::getWindowWindow()
{
    return _window;
}

void RenderWindow::setViewCenter(sf::Vector2f pos)
{
    sf::View view= _window->getView();
    view.setCenter(pos.x, pos.y);
    
    _window->setView(view);
}   

void RenderWindow::setViewZoom(float zoom)
{
    sf::View view= _window->getView();
    view.zoom(zoom);
    
    _window->setView(view);
} 

void RenderWindow::setViewRotate(float rot)
{
    sf::View view= _window->getView();
    view.rotate(rot);
    
    _window->setView(view);
} 

sf::Vector2f RenderWindow::getViewCenter()
{
    return _window->getView().getCenter();
}

void RenderWindow::resetView()
{
    sf::View view = _window->getDefaultView();
    _window->setView(view);
}