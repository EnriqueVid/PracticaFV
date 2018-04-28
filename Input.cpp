/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.cpp
 * Author: newman
 * 
 * Created on 18 de abril de 2018, 13:36
 */



#include "Input.h"
Input* Input::_pinstance = 0;
Input* Input::Instance()
{
    if(_pinstance == 0)
    {
        _pinstance = new Input;
    }
    return _pinstance;
}

Input::Input() 
{
    for(int i=0; i<100; i++)
    {
        _keyboard[i] = false;
    }
}

Input::Input(const Input& orig) 
{
    
}

Input::~Input() 
{
    
}

bool Input::inputCheck(int i)
{
    return _keyboard[i];
}

void Input::inputInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) _keyboard[0] = true;
    else  _keyboard[0] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) _keyboard[1] = true;
    else  _keyboard[1] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) _keyboard[2] = true;
    else  _keyboard[2] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) _keyboard[3] = true;
    else  _keyboard[3] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _keyboard[4] = true;
    else  _keyboard[4] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _keyboard[5] = true;
    else  _keyboard[5] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _keyboard[6] = true;
    else  _keyboard[6] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _keyboard[7] = true;
    else  _keyboard[7] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) _keyboard[8] = true;
    else  _keyboard[8] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) _keyboard[9] = true;
    else  _keyboard[9] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) _keyboard[10] = true;
    else  _keyboard[10] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) _keyboard[11] = true;
    else  _keyboard[11] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        _keyboard[12] = true;
    }
    else  _keyboard[12] = false;
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _keyboard[13] = true;
    }
    else  _keyboard[13] = false;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Insert))
    {
        _keyboard[14] = true;
    }
    else  _keyboard[14] = false;
    
}

