/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.cpp
 * Author: tuba
 * 
 * Created on 24 de marzo de 2018, 19:30
 */

#include "Jugador.h"

Jugador::Jugador(sf::Sprite* s, int vm, int sm) {
    personaje = new sf::Sprite();
    personaje->setTexture(*s->getTexture());
    personaje->setTextureRect(s->getTextureRect());
    personaje->setOrigin(s->getOrigin());
    personaje->setPosition(s->getPosition());
    personaje->setScale(s->getScale());
    personaje->setRotation(s->getRotation());
    vida_max = vm;
    vida = vm;
    estamina_max = sm;
    estamina = sm;
    color = -1;
    personaje->setColor(sf::Color::White);
    pasado = new Estado(personaje->getPosition().x, personaje->getPosition().y, personaje->getRotation());
    futuro = new Estado(personaje->getPosition().x, personaje->getPosition().y, personaje->getRotation());
    velocidad = 20;
    
    
}

void Jugador::deletear(){
    delete personaje;
    personaje = NULL;
    
    delete pasado;
    pasado = NULL;
    
    delete futuro;
    futuro = NULL;
}

void Jugador::cambiaColor(sf::Color c){
    personaje->setColor(c);
    
    if(c == sf::Color::Blue){
        color = 2;
    }else if(c == sf::Color::Red){
        color = 3;
    }else if(c == sf::Color::Yellow){
        color = 4;
    }else if(c == sf::Color::Green){
        color = 5;
    }else{
        color = -1;
    }
}

int Jugador::getColor(){
    return color;
}

void Jugador::input(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        eje_x= 1;
        eje_y= -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        eje_x= 1;
        eje_y= 1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        eje_x= -1;
        eje_y= -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        eje_x= -1;
        eje_y= 1;
    
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        eje_x= 1;
        eje_y= 0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        eje_x= -1;
        eje_y= 0;
    }  
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        eje_x= 0;
        eje_y= -1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        eje_x= 0;
        eje_y= 1;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        habilidad=true;
    }
}

void Jugador::update(){
        
    personaje->setPosition(futuro->getEstado());
    personaje->setRotation(futuro->getGrados());
        
    pasado = new Estado(futuro->getEstado().x, futuro->getEstado().y, futuro->getGrados());
        
    //cout << "Valor ejeX: "<< ejeX << ". Valor ejeY: " << ejeY << endl;
    //arriba-derecha
        
    if(eje_x==1&&eje_y==-1){
        
        if(personaje->getRotation()<135){
            pasado->setGrados(personaje->getRotation()+360);
        }
        
        personaje->setRotation(315);
        personaje->move(velocidad*sin(45),-velocidad*sin(45));
        
        dir_x=eje_x;
        dir_y=eje_y;
        
    }else
        //abajo derecha
    if(eje_x==1&&eje_y==1){

        
        if(personaje->getRotation()>225){
            pasado->setGrados(personaje->getRotation()-360);
        }

        
        personaje->setRotation(45);
        personaje->move(velocidad*sin(45),velocidad*sin(45));
        
        dir_x=eje_x;
        dir_y=eje_y;
    
    }else
        //arriba izquierda
    if(eje_x==-1&&eje_y==-1){
        
        personaje->setRotation(225);
        personaje->move(-velocidad*sin(45),-velocidad*sin(45));
    
        dir_x=eje_x;
        dir_y=eje_y;
    
    }else
        //abajo izquierda
    if(eje_x==-1&&eje_y==1){
        
        personaje->setRotation(135);
        personaje->setScale(1,1);
        personaje->move(-velocidad*sin(45),velocidad*sin(45));
        
        dir_x=eje_x;
        dir_y=eje_y;
    
    }else
        //derecha
    if(eje_x==1){
        
        //sprite->setRotation(0);
        /*
        if(sprite->getRotation()==330){
            
            estadoAnterior->setGrados(-90);
            sprite->setRotation(sprite->getRotation()+90);    
            
        }
        
        if(sprite->getRotation()>180){
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>0){
            sprite->setRotation(sprite->getRotation()-90);
        }*/
        
        if(personaje->getRotation()>180){
            pasado->setGrados(personaje->getRotation()-360);
        }
        
        personaje->setRotation(0);
        personaje->move(velocidad,0);
        
        dir_x=eje_x;
        dir_y=0;
        
        //izquierda
    }else if(eje_x==-1){
        //sprite->setRotation(180);
        /*if(sprite->getRotation()<180){
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>180){
            sprite->setRotation(sprite->getRotation()-90);
        }
         */
        personaje->setRotation(180);
        personaje->move(-velocidad,0);
        
        
        dir_x=eje_x;
        dir_y=0;
        
    }else 
        //arriba
    if(eje_y==-1){
        //sprite->setRotation(270);
        
        /*
        if(sprite->getRotation()==0){
            estadoAnterior->setGrados(360);
        }
        
        if(sprite->getRotation()<270 && sprite->getRotation()>=90){
            sprite->setRotation(sprite->getRotation()+90);
        }else if(sprite->getRotation()>270 || sprite->getRotation()<90){
            sprite->setRotation(sprite->getRotation()-90);
        }
         */
        
        if(personaje->getRotation()<180){
            pasado->setGrados(personaje->getRotation()+360);
        }
        
        
        personaje->setRotation(270);
        personaje->move(0,-velocidad);  
        
        
        dir_x=0;
        dir_y=eje_y;
        
        //abajo
    }else if(eje_y==1){
        //sprite->setRotation(90);
        /*
        if(sprite->getRotation()<90){
            sprite->setRotation(sprite->getRotation()+30);
        }else if(sprite->getRotation()>90){
            sprite->setRotation(sprite->getRotation()-30);
        }
         */
        personaje->setRotation(90);
        personaje->move(0,velocidad);
        
        dir_x=0;
        dir_y=eje_y;
    }
    
        //supervelocidad();
    
    futuro = new Estado(personaje->getPosition().x, personaje->getPosition().y, personaje->getRotation());
    
    
    
    dejarDePulsarTeclas();
}
    
void Jugador::dejarDePulsarTeclas(){
    eje_x=0;
    eje_y=0;
    habilidad=false;
}

void Jugador::supervelocidad(){
    
    sf::Clock* dur;
    bool delay = false;
    sf::Clock* retraso;
    
    
    if(dur==NULL || dur->getElapsedTime().asSeconds()>=1.0){
        if(habilidad){
            if(estamina>=estamina_max){
                if(retraso==NULL){
                    estamina = 0;
                    velocidad = 4 * velocidad;
                    delay = true;
                    dur = new sf::Clock();
                }
            }else{
                velocidad = 20;
                estamina++;
                if(delay){
                    retraso = new sf::Clock();
                    delay=false;
                }
            }
        }else if(!habilidad){
            velocidad = 20;
            if(estamina<estamina_max){
                estamina++;
            }
            if(delay){
                retraso = new sf::Clock();
                delay = false;
            }
        }
        if(dur!=NULL && dur->getElapsedTime().asSeconds()>=1.0){
            delete dur;
            dur = NULL;
        }
    }
    if(retraso!=NULL && retraso->getElapsedTime().asSeconds()>1.0){
        delete retraso;
        retraso = NULL;
    }
    
    std::cout<<"Estamina: "<<estamina<<std::endl;
}
    
    void Jugador::render(sf::RenderWindow* w, sf::Clock* reloj, float tmax){
        float t = reloj->getElapsedTime().asSeconds() / tmax;
        interpolar(t);
        w->draw(*personaje);
    }
    
    void Jugador::interpolar(float t){
        float x,y,g;
        
        x = (((t-0)*(futuro->getEstado().x - pasado->getEstado().x))/(1-0))+pasado->getEstado().x;
        
        y = (((t-0)*(futuro->getEstado().y - pasado->getEstado().y))/(1-0))+pasado->getEstado().y;
        
        g = (((t-0)*(futuro->getGrados() - pasado->getGrados()))/(1-0))+pasado->getGrados();
        
        //cout << g << endl;
        
        personaje->setPosition(x, y);
        personaje->setRotation(g);
    }
    
    sf::Sprite* Jugador::getPersonaje(){
        return personaje;
    }
    
    void Jugador::bajavida(float f)
    {
        vida-=f;
        std::cout<<"Vida: "<<vida<<std::endl;
    }
    
    