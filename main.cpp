#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Enemigo.h"
#include "Mapa.h"
#include <cmath>
#include "Collision.h"
#include "tinyxml2.h"

#define tMax 1.0/15.0 
using namespace std;
using namespace sf;

void input(Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Mapa *map, Jugador *j);
void update(Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Jugador *j, Mapa *map);
void render(sf::RenderWindow *window, Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Clock *clock, Mapa *map, Jugador *j);

int main() 
{
    RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 800),"Tetris FV", sf::Style::Close | sf::Style::Titlebar);
    
    Mapa *map = new Mapa(-1);
    
    Texture *tex = new Texture();
    Texture *texCono = new Texture();
    if(!tex->loadFromFile("./Textures/PlayerSheet.png") || !texCono->loadFromFile("./Textures/CampoVision.png"))
    {
        cout<<"Error: textura no encontrada"<<endl;
    }
    Sprite *spr = new Sprite(*tex);
    spr->setTextureRect(IntRect(0,0,32,32));
    spr->setOrigin(16,16);
    spr->setRotation(0);
    spr->setPosition(400, 400);
    spr->setColor(Color::Blue);
    
    Enemigo *enemy = new Enemigo(tex, texCono, 64+16, 64+16, 'r', 0, IntRect(0,0,32,32), "s");
    Enemigo *enemy2 = new Enemigo(tex, texCono, 256+16, 256+16, 'p', 0, IntRect(0,0,32,32), "eswaws");
    Enemigo *enemy3 = new Enemigo(tex, texCono, 256+16, 32*15+16, 'q', 0, IntRect(0,0,32,32), "snwsewewewewewesn");
    
    Jugador *player = new Jugador(spr, 100, 50);
    
    player->cambiaColor(sf::Color::Blue);
    
    Clock *clock = new Clock();
    
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
                    
                default: break;
            }
        }
        
        input(enemy, enemy2, enemy3, map, player);
        
        if(clock->getElapsedTime().asSeconds()>tMax)
        {
            update(enemy, enemy2, enemy3, player, map);
            clock->restart();
        }
        
        render(window, enemy, enemy2, enemy3, clock, map, player);
    }
    
    return 0;
}

void input(Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Mapa *map, Jugador *j)
{
    enemy->input(map);
    enemy2->input(map);
    enemy3->input(map);
    j->input();
}


void update(Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Jugador *j, Mapa *map)
{
    enemy->update(j, map);
    enemy2->update(j, map);
    enemy3->update(j, map);
    j->update();
}

void render(sf::RenderWindow *window, Enemigo *enemy, Enemigo *enemy2, Enemigo *enemy3, Clock *clock, Mapa *map, Jugador *j)
{
    window->clear();
    
    map->dibujar(window);
    enemy->render(window, clock, tMax);
    enemy2->render(window, clock, tMax);
    enemy3->render(window, clock, tMax);
    j->render(window, clock, tMax);
    
    window->display();
}