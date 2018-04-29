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

#define UPS 1.0f/15.0f

using namespace std;

int main()
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");

    Texture* enemyTex = new Texture("./textures/EnemyTiles.png");
    
    Texture* playerTex = new Texture("./textures/PlayerTiles.png");

    EnemyBounce* enemyBounce = new EnemyBounce(enemyTex, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(300.0f, 300.0f), sf::Vector2f(1.0f, 1.0f), "udlr");
    
    Hud* hud = Hud::Instance();
    
    hud->setSprites(playerTex);
    
    hud->update(256,100, 0, 255, 255, 255);
    
    
    
    Event* ev = new Event();
    Input* in = Input::Instance();
    Clock* clc = new Clock();
    
    window->setWindowFramerateLimit(60);
    
    std::cout<<"Checkpoint 1"<<endl;
    
    World* world = World::Instance();
    
    world->buildTestObjects();
    
    enemyBounce->update();
    
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
        window->windowInterpolateDraw(enemyBounce->getEnemySprite(), enemyBounce->getEnemyPreviousSituation(), enemyBounce->getEnemyActualSituation());
        
        if(in->inputCheck(12))
        {
            hud->update(200, 50, 255, 255, 0, 255);
            cout<<"Revisando hud"<<endl;
            cout<<hud->getLife()->getBox()->height<<endl;
            cout<<hud->getLife()->getBox()->width<<endl;
            cout<<hud->getLife()->getSpritePosition().x<<endl;
            cout<<hud->getLife()->getSpritePosition().y<<endl;
        }
        window->windowDraw(hud->getLife());
        window->windowDraw(hud->getRectangle());
        window->windowDraw(hud->getStamina());
        
        window->windowDisplay();

    }
    return 0;
}