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

#define UPS 1.0f/15.0f

using namespace std;

int main()
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    
    Event* ev = new Event();
    Input* in = Input::Instance();
    Clock* clc = new Clock();

    
    std::cout<<"Checkpoint 1"<<endl;
    
    LevelFactory* lf = LevelFactory::Instance();
    lf->setLevelFactoryStates(0);
    
    Sprite**** lftilemap = lf->getLevelFactoryTileMapSprite();
    int lfwidth = lf->getLevelFactoryWidth();
    int lfheight = lf->getLevelFactoryHeight();
    int lfnumlayers = lf->getLevelFactoryNumLayers();
    
    //cout<<lfnumlayers<<endl<<lfwidth<<endl<<lfheight<<endl;
    
    std::cout<<"Checkpoint 2"<<endl;

    
    Player* player = Player::Instance();
    std::cout<<"Checkpoint 3"<<endl;
    
    std::string path = "resources/PlayerSheet.png";
    
    Texture* playerTexture = new Texture(path);
    
    std::cout<<"Checkpoint 4"<<endl;
    
    sf::IntRect* square = new sf::IntRect(0,0,32,32);
    
    player->setPlayer(playerTexture, square,sf::Vector2f(16,16), sf::Vector2f(100,100), sf::Vector2f(1,1));
    player->setColor(sf::Color::Blue);
    
    std::cout<<"Checkpoint 5"<<endl;

    Game* lvl = new Game(StateGameLoop::Instance());
    
    Clock* clock = new Clock();
    
    Texture* texture = new Texture();
    
    int iteracion=0;
    
    Object* objeto = new Object(0, 3.0, 3.0, 37.0, false, texture);
    
    Door* door1 = new Door(1, 0.0, 0.0, 0.0, false, texture,
                            1, 4.5);
    Door* door2 = new Door(1, 0.0, 0.0, 0.0, false, texture,
                            1, 2.5);
    Switch* button1 = new Switch(1, 0.0, 0.0, 0.0, false, texture,
                                1);
    Switch* button2 = new Switch(1, 0.0, 0.0, 0.0, false, texture, 0);
    
    Box* box = new Box(1, 0.0, 0.0, 0.0, false, texture,
                        1, 2, 3.0);
    
    Sprite* meh = new Sprite(playerTexture, square,sf::Vector2f(16,16), sf::Vector2f(100,100), sf::Vector2f(1,1));
    
    while(window->windowIsOpen())
    {
        while(window->windowPollEvent(ev))
        {
            if(ev->getEventType() == 1)
            {
                window->windowClose();
            }
        }
        
        in->inputInput();
        player->input();
        
        if(clc->getClockAsSeconds() >= UPS)
        {
            /*
            if(in->inputCheck(0)) cout<<"UP"<<endl;
            if(in->inputCheck(1)) cout<<"DOWN"<<endl;
            if(in->inputCheck(2)) cout<<"LEFT"<<endl;
            if(in->inputCheck(3)) cout<<"RIGHT"<<endl;
            if(in->inputCheck(10)) window->windowClose();
            */
            player->update();
            
            if(player->getPlayer()->spriteIntersectsPixel(meh->getSpriteSprite(), 0))
            {
                cout<<"Intersecto jajajaja saludos"<<endl;
            }
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
                        button1->setDoor(door1);
        }
        if(clock->getClockAsSeconds()>9.0&&iteracion==8){
            std::cout <<"Llego aqui"<<endl;
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        if(button1->getDoor()!=NULL) button1->getDoor()->open();
        }
        if(clock->getClockAsSeconds()>10.0&&iteracion==9){
            iteracion = iteracion + 1;
                        std::cout <<"==========================================" << endl;
                        //button1->getDoor()->close();
                        door1->interact();
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
        
        window->windowClear();
        
        
        
        for (int l=1; l<lfnumlayers; l++)
        {
            for (int y=0; y<lfheight; y++)
            {
                for(int x=0; x<lfwidth; x++)
                {
                    if(lftilemap[l][y][x] != NULL)
                        window->windowDraw(lftilemap[l][y][x]);
                }
            }
        }
        
        
        window->windowDraw(meh);
        
        player->render(window, clc, UPS);
        
        
        window->windowDisplay();
        
        if(door1!=NULL){
            door1->update();
        }
        if(door2!=NULL) door2->update();
        if(box!=NULL) box->update();
       
        
    }
    return 0;
}