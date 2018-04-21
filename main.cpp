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

#define UPS 1.0f/15.0f


using namespace std;

int main() 
{
    RenderWindow* window = new RenderWindow(800, 800, "Esto es una prueba");
    Event* ev = new Event();
    Input* in = Input::Instance();
    Clock* clc = new Clock();
    
    Player* player = Player::Instance();
    std::cout<<"Jugador creado correctamente"<<endl;
    
    std::string path = "resources/PlayerSheet.png";
    
    Texture* playerTexture = new Texture(path);
    
    sf::IntRect* square = new sf::IntRect(0,0,32,32);
    
    
    player->setPlayer(playerTexture, square,sf::Vector2f(16,16), sf::Vector2f(16,16), sf::Vector2f(1,1));
    
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
    Switch* button2 = new Switch(1, 0.0, 0.0, 0.0, false, texture,
                                0);  

    sf::VertexArray quad(sf::Quads,4);
    
    quad[0].position = sf::Vector2f(100,60);
    quad[1].position = sf::Vector2f(400,60);
    quad[2].position = sf::Vector2f(400,200);
    quad[3].position = sf::Vector2f(100,100);
    
    quad[0].color = sf::Color::Blue;
    quad[1].color = sf::Color::Red;
    quad[2].color = sf::Color::Green;
    quad[3].color = sf::Color::Yellow;
    
     

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
        
        if(clc->getClockAsSeconds() >= 1)
        {
            if(in->inputCheck(0)) cout<<"UP"<<endl;
            if(in->inputCheck(1)) cout<<"DOWN"<<endl;
            if(in->inputCheck(2)) cout<<"LEFT"<<endl;
            if(in->inputCheck(3)) cout<<"RIGHT"<<endl;
            if(in->inputCheck(10)) window->windowClose();
            
            player->update();
            
            clc->clockRestart();
        }

        //lvl->testState();
        
        if(clock->getClockAsSeconds()>1.0&&iteracion==0){
            iteracion = iteracion + 1;
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
        window->windowClear();
        //window->windowDraw(quad);
        
        player->render(window, clc, 1.0f);
        window->windowDisplay();
        
        door1->update();
        door2->update();
        
    }
    return 0;
}
