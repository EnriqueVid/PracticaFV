/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   StateGameLoop.h
 * Author: carlos
 *
 * Created on 17 de abril de 2018, 20:22
 */

#ifndef STATEGAMELOOP_H
#define STATEGAMELOOP_H
#include "State.h"
#include "StateGameOver.h"
#include "Texture.h"
#include "StateStart.h"
#include "Player.h"
#include <iostream>

class StateGameLoop : public State {
public:
    //StateGameLoop();
    //StateGameLoop(const StateGameLoop& orig);
    //virtual ~StateGameLoop();
    virtual State* GetNextState(int i);
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual void update(RenderWindow* window);
    
    static StateGameLoop* Instance();
    protected:
        StateGameLoop();
        StateGameLoop(const StateGameLoop & );
        StateGameLoop &operator= (const StateGameLoop & ){};
        
        //constructores
    private:

    static StateGameLoop* _pinstance;
    
};

#endif /* STATEGAMELOOP_H */
