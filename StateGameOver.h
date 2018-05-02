/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateGameOver.h
 * Author: carlos
 *
 * Created on 17 de abril de 2018, 21:06
 */

#ifndef STATEGAMEOVER_H
#define STATEGAMEOVER_H

#include "State.h"
#include "Sprite.h"
#include <iostream>
#include "StateStart.h"
#include "StateGameLoop.h"

class StateGameOver : public State {
public:

    virtual State* GetNextState(int i);
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual int update(RenderWindow* window);
    
    static StateGameOver* Instance();
    
    protected:
        virtual ~StateGameOver();
        StateGameOver();
        StateGameOver(const StateGameOver & );
        StateGameOver &operator= (const StateGameOver & ){};
        
    private:
    static StateGameOver* _pinstance;
    Texture* _tgameover;
    Sprite* _sgameover;
};
#endif /* STATEGAMEOVER_H */

