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
#include "Player.h"

using namespace std;

Message::Message(int number,std::string file, Texture* texturebg)
    {
        
        _text = new Text();
        
        std::string message1 = "";
        switch(number)
        {
            case 0:
                message1 = "¡Hola, bienvenide a Color of Fate! En este juego se va a poner a prueba tus habilidades así que esperamos grandes cosas de ti.";
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
        
        _font = new Font(file);
        _sbox = new Sprite();        
        _sbox->setSpriteTexture(texturebg);
        _sbox->setSpriteOrigin(sf::Vector2f(texturebg->getTextureSize().x/2.f, texturebg->getTextureSize().y/2.f));
        _sbox->setSpritePosition(sf::Vector2f(Player::Instance()->getPlayer()->getSpritePosition().x, Player::Instance()->getPlayer()->getSpritePosition().y - texturebg->getTextureSize().y));
        
        _text->setFont(_font);
        _text->setCharacterSize(12);
        _text->setColor(sf::Color::White);
        _text->setOrigin(_text->getGlobalBounds().width/2.f, _text->getGlobalBounds().height/2.f);
        _text->setPosition(_sbox->getSpritePosition().x, _sbox->getSpritePosition().y);

}

Message::~Message()
{
    delete _text;
    _text = NULL;
    delete _font;
    _font = NULL;   
    delete _sbox;
    _sbox = NULL;
}