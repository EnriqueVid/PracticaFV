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
#include "Bullet.h"
#include "World.h"

#define UPS 1.0f/15.0f

using namespace std;

int main()
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    
    Event* ev = new Event();
    Input* in = Input::Instance();
    Clock* clc = new Clock();
    
    window->setWindowFramerateLimit(60);
    
    std::cout<<"Checkpoint 1"<<endl;
    
    /*
    LevelFactory* lf = LevelFactory::Instance();
    lf->setLevelFactoryStates(0);
    
    Sprite**** lftilemap = lf->getLevelFactoryTileMapSprite();
    int lfwidth = lf->getLevelFactoryWidth();
    int lfheight = lf->getLevelFactoryHeight();
    int lfnumlayers = lf->getLevelFactoryNumLayers();
        
    std::cout<<"Checkpoint 2"<<endl;
    
    Player* player = Player::Instance();
    
    std::cout<<"Checkpoint 3"<<endl;
    
    std::string path = "textures/PlayerTiles.png";

    std::string pathObject = "textures/ObjectTiles.png";

    std::string pathBullet = "textures/BulletTiles.png";

    std::string pathButton = "textures/TexturaBotonTemporal.png";
    
    Texture* playerTexture = new Texture(path);
    Texture* bulletTexture = new Texture(pathBullet);
    Texture* objectTexture = new Texture(pathObject);
    Texture* buttonTexture = new Texture(pathButton);
    
    std::cout<<"Checkpoint 4"<<endl;
    
    sf::IntRect* square = new sf::IntRect(0,0,32,32);
    
    player->setPlayer(playerTexture, square,sf::Vector2f(16,16), sf::Vector2f(100,100), sf::Vector2f(1,1));
    
    player->setColor(sf::Color::Cyan);
    
    //PRUEBA MESSAGE
    
    Texture* texturebox = new Texture("./textures/fondotexto.png");
    Font* font = new Font("./textures/Pixeled.ttf");
    Message* mes = new Message(0, font , texturebox, player->getPlayer()->getGlobalBounds(), player->getPlayer()->getSpritePosition());
    
    
    std::cout<<"Checkpoint 5"<<endl;

    Game* lvl = new Game(StateGameLoop::Instance());
    
    Clock* clock = new Clock();
    
    Texture* texture = new Texture();
    
    int iteracion=0;
    
    Object* objeto = new Object(0, 3.0, 3.0, 37.0, false, objectTexture);
    
    Door* door1 = new Door(1, 352.0, 320.0+64, 0.0, false, objectTexture,
                            0, 4.5, 1.0);
    Door* door2 = new Door(1, 352.0, 352.0+64, 0.0, false, objectTexture,
                            1, 4.5, 1.0);
    Switch* button1 = new Switch(1, 160.0, 200.0, 0.0, false, buttonTexture,
                                1);
    Switch* button2 = new Switch(1, 0.0, 0.0, 0.0, false, buttonTexture, 
            0);
    
    Box* box = new Box(1, 160.0, 360.0, 0.0, false, objectTexture,
                        1, 2, 3.0);
    
    Bullet* bullet = new Bullet(true,40.0f,40.0f,0.0f,1.0f,2.0f,1,bulletTexture);
    
    sf::RectangleShape boundsPlayer;
    sf::RectangleShape boundsBox;
    
    boundsPlayer.setSize(sf::Vector2f(32.0f,32.0f));
    boundsBox.setSize(sf::Vector2f(64.0f,64.0f));
    
    boundsPlayer.setFillColor(sf::Color::Red);
    boundsBox.setFillColor(sf::Color::Green);
    
    boundsPlayer.setOrigin(16.0f,16.0f);
    boundsBox.setOrigin(32.0f,32.0f);
    
    //Sprite* meh = new Sprite(playerTexture, square,sf::Vector2f(16,16), sf::Vector2f(100,100), sf::Vector2f(1,1));
    
    */ 
    
    World* world = World::Instance();
    
    //world->buildTestObjects();
    
    world->buildTestObjects();
    
    
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
        
        window->windowDisplay();
        
        /*
        
        in->inputInput();
        player->input();
        
        if(clc->getClockAsSeconds() >= UPS)
        {
            
            if(in->inputCheck(0)) cout<<"UP"<<endl;
            if(in->inputCheck(1)) cout<<"DOWN"<<endl;
            if(in->inputCheck(2)) cout<<"LEFT"<<endl;
            if(in->inputCheck(3)) cout<<"RIGHT"<<endl;
            if(in->inputCheck(10)) window->windowClose();
            
            player->update();
            
           // if(player->getPlayer()->spriteIntersectsPixel(meh->getSpriteSprite(), 0))
           // {
           //     cout<<"Intersecto jajajaja saludos"<<endl;
           // }
           clc->clockRestart();
        }
        //lvl->testState();
        
        if(clock->getClockAsSeconds()>1.0&&iteracion==0){
            iteracion = iteracion + 1;
            objeto->newSituation(9.0,9.0,9.0);
            std::cout << "Situacion actual: "<<objeto->getActualSituation()->getPosition().x<< " , " <<
                   objeto->getActualSituation()->getPosition().y <<"Angle: " << objeto->getActualSituation()->getAngle()<< endl;
            std::cout << "Situacion anterior:" << objeto->getPreviousSituation()->getPosition().x << ", " <<
                    objeto->getPreviousSituation()->getPosition().y << "Angle: " << objeto->getPreviousSituation()->getAngle()<<endl;
        }
        if(clock->getClockAsSeconds()>2.0&&iteracion==1){
            iteracion = iteracion + 1;
            std::cout <<"==========================================" << endl;
            objeto->newSituation(1.0,2.0,3.0);
            std::cout << "Situacion actual: "<<objeto->getActualSituation()->getPosition().x<< " , " <<
                   objeto->getActualSituation()->getPosition().y <<"Angle: " << objeto->getActualSituation()->getAngle()<< endl;
            std::cout << "Situacion anterior:" << objeto->getPreviousSituation()->getPosition().x << ", " <<
                    objeto->getPreviousSituation()->getPosition().y << "Angle: " << objeto->getPreviousSituation()->getAngle()<<endl;            
            
        }
        if(clock->getClockAsSeconds()>3.0&&iteracion==2){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
            objeto->setActualSituation(5.0,5.0,5.0);
            std::cout << "Situacion actual: "<<objeto->getActualSituation()->getPosition().x<< " , " <<
                   objeto->getActualSituation()->getPosition().y <<"Angle: " << objeto->getActualSituation()->getAngle()<< endl;
            std::cout << "Situacion anterior:" << objeto->getPreviousSituation()->getPosition().x << ", " <<
                    objeto->getPreviousSituation()->getPosition().y << "Angle: " << objeto->getPreviousSituation()->getAngle()<<endl;            
        }
        
        if(clock->getClockAsSeconds()>4.0&&iteracion==3){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
            objeto->setPreviousSituation(7.0,7.0,7.0);
            std::cout << "Situacion actual: "<<objeto->getActualSituation()->getPosition().x<< " , " <<
                   objeto->getActualSituation()->getPosition().y <<"Angle: " << objeto->getActualSituation()->getAngle()<< endl;
            std::cout << "Situacion anterior:" << objeto->getPreviousSituation()->getPosition().x << ", " <<
                    objeto->getPreviousSituation()->getPosition().y << "Angle: " << objeto->getPreviousSituation()->getAngle()<<endl;            
        }
        if(clock->getClockAsSeconds()>5.0&&iteracion==4){
            iteracion = iteracion + 1;          
            std::cout <<"==========================================" << endl;
                        
            std::cout <<"¿Puede moverse?" <<objeto->getCanBeMoved() <<endl;
            std::cout << "¿Que tipo de objeto es?" <<objeto->getObjectType() <<endl;
            std::cout << "¿Hay sprite?" <<objeto->getSprite() <<endl;
        }
        if(clock->getClockAsSeconds()>6.0&&iteracion==5){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        button1->activate();
        }
        
        if(clock->getClockAsSeconds()>7.0&&iteracion==6){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        button1->deactivate();
        }
         
        if(clock->getClockAsSeconds()>8.0&&iteracion==7){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        button1->setDoor(door1,door2);
        }
        if(clock->getClockAsSeconds()>9.0&&iteracion==8){
            std::cout <<"Llego aqui"<<endl;
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        //button1->activate();
        }
        if(clock->getClockAsSeconds()>10.0&&iteracion==9){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        //button1->getDoor()->close();
        }
        if(clock->getClockAsSeconds()>11.0&&iteracion==10){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        std::cout << box->getSpeed() <<std::endl;
                        std::cout << box->getVt() <<std::endl;
                        std::cout << box->getBreakAnimation() <<std::endl;
        }
        if(clock->getClockAsSeconds()>13.0&&iteracion==11){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        box->impact();
                        std::cout << box->getVt() <<std::endl;
        }
        if(clock->getClockAsSeconds()>15.0&&iteracion==12){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        box->impact();
                        std::cout << box->getVt() <<std::endl;
        }
        if(clock->getClockAsSeconds()>17.0&&iteracion==13){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        box->impact();
                        std::cout << box->getVt() <<std::endl;
        }
        if(clock->getClockAsSeconds()>19.0&&iteracion==14){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        box->breakBox();
                        std::cout << box->getBreakAnimation() <<std::endl;
                        std::cout << box->getBreakAnimationFrame() <<std::endl;
        }
        if(box!=NULL){
            if(clock->getClockAsSeconds()>20.0&&box->getErase()&&iteracion==15){
                iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;

                        delete box;
                        box=NULL;
                        
                        delete button1;
                        button1=NULL;
                        
                        delete button2;
                        button2=NULL;

                        delete door1;
                        door1=NULL;
                        
                        delete door2;
                        door2=NULL;
                        
                        delete objeto;
                        objeto=NULL;
            }
        }
        
        float percenTick = min(1.0f, clc->getClockAsSeconds() / float(UPS));
        
        window->updatePercentTick(percenTick);
        
        window->windowClear();
        
        for (int y=0; y<lfheight; y++)
            {
                for(int x=0; x<lfwidth; x++)
                {
                    if(lftilemap[1][y][x] != NULL)
                        window->windowDraw(lftilemap[1][y][x]);
                }
            }
        
        //window->windowDraw(meh);
        
        if(bullet!=NULL){
            bullet->update();
        }
        if(door1!=NULL){
            door1->update();
        }
        if(door2!=NULL) door2->update();
        if(box!=NULL) box->update();
                
        if(bullet!=NULL){
            if(bullet->getErase()){
                delete bullet;
                bullet = NULL;
            }
        }
        

        
        
        if(box!=NULL){
            boundsPlayer.setPosition(player->getPlayer()->getSpritePosition().x , player->getPlayer()->getSpritePosition().y);
            boundsBox.setPosition(box->getSprite()->getSpritePosition().x , box->getSprite()->getSpritePosition().y);
        
        }
        
        window->getWindowWindow()->draw(boundsPlayer);
        window->getWindowWindow()->draw(boundsBox);
        
        
        if(box!=NULL){
        if(player->getPlayer()->spriteIntersectsBounds(box->getSprite())){
            cout <<"Activando boton"<<endl;
            button1->activate();
        }
        }        
        
        
        if(box!=NULL){
            if(box->getErase()){
                delete box;
                box=NULL;
            }
        }
        
        
        

        //cout << box->getActualSituation()->getPositionX() <<" , " << box->getActualSituation()->getPositionY()<< endl;

        if(box!=NULL){
            box->update();
            box->render(window, clc, UPS);
        }
        
        //cout << button1->getActualSituation()->getPositionX() <<" , " << button1->getActualSituation()->getPositionY()<< endl;
        
        if(button1!=NULL){
            button1->update();
            button1->render(window,clc,UPS);        
        }
        
        door1->render(window,clc,UPS);
        
        door2->render(window,clc,UPS);
        
        if(bullet!=NULL){
            bullet->render(window,clc,UPS);            
        }

        //window->windowDraw(mes);
        //player->render(window, clc, UPS);
        window->windowInterpolateDraw(player->getPlayer(), player->getPreviousSituation(), player->getActualSituation());

        window->windowDraw(mes);

        
        //window->windowDraw(box->getSprite());
        for (int y=0; y<lfheight; y++)
            {
                for(int x=0; x<lfwidth; x++)
                {
                    if(lftilemap[2][y][x] != NULL)
                        window->windowDraw(lftilemap[2][y][x]);
                }
            }

        window->windowDisplay();
        
        

       */
        
        
        
        
        
    }
    return 0;
}