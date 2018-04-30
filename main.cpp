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
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");

    Texture* enemyTex = new Texture("./textures/EnemyTiles.png");
    /*
    bool dado = false;
    
    Astar* astar;
    
    int** map;
    
    int width = 25;
    int height = 25;
    
    sf::Vector2i start;
    sf::Vector2i end;
    
    start.x = 0;
    start.y = 0;
    
    end.x = 20;
    end.y = 0;
    
    map = new int*[width];
    for(int i=0;i<width;i++)
    {
        map[i] = new int[height];
        for(int j=0;j<height;j++)
        {
            map[i][j] = 1;
        }
    }
    */
    Texture* playerTex = new Texture("./textures/PlayerTiles.png");

    LevelFactory* lf = LevelFactory::Instance();
    
    Player* pl = Player::Instance();
    
    
    
    /*
    Hud* hud = Hud::Instance();
    
    hud->setSprites(playerTex);
    
    hud->update(256,100, 0, 255, 255, 255);
    
     */ 
    //astar = new Astar(map, width, height, 8);
    
    //string meh = astar->pathfind(start, end);
    
    Event* ev = new Event();
    Input* in = Input::Instance();
    Clock* clc = new Clock();
    
    window->setWindowFramerateLimit(60);
    
    std::cout<<"Checkpoint 1"<<endl;
    
    World* world = World::Instance();
    
    world->buildTestObjects();
    
    //enemyBounce->update();
    
    while(window->windowIsOpen())
    {
        while(window->windowPollEvent(ev))
        {
            if(ev->getEventType() == 1)
            {
                window->windowClose();
            }
        }
        
        world->update();
        

        window->windowClear();
        
        
        
        world->render(window);
         
        /*
        if(in->inputCheck(12) && !dado)
        {
            dado=true;
            cout<<"Revisando A* al pulsar espacio"<<endl;
            for(int i=0;i<width;i++)
            {
                for(int j=0;j<height;j++)
                {
                    cout<<map[i][j];
                }
                cout<<endl;
            }
            
            cout<<meh<<endl;
        }
        */
        /**
        window->windowDraw(hud->getLife());
        window->windowDraw(hud->getRectangle());
        window->windowDraw(hud->getStamina());
         */ 
        
        window->windowDisplay();
        
    }
    return 0;
}