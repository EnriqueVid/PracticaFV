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

#define UPS 1.0f/15.0f

using namespace std;

int main()
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");

    Texture* enemyTex = new Texture("./textures/EnemyTiles.png");

    LevelFactory* lf = LevelFactory::Instance();
    Player* pl = Player::Instance();
    
    EnemyChase* enemyChase = new EnemyChase(enemyTex, sf::Vector2f(16.0f, 16.0f), sf::Vector2f(300.0f, 370.0f), sf::Vector2f(1.0f, 1.0f), "usds", 4.0f);
    
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
        
        if(clc->getClockAsSeconds() > float(1.0f/15.0f))
        {
            enemyChase->update(lf->getLevelFactoryCollisionMap());
            clc->clockRestart();
        }

        window->windowClear();

        
        
        world->render(window);
        
        window->windowInterpolateDraw(enemyChase->getConeSprite(), enemyChase->getEnemyPreviousSituation(), enemyChase->getEnemyActualSituation());
        window->windowInterpolateDraw(enemyChase->getEnemySprite(), enemyChase->getEnemyPreviousSituation(), enemyChase->getEnemyActualSituation());
        
        
        window->windowDisplay();

    }
    return 0;
}