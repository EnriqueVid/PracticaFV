#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;


int main() 
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 800),"Color of Fate", sf::Style::Close | sf::Style::Titlebar);
    
    while(window->isOpen())
    {
        sf::Event ev;
        while(window->pollEvent(ev))
        {
            switch(ev.type)
            {
                case sf::Event::Closed: 
                    window->close();
                    break;
                    
                default: break;
            }
        }
        
        window->clear();
        
        window->display();
    }
    
    return 0;
}
