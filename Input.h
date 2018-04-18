/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.h
 * Author: newman
 *
 * Created on 18 de abril de 2018, 13:36
 */

#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Input {

public:
    static Input* Instance();
    bool inputCheck(int i);
    void inputInput();
    
protected:
    Input();
    Input(const Input& orig);
    Input &operator= (const Input & ){};
    virtual ~Input();
    
    
private:
    static Input* _pinstance;
    bool _keyboard[100];

};

#endif /* INPUT_H */

