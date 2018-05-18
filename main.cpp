#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "RenderWindow.h"
#include "Event.h"
#include "Input.h"
#include "Clock.h"
#include "Game.h"
#include "State.h"
#include "StateGameLoop.h"
#include "StateStart.h"
#include "StateGameOver.h"
#include "Object.h"
#include "Box.h"
#include "Switch.h"
#include "Door.h"
#include "Player.h"
#include "Texture.h"
#include "LevelFactory.h"
#include "Font.h"
#include "Text.h"
#include "Message.h"
#include "EnemyBounce.h"
#include "Bullet.h"
#include "World.h"
#include "Hud.h"
#include "Astar.h"

#define UPS 1.0f/15.0f

using namespace std;

int main()
{
    RenderWindow* window = RenderWindow::Instance();

    StateStart::Instance();
    
    int which = StateStart::Instance()->getStateNumber();

    
            //Quitar
            Texture* _texture = new Texture("./textures/fondotexto.png");
            
            int _number = 1;
            
            sf::Font _font;
            _font.loadFromFile("./textures/Pixeled.ttf");
            
            sf::FloatRect _box;
            _box.height = 100;
            _box.width = 100;
            _box.left = 300;
            _box.top = 300;
            
            sf::Vector2f _pos;
            _pos.x = 50;
            _pos.y = 50;
            
            Message* _message = new Message(_number, _font, _texture, _box, _pos);
            
            cout<<_message->getSpriteMessage()->getSpritePosition().x<<endl;
            cout<<_message->getTextMessage()->getPosition().x<<endl;
            cout<<_message->getTextMessage()->getPosition().y<<endl;
        
    
    Event* ev = new Event();
    while(window->windowIsOpen())
    {
        while(window->windowPollEvent(ev))
        {
            if(ev->getEventType() == 1)
            {
                window->windowClose();
            }
        }
        
        if(which == 1)
        {
            which = StateStart::Instance()->update(window);
            
        }else if(which == 2)
        {   
            which = StateGameLoop::Instance()->update(window);
            
            window->windowClear();
            StateGameLoop::Instance()->render(window);
            
            //Quitar
            window->windowDraw(_message);
            window->windowDisplay();
        }
        else
        {
            which = StateGameOver::Instance()->update(window);
            
        }
        
    }
    return 0;
}