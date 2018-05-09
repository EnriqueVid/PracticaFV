/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateStart.h
 * Author: carlos
 *
 * Created on 18 de abril de 2018, 13:40
 */

#ifndef STATESTART_H
#define STATESTART_H

#include "State.h"
#include "Texture.h"
#include "Sprite.h"
#include <iostream>
#include "StateGameOver.h"
#include "StateGameLoop.h"
#include <SFML/Graphics.hpp>

class StateStart : public State {
public:
    
    virtual State* GetNextState(int i);
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual int update(RenderWindow* window);
    
    static StateStart* Instance();
    
    protected:
        virtual ~StateStart();
        StateStart();
        StateStart(const StateStart & );
        StateStart &operator= (const StateStart & ){};
        
    private:
        
    static StateStart* _pinstance;        
    Texture* _tstartbg;
    Texture* _tstartbutton;
    Texture* _tpj1;
    Texture* _tpj2;
    Texture* _tpj3;
    Texture* _tpj4;
    Sprite* _sstartbg;
    Sprite* _sstartbutton;
    Sprite* _spj1;
    Sprite* _spj2;
    Sprite* _spj3;
    Sprite* _spj4;
    View* _sview;
};
#endif /* STATESTART_H */
