#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "RenderWindow.h"
#include "Event.h"
using namespace std;


int main() 
{
    
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    Event* ev = new Event();
    
    while(window->windowIsOpen())
    {
        while(window->windowPollEvent(ev))
        {
            if(ev->getEventType() == 666)
            {
                window->windowClose();
            }
            
            if(ev->getEventType()>0 && ev->getEventType()<100)
            {
                cout<<ev->getEventType()<<endl;
            }
            
            if(ev->getEventType()<0 && ev->getEventType()>-100)
            {
                cout<<"Suelto tecla"<<endl;
            }
        }
        
        window->windowClear();
        
        window->windowDisplay();
     
    }
    
    return 0;
}
