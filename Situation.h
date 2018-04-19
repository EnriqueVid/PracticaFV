/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Situation.h
 * Author: carlos
 *
 * Created on 19 de abril de 2018, 10:46
 */

#ifndef SITUATION_H
#define SITUATION_H

#include <SFML/System/Vector2.hpp>


class Situation {
public:
    Situation();
    Situation(float, float, float);
    Situation(const Situation& orig);
    
    sf::Vector2f getPosition();
    float getPositionX();
    float getPositionY();
    
    float getAngle();
    
    void setPosition(float, float);
    
    void setAngle(float);

    virtual ~Situation();
    
private:
    float _pos_x;
    float _pos_y;
    float _angle;
};

#endif /* SITUATION_H */

