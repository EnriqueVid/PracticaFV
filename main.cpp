#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Game.h"
#include "State.h"
#include "StateGameLoop.h"

using namespace std;

int main() 
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 800),"Color of Fate", sf::Style::Close | sf::Style::Titlebar);
    
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
                    
                case sf::Event::KeyReleased:
                        lvl->StateChanged();                        
                    break;
                default: break;
            } 
        }
        
        lvl->testState();

        window->clear();
        window->draw(quad);
        
        window->display();
    }
    
    return 0;
}
