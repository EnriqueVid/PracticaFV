/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Help.h
 * Author: carlos
 *
 * Created on 20 de mayo de 2018, 2:45
 */

#ifndef HELP_H
#define HELP_H
#include "Message.h"
#include "Object.h"
#include <iostream>

class Help : public Object {
public:
    Help(int objectType, float initialPosX, float initialPosY, float initialAngle, bool canBeMoved, Texture *texture, 
            int number,sf::Font* font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition);
    Help(const Help& orig);
    
    Message* getMessage();
    
    void update();
    
    void setShowMessage(bool b);
    bool getShowMessage();
    
    
    virtual ~Help();
private:
    int _messageNumber;
    Message* _message;
    bool _show;
    bool _showLastUpdate;
};

#endif /* HELP_H */

