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
    
    Astar* astar;
    
    int** map;
    
    int width = 25;
    int height = 25;
    
    int* _dirX;
    int* _dirY;
    
    sf::Vector2i start;
    sf::Vector2i end;
    sf::Vector2i* camino;
    
    start.x = 10;
    start.y = 0;
    
    end.x = 0;
    end.y = 0;
    
    map = new int*[height];
    for(int i=0;i<height;i++)
    {
        
        map[i] = new int[width];
        for(int j=0;j<width;j++)
        {
            map[i][j] = 1;
        }
    }
    
    for(int i=0;i<height;i++)
    {
        
        for(int j=0;j<width;j++)
        {
            map[2][i] = 2;
        }
    }

    
    map[2][2] = 2;
    
    
    

    astar = new Astar(map, width, height, 8);
    
    
    string meh = astar->pathfind(start, end);
    
    camino = astar->getAbsoluto(meh);
    
            map[start.y][start.x] = 3;
            map[end.y][end.x] = 3;
            map[2][2] = 2;
            for(int i=0;i<height;i++)
            {
                for(int j=0;j<width;j++)
                {
                    bool entra = false;
                    for(int z=0;z<meh.size();z++)
                    {
                        
                        if((camino[z].y == i && camino[z].x == j) && !entra)
                        {
                            if(map[j][i] != 2){
                            cout<<'X';
                            entra = true;
                            }
                        }
                    }
                    if(!entra){
                        cout<<map[j][i];
                    }
                }
                cout<<endl;
            }
            
            cout<<meh<<endl;
            
            
            
            for(int i=0;i<meh.size();i++)
            {
                cout<<camino[i].x<<", "<<camino[i].y<<endl;
            }
    
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
            _pos.x = 300;
            _pos.y = 300;
            
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