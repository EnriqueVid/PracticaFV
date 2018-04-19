#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "RenderWindow.h"
#include "Event.h"
#include "Input.h"
#include "Game.h"
#include "State.h"
#include "StateGameLoop.h"

#define UPS 1.0f/15.0f


sf::Clock* clc;

using namespace std;

int main() 
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    Event* ev = new Event();
    Input* in = Input::Instance();
    clc = new sf::Clock();
    
    while(window->windowIsOpen()){
    Game* lvl = new Game(StateGameLoop::Instance());
            
    sf::VertexArray quad(sf::Quads,4);
    
    quad[0].position = sf::Vector2f(100,60);
    quad[1].position = sf::Vector2f(400,60);
    quad[2].position = sf::Vector2f(400,200);
    quad[3].position = sf::Vector2f(100,100);
    
    quad[0].color = sf::Color::Blue;
    quad[1].color = sf::Color::Red;
    quad[2].color = sf::Color::Green;
    quad[3].color = sf::Color::Yellow;
    
    while(window->windowIsOpen())
    {
        while(window->windowPollEvent(ev))
        {
            if(ev->getEventType() == 1)
            {
                window->windowClose();
            }
        }
        
        in->inputInput();
        
        if(clc->getElapsedTime().asSeconds() >= 1)
        {
            if(in->inputCheck(0)) cout<<"UP"<<endl;
            if(in->inputCheck(1)) cout<<"DOWN"<<endl;
            if(in->inputCheck(2)) cout<<"LEFT"<<endl;
            if(in->inputCheck(3)) cout<<"RIGHT"<<endl;
            if(in->inputCheck(10)) window->windowClose();
            
            clc->restart();
        }

        lvl->testState();
        
        

        window->windowClear();
        //window->windowDraw(quad);
        window->windowDisplay();
     
    }
    }
    
    return 0;
}
