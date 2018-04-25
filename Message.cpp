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


using namespace std;

Message::Message(int number,Font* font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition)
    {
        
        _text = new Text();
        
        sf::FloatRect box = pjbounds; 
        sf::IntRect box1;
        box1.top = (int) (box.top + box.height);
        box1.left = (int) (box.left - box.width);
        box1.height = (int)(texturebg->getTextureSize().y);
        box1.width = (int) (texturebg->getTextureSize().x);
        
        _text->setFont(font);
        _sbox = new Sprite(texturebg, box1, sf::Vector2f(texturebg->getTextureSize().x/2.f, texturebg->getTextureSize().y/2.f), pjposition); 
        _text->setCharacterSize(12);
        _text->setColor(sf::Color::White);
        _text->setPosition(_sbox->getSpritePosition().x + 20, _sbox->getSpritePosition().y);
        
        std::string message1 = "";
        switch(number)
        {
            case 0:
                message1 = "Hola, bienvenide a Color of Fate En este juego se va a poner a prueba tus habilidades asi que esperamos grandes cosas de ti.";
                _text->setString(message1);
                break;
                
            case 1:
                message1 = "Cada piso tiene varios niveles y para salvar a tu mundo debes ascender a lo más alto para erradicar el mal. ¡Nos vemos en la cima!";
                _text->setString(message1); 
                break;
                
            case 2:
                message1 = "Bienvenido al nivel 0, para llegar a los objetivos necesitarás utilizar las teclas W, A, S, D.";
                _text->setString(message1); 
                break;
                
            case 3:
                message1 = "Allí está la escalera para subir al siguiente nivel, tu objetivo es alcanzarla.";
                _text->setString(message1); 
                
                break;
                
            default:
                break;                
        }
        
        


}

Text* Message::getTextMessage()
{
    return _text;
}

Sprite* Message::getSpriteMessage()
{
    return _sbox;
}

Font* Message::getFontMessage()
{
    return _text->getFont();
}



Message::~Message()
{
    delete _text;
    _text = NULL;;   
    delete _sbox;
    _sbox = NULL;
}