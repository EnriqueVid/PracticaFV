/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Message.cpp
 * Author: emiliosello
 * 
 * Created on 22 de abril de 2018, 17:55
 */


#include "Message.h"
#include "RenderWindow.h"
#include "Player.h"


using namespace std;

Message::Message(int number,sf::Font* font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition)
    {
        sf::IntRect box1;
        box1.top = (int) (0);
        box1.left = (int) (0);
        box1.height = (int)(texturebg->getTextureSize().y);
        cout<<"Altura: "<<box1.height<<endl;
        box1.width = (int) (texturebg->getTextureSize().x);
        
        sf::String message1 = "";

        _sbox = new Sprite(texturebg, box1, sf::Vector2f(texturebg->getTextureSize().x/2.f, texturebg->getTextureSize().y/2.f), pjposition);

        _sbox->setSpriteScale(sf::Vector2f(0.5, 0.3));

        
        
        
        switch(number)
        {
            case 0:
                message1 = "Hola, bienvenide a Color of Fate.";

                break;
                
            case 1:
                message1 = "Hola, bienvenide a Color of Fate \n En este juego se va a poner a prueba tus habilidades \n asi que esperamos grandes cosas de ti.";
                
                break;
                
            case 2:
                message1 = "Cada piso tiene varios niveles y para salvar a tu mundo debes ascender a lo más alto para erradicar el mal. ¡Nos vemos en la cima!";
                
                break;
                
            case 3:
                message1 = "Bienvenido al nivel 0. Para llegar a los objetivos necesitarás utilizar las teclas W, A, S, D.";
                
                break;
                
            case 4:
                message1 = "Allí está la escalera para subir al siguiente nivel, tu objetivo es alcanzarla.";
                
                
                break;
                
            case 5:
                message1 = "Este es el color Rojo, este color te otorga la habilidad\nde mover y destruir cajas. \nTal vez te pueda ser util para seguir avanzando.";
                
                
                break;
                
            case 6:
                message1 = "Recuerda que el color rojo te puede ayudar a mover cajas sobre interruptores.";
                
                
                break;
                
                
            case 7:
                message1 = "¡Atencion! Tienes a un guardia de clase C enfrente tuyo, si te ve te absorberá pigmento. Evita que tu pigmento llegue a cero.";
                break;
                
                
            case 8:
                message1 = "Eso que ves de rojo es una zona de Tinta Roja. Si posees\nel poder rojo te podras ocultar de la vision de los\nguardias en las zonas de tu color, tambien recuperas mana.";
                
                
                break;            
                
            case 9:
                message1 = "¡Enhorabuena adalid! Nos vemos en el siguiente nivel.";
                
                
                break;
                
            case 10:
                message1 = "¡Enhorabuena! Acabas de conseguir el color Azul, este color te otorga la habilidad de moverte a grandes velocidades durante un corta fraccion de tiempo. Tal vez te pueda ser util para seguir avanzando.";
                 
                
                break;
                
            case 11:
                message1 = "Como puedes ver, al entrar en zonas de tinta azul, recargas pigmento azul, lo cual te permite volver a utilizar tu habilidad.";
                
                
                break;
                
            case 12:
                message1 = "Atencion, solo te camuflas en las zonas del tinte de tu color.";
                break;
                
            case 13:
                message1 = "Nivel 1";
                break;
            case 14:
                message1 = "Nivel 2";
                break;
            case 15:
                message1 = "Nivel 3";
                break;
            case 16:
                message1 = "Nivel 4";
                break;
            case 17:
                message1 = "Nivel 5";
                break;
            case 18:
                message1 = "Nivel 6";
                break;
            case 19:
                message1 = "Nivel Final";
                break;
                
            
                
            default:
                break;
        }
        
    _text = new sf::Text(message1, *font, 6);
    _text->setColor(sf::Color::White);
    _text->setPosition(sf::Vector2f(_sbox->getGlobalBounds().left,_sbox->getGlobalBounds().top));
     
}


void Message::update()
{
    Player* player = Player::Instance();

    sf::FloatRect box = player->getPlayer()->getGlobalBounds();
    sf::IntRect box1;
    box1.top = (int) (box.top + box.height);
    box1.left = (int) (box.left - box.width);
    
    _sbox->setSpritePosition(sf::Vector2f(RenderWindow::Instance()->getViewCenter().x, RenderWindow::Instance()->getViewCenter().y + 100));
    _text->setPosition(sf::Vector2f(_sbox->getSpritePosition().x - _sbox->getGlobalBounds().width * 0.43, _sbox->getSpritePosition().y - 20));    
    
    player=NULL;
}


sf::Text* Message::getTextMessage()
{
    return _text;
}

Sprite* Message::getSpriteMessage()
{
    return _sbox;
}

std::string Message::getStringMessage()
{
    return _text->getString();
}

Message::~Message()
{   
    if(_sbox!=NULL){
    delete _sbox;
    }
    _sbox = NULL;
    if(_text!=NULL){
        delete _text;
    }
    _text=NULL;
}