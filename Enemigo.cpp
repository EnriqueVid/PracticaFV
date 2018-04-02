/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.cpp
 * Author: newman
 * 
 * Created on 26 de marzo de 2018, 0:58
 */

#include "Enemigo.h"

Enemigo::Enemigo(Texture *tex, Texture *texCono, int x, int y, char t, int rot, IntRect rect, string d) 
{
    spr.setTexture(*tex);
    spr.setTextureRect(rect);
    spr.setPosition(x, y);
    spr.setOrigin(rect.width/2, rect.height/2);
    spr.setRotation(rot);
    pasado = new Estado(spr.getPosition().x, spr.getPosition().y, spr.getRotation());
    futuro = new Estado(spr.getPosition().x, spr.getPosition().y, spr.getRotation());
    tipo = t;
    patAct = -1;
    estado = 'n';
    
    if(tipo != 'r')
    {
        cono = new Sprite();
        cono->setTexture(*texCono);
        cono->setPosition(spr.getPosition().x, spr.getPosition().y);
        cono->setOrigin(60, 0);
        clk.restart();
        patAct = 0;
    }
    
    switch(tipo)
    {
        case 'r': //Rebotar
            vel = 10;
            dir = d.at(0);
            break;
            
        case 'q': //Quieto
            vel = 0;
            patron = d;
            break;
            
        case 'p':
            vel = 5;
            patron = d;
            break;
            
        default:
            vel = 0;
            break;
    }
    
}

Enemigo::Enemigo(const Enemigo& orig) 
{
    
}

Enemigo::~Enemigo() 
{
    
}

void Enemigo::input(Mapa *map)
{
    switch(tipo)
    {
        case 'r': //Rebotar
            if(dir == 'e')
            {
                if(map->getCasilla(spr.getPosition().x+16+vel, spr.getPosition().y+16)!=1 || map->getCasilla(spr.getPosition().x+16+vel, spr.getPosition().y-16)!=1)
                {
                    eje_x = 1;
                    eje_y = 0;
                }
                else
                {
                    while(map->getCasilla(spr.getPosition().x+16+1, spr.getPosition().y+16)!=1 || map->getCasilla(spr.getPosition().x+16+1, spr.getPosition().y-16)!=1)
                    {
                        spr.setPosition(spr.getPosition().x+1, spr.getPosition().y);
                    }
                    futuro->setEstado(spr.getPosition().x+1, spr.getPosition().y);
                    dir = 'w';
                }
            }
            else if(dir == 'w')
            {
                if(map->getCasilla(spr.getPosition().x-16-vel, spr.getPosition().y+16)!=1 || map->getCasilla(spr.getPosition().x-16-vel, spr.getPosition().y-16)!=1)
                {
                    eje_x = -1;
                    eje_y = 0;
                }
                else
                {
                    while(map->getCasilla(spr.getPosition().x-16-1, spr.getPosition().y+16)!=1 || map->getCasilla(spr.getPosition().x-16-1, spr.getPosition().y-16)!=1)
                    {
                        spr.setPosition(spr.getPosition().x-1, spr.getPosition().y); 
                    }
                    futuro->setEstado(spr.getPosition().x-1, spr.getPosition().y);
                    dir = 'e';
                }
            }
            else if(dir == 'n')
            {
                if(map->getCasilla(spr.getPosition().x-16, spr.getPosition().y-16-vel)!=1 || map->getCasilla(spr.getPosition().x+16, spr.getPosition().y-16-vel)!=1)
                {
                    eje_x = 0;
                    eje_y = -1;
                }
                else
                {
                    while(map->getCasilla(spr.getPosition().x-16, spr.getPosition().y-16-1)!=1 || map->getCasilla(spr.getPosition().x+16, spr.getPosition().y-16-1)!=1)
                    {
                        spr.setPosition(spr.getPosition().x, spr.getPosition().y-1); 
                    }
                    futuro->setEstado(spr.getPosition().x, spr.getPosition().y-1);
                    dir = 's';
                }
            }
            else if(dir == 's')
            {
                if(map->getCasilla(spr.getPosition().x-16, spr.getPosition().y+16+vel)!=1 || map->getCasilla(spr.getPosition().x+16, spr.getPosition().y+16+vel)!=1)
                {
                    eje_x = 0;
                    eje_y = 1;
                }
                else
                {
                    while(map->getCasilla(spr.getPosition().x-16, spr.getPosition().y+16+1)!=1 || map->getCasilla(spr.getPosition().x+16, spr.getPosition().y+16+1)!=1)
                    {
                        spr.setPosition(spr.getPosition().x, spr.getPosition().y+1); 
                    }
                    futuro->setEstado(spr.getPosition().x, spr.getPosition().y+1);
                    dir = 'n';
                }
            }
            else
            {
                eje_x = 0;
                eje_y = 0;
            }
            break;
            
        case 'q': //Quieto
            
            if(estado == 'n')
            {
                if(clk.getElapsedTime().asSeconds()>3)
                {
                    if(patAct>=patron.length()) patAct = 0;

                    switch(patron.at(patAct))
                    {
                        case 'n':
                            eje_x = 0;
                            eje_y = -1;
                            break;

                        case 's':
                            eje_x = 0;
                            eje_y = 1;
                            break;

                        case 'e':
                            eje_x = 1;
                            eje_y = 0;
                            break;

                        case 'w':
                            eje_x = -1;
                            eje_y = 0;
                            break;
                    }

                }

                if(clk.getElapsedTime().asSeconds()>6)
                {
                    eje_x = 0;
                    eje_y = 0;
                    patAct++;
                    clk.restart();
                }
            }
            
            break;
        
        case 'p': //Quieto
            if(estado == 'n'){
                vel = 5;
                if(clk.getElapsedTime().asSeconds()>3)
                {
                    if(patAct>=patron.length()) patAct = 0;

                    switch(patron.at(patAct))
                    {
                        case 'n':
                            eje_x = 0;
                            eje_y = -1;
                            break;

                        case 's':
                            eje_x = 0;
                            eje_y = 1;
                            break;

                        case 'e':
                            eje_x = 1;
                            eje_y = 0;
                            break;

                        case 'w':
                            eje_x = -1;
                            eje_y = 0;
                            break;
                    }

                }

                if(clk.getElapsedTime().asSeconds()>6)
                {
                    eje_x = 0;
                    eje_y = 0;
                    patAct++;
                    clk.restart();
                }
            }
            else
            {
                vel = 13;
            }
            break;
    }
}

void Enemigo::update(Jugador *jug, Mapa *map)
{   
    spr.setPosition(futuro->getEstado());
    spr.setRotation(futuro->getGrados());
        
    pasado = new Estado(futuro->getEstado().x, futuro->getEstado().y, futuro->getGrados());
    
    if(tipo == 'r' && Collision::PixelPerfectTest(*jug->getPersonaje(), spr, 0))
    {
        estado = 'x';
    }
    
    if(tipo != 'r' && Collision::PixelPerfectTest(*jug->getPersonaje(), *cono, 0) && (map->getCasilla(jug->getPersonaje()->getPosition().x, jug->getPersonaje()->getPosition().y)) != jug->getColor())
    {
        
        jug->bajavida(1.0f);
        
        
        estado = 'a';
        if(tipo == 'q')
        {
            mirar(jug->getPersonaje()->getPosition().x, jug->getPersonaje()->getPosition().y);
        }
        else if(tipo == 'p')
        {
            mirar(jug->getPersonaje()->getPosition().x, jug->getPersonaje()->getPosition().y);
            perseguir(jug->getPersonaje()->getPosition().x, jug->getPersonaje()->getPosition().y);
        }
    }
    else if(estado == 'x')
    {
        eje_x = 0;
        eje_y = 0;
        dir_x=eje_x;
        dir_y=eje_y;
    }
    else
    {
        estado = 'n';
        //arriba-derecha
        spr.setRotation(((int)spr.getRotation()/10)*10);

        if(eje_x==1&&eje_y==-1)
        {
            spr.move(vel*sin(45),-vel*sin(45));

            dir_x=eje_x;
            dir_y=eje_y;
        }
        else if(eje_x==1&&eje_y==1)//abajo derecha
        {
            spr.move(vel*sin(45),vel*sin(45));

            dir_x=eje_x;
            dir_y=eje_y;
        }
        else if(eje_x==-1&&eje_y==-1)//arriba izquierda
        {
            spr.move(-vel*sin(45),-vel*sin(45));

            dir_x=eje_x;
            dir_y=eje_y;
        }
        else if(eje_x==-1&&eje_y==1)//abajo izquierda
        {
            spr.move(-vel*sin(45),vel*sin(45));

            dir_x=eje_x;
            dir_y=eje_y;
        }
        else if(eje_x==1)//derecha
        {
            spr.move(vel,0);
            //cout<<vel<<endl;

            dir_x=eje_x;
            dir_y=0;
        }
        else if(eje_x==-1)//izquierda
        {
            spr.move(-vel,0);

            dir_x=eje_x;
            dir_y=0;
        }
        else if(eje_y==-1)
        { //arriba
            spr.move(0,-vel);  

            dir_x=0;
            dir_y=eje_y;
        }
        else if(eje_y==1)//abajo
        {
            spr.move(0,vel);

            dir_x=0;
            dir_y=eje_y;
        }





        if(dir_x==1&&dir_y==-1)//arriba-derecha
        {
            if(spr.getRotation()<135)
            {
                pasado->setGrados(spr.getRotation()+360);
            }
            spr.setRotation(225);

        }
        else if(dir_x==1 && dir_y==1)//abajo derecha
        {
            if(spr.getRotation()>225)
            {
                pasado->setGrados(spr.getRotation()-360);
            }
            spr.setRotation(315);
        }
        else if(dir_x==-1 && dir_y==-1)//arriba izquierda
        {
            spr.setRotation(135);
        }
        else if(dir_x==-1 && dir_y==1)//abajo izquierda
        {
            spr.setRotation(45);
        }
        else if(dir_x==1)//derecha
        {
            if(spr.getRotation()==0)
            {
                pasado->setGrados(spr.getRotation()+360);
            }

            if(spr.getRotation() < 270 && spr.getRotation() >= 90)
            {
                spr.rotate(10);
            }
            else if(spr.getRotation() > 270 || spr.getRotation() < 90)
            {
                spr.rotate(-10);
            }
        }
        else if(dir_x==-1)//izquierda
        {
            if(spr.getRotation()==350)
            {
                pasado->setGrados(spr.getRotation()-360);
            }

            if(spr.getRotation() < 90 || spr.getRotation() >= 270)
            {
                spr.rotate(10);
            }
            else if(spr.getRotation() > 90 && spr.getRotation() < 270)
            {
                spr.rotate(-10);
            }

        }
        else if(dir_y==-1)//arriba
        { 

            if(spr.getRotation() < 180)
            {
                spr.rotate(10);
            }
            else if(spr.getRotation() > 180)
            {
                spr.rotate(-10);
            }
        }
        else if(dir_y==1)//abajo
        {
            if(spr.getRotation()==350)
            {
                pasado->setGrados(spr.getRotation()-360);
            }


            if(spr.getRotation() < 180 && spr.getRotation()>=10)
            {
                spr.rotate(-10);
                cout<<spr.getRotation()<<endl;
            }
            else if(spr.getRotation() >= 180)
            {
                spr.rotate(10);
                cout<<spr.getRotation()<<endl;
            }
        }
    }
    futuro = new Estado(spr.getPosition().x, spr.getPosition().y, spr.getRotation());
    
    dejarDePulsarTeclas();
}

void Enemigo::render(sf::RenderWindow* window, sf::Clock* reloj, float maxTime)
{
    float t = reloj->getElapsedTime().asSeconds() / maxTime;
    interpolar(t);
    if(tipo != 'r') window->draw(*cono);
    window->draw(spr);
}

void Enemigo::interpolar(float time)
{
    float x,y,g;
        
    x = (((time-0)*(futuro->getEstado().x - pasado->getEstado().x))/(1-0))+pasado->getEstado().x;
    y = (((time-0)*(futuro->getEstado().y - pasado->getEstado().y))/(1-0))+pasado->getEstado().y;
    g = (((time-0)*(futuro->getGrados() - pasado->getGrados()))/(1-0))+pasado->getGrados();
    
    spr.setPosition(x, y);
    spr.setRotation(g);
    if(tipo != 'r')
    {
        cono->setPosition(spr.getPosition().x, spr.getPosition().y);
        cono->setRotation(spr.getRotation());
    }
    
}

void Enemigo::dejarDePulsarTeclas()
{
    eje_x=0;
    eje_y=0;
}

Sprite Enemigo::getCono()
{
    return *cono;
}

void Enemigo::mirar(float x, float y)
{
    float catC, catO, hipo, rot;
    catC = spr.getPosition().x-x;
    catO = spr.getPosition().y-y;
    hipo = sqrt((catC*catC)+(catO*catO));
    rot = 0;
    
    cout<<"hipo = "<<hipo<<endl;
    cout<<"catC = "<<abs(catC)<<endl;
    
    if(spr.getPosition().x >= x)
    {
        if(spr.getPosition().y >= y){
            rot =   (3.14159265359/2+acos(catC/hipo))*180/3.14159265359;
            cout<<"rot = "<<abs(rot)<<endl;
            spr.setRotation(rot);
        }
        else
        {
            rot =   (3.14159265359/2-acos(catC/hipo))*180/3.14159265359;
            cout<<"rot = "<<abs(rot)<<endl;
            spr.setRotation(rot);
        }
    }
    else
    {
        if(spr.getPosition().y >= y){
            rot =   -1*(3*3.14159265359/2-acos(catC/hipo))*180/3.14159265359;
            cout<<"rot = "<<abs(rot)<<endl;
            spr.setRotation(rot);
        }
        else
        {
            rot =   -1*(3*3.14159265359/2+acos(catC/hipo))*180/3.14159265359;
            cout<<"rot = "<<abs(rot)<<endl;
            spr.setRotation(rot);
        }
    }
}

void Enemigo::perseguir(float x, float y)
{
    if(spr.getPosition().x < x-40)
    {
        spr.move(vel,0);

    }
    if(spr.getPosition().x > x+40)
    {
        spr.move(-vel,0);
    }
    
    if(spr.getPosition().y < y-40)
    {
        spr.move(0, vel);

    }
    if(spr.getPosition().y > y+40)
    {
        spr.move(0, -vel);
    }
}


  
