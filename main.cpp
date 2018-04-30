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
    
    bool dado = false;
    
    Astar* astar;
    
    int** map;
    
    int width = 25;
    int height = 25;
    
    int* _dirX;
    int* _dirY;
    
    sf::Vector2i start;
    sf::Vector2i end;
    sf::Vector2i* camino;
    
        _dirX = new int[8];
        _dirY = new int[8];
        
        _dirX[0] = 1;
        _dirY[0] = 0;
        
        _dirX[1] = 1;
        _dirY[1] = 1;
        
        _dirX[2] = 0;
        _dirY[2] = 1;
        
        _dirX[3] = -1;
        _dirY[3] = 1;
        
        _dirX[4] = -1;
        _dirY[4] = 0;
        
        _dirX[5] = -1;
        _dirY[5] = -1;
        
        _dirX[6] = 0;
        _dirY[6] = -1;
        
        _dirX[7] = 1;
        _dirY[7] = -1;
    
    start.x = 1;
    start.y = 1;
    
    end.x = 10;
    end.y = 10;
    
    map = new int*[height];
    for(int i=0;i<height;i++)
    {
        map[i] = new int[width];
        for(int j=0;j<width;j++)
        {
            map[i][j] = 1;
        }
    }
    
    Texture* playerTex = new Texture("./textures/PlayerTiles.png");

    LevelFactory* lf = LevelFactory::Instance();
    
    Player* pl = Player::Instance();
    
    EnemyChase* enemyChase = new EnemyChase(enemyTex, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(300.0f, 370.0f), sf::Vector2f(1.0f, 1.0f), "usds", 4.0f);
    
    
    Hud* hud = Hud::Instance();
    
    hud->setSprites(playerTex);
    
    hud->update(256,100, 0, 255, 255, 255);
    
    map[2][2] = 2;

    astar = new Astar(map, width, height, 8);
    
    string meh = astar->pathfind(start, end);
    
    camino = new sf::Vector2i[meh.size()];
    
    for(int i=0;i<meh.size();i++)
    {
        if(i==0)
        {
            int m = meh.at(i);
            cout<<m<<endl;
            camino[i].x = _dirX[meh.at(i)-48] + start.x;
            camino[i].y = _dirY[meh.at(i)-48] + start.y;
        }else
        {
            camino[i].x = _dirX[meh.at(i)-48] + camino[i-1].x;
            camino[i].y = _dirY[meh.at(i)-48] + camino[i-1].y;
        }
    }
    
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

        
        window->windowInterpolateDraw(enemyChase->getConeSprite(), enemyChase->getEnemyPreviousSituation(), enemyChase->getEnemyActualSituation());
        window->windowInterpolateDraw(enemyChase->getEnemySprite(), enemyChase->getEnemyPreviousSituation(), enemyChase->getEnemyActualSituation());

        if(in->inputCheck(12) && !dado)
        {
            dado=true;
            cout<<"Revisando A* al pulsar espacio"<<endl;
            
            
            map[start.y][start.x] = 3;
            map[end.y][end.x] = 3;
            map[2][2] = 2;
            for(int i=0;i<height;i++)
            {
                for(int j=0;j<width;j++)
                {
                    cout<<map[i][j];
                }
                cout<<endl;
            }
            
            cout<<meh<<endl;
            for(int i=0;i<meh.size();i++)
            {
                cout<<camino[i].x<<", "<<camino[i].y<<endl;
            }
        }

        
        window->windowDraw(hud->getLife());
        window->windowDraw(hud->getRectangle());
        window->windowDraw(hud->getStamina());
        
        
        window->windowDisplay();
        
    }
    return 0;
}