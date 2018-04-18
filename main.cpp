#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "RenderWindow.h"
#include "Event.h"
#include "Input.h"

#define UPS 1.0f/15.0f

using namespace std;

sf::Clock* clc;

int main() 
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    Event* ev = new Event();
    Input* in = Input::Instance();
    clc = new sf::Clock();
    
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
        
        
        
        window->windowClear();
        
        window->windowDisplay();
     
    }
    
    return 0;
}
