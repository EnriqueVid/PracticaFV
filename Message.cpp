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


using namespace std;

Message::Message(int number,sf::Font font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition)
    {
        sf::FloatRect box = pjbounds;
        sf::IntRect box1;
        box1.top = (int) (box.top + box.height);
        box1.left = (int) (box.left - box.width);
        box1.height = (int)(texturebg->getTextureSize().y);
        box1.width = (int) (texturebg->getTextureSize().x);
        
        
        _text = new sf::Text();
        _text->setFont(font);

        _sbox = new Sprite(texturebg, box1, sf::Vector2f(texturebg->getTextureSize().x/2.f, texturebg->getTextureSize().y/2.f), pjposition);
        _sbox->setSpriteScale(sf::Vector2f(1.f, 1.f));

        _text->setColor(sf::Color::White);
        _text->setCharacterSize(20);
        _text->setPosition(_sbox->getSpritePosition().x + 20, _sbox->getSpritePosition().y);
        
        std::string message1 = "";
        switch(number)
        {
            case 0:
                message1 = "Hola, bienvenide a Color of Fate.";
                _text->setString(message1);

                break;
                
            case 1:
                message1 = "Hola, bienvenide a Color of Fate En este juego se va a poner a prueba tus habilidades asi que esperamos grandes cosas de ti.";
                _text->setString(message1);
                break;
                
            case 2:
                message1 = "Cada piso tiene varios niveles y para salvar a tu mundo debes ascender a lo más alto para erradicar el mal. ¡Nos vemos en la cima!";
                _text->setString(message1); 
                //_text->getText().setString(message1);
                break;
                
            case 3:
                message1 = "Bienvenido al nivel 0, para llegar a los objetivos necesitarás utilizar las teclas W, A, S, D.";
                _text->setString(message1); 
                break;
                
            case 4:
                message1 = "Allí está la escalera para subir al siguiente nivel, tu objetivo es alcanzarla.";
                _text->setString(message1); 
                
                break;
                
            case 5:
                message1 = "Acabas de descubrir el color Rojo, este color te otorga la habilidad de mover y destruir cajas. Tal vez te pueda ser útil para seguir avanzando.";
                _text->setString(message1); 
                
                break;
                
            case 6:
                message1 = "Recuerda que el color rojo te puede ayudar a mover cajas sobre interruptores.";
                _text->setString(message1); 
                
                break;
                
                
            case 7:
                message1 = "¡Atención! Tienes a un guardia de clase C enfrente tuyo, si te ve te absorberá pigmento. Evita que tu pigmento llegue a cero.";
                _text->setString(message1); 
                
                break;
                
            case 8:
                message1 = "Eso que ves de rojo es una zona de Tinta Roja. Si posees el poder del rojo te podrás ocultar de la visión de los guardias en las zonas de tu color, además de que recuperas maná.";
                _text->setString(message1); 
                
                break;            
                
            case 9:
                message1 = "¡Enhorabuena adalid! Nos vemos en el siguiente nivel.";
                _text->setString(message1); 
                
                break;
                
            case 10:
                message1 = "¡Enhorabuena! Acabas de conseguir el color Azul, este color te otorga la habilidad de moverte a grandes velocidades durante un corta fracción de tiempo. Tal vez te pueda ser útil para seguir avanzando.";
                _text->setString(message1); 
                
                break;
                
            case 11:
                message1 = "Como puedes ver, al entrar en zonas de tinta azul, recargas pigmento azul, lo cual te permite volver a utilizar tu habilidad.";
                _text->setString(message1); 
                
                break;
                
            case 12:
                message1 = "Atención, solo te camuflas en las zonas del tinte de tu color.";
                _text->setString(message1); 
                
                break;
                
            default:
                break;                
        }
        
    _text->setCharacterSize(12);     
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
    delete _sbox;
    _sbox = NULL;
}