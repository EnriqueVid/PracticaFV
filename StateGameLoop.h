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
#include "World.h"
#include <iostream>

class StateGameLoop : public State {
public:
    //StateGameLoop();
    //StateGameLoop(const StateGameLoop& orig);
    
    virtual State* GetNextState(int i);
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual int update(RenderWindow* window);
    virtual void render(RenderWindow* window);
    
    static StateGameLoop* Instance();
    protected:
        virtual ~StateGameLoop();
        StateGameLoop();
        StateGameLoop(const StateGameLoop & );
        StateGameLoop &operator= (const StateGameLoop & ){};
        
        //constructores
    private:

    static StateGameLoop* _pinstance;
    Texture* _t1;
    Sprite* _s1;
    int _aux;
    World* _world;
    RenderWindow* _window;
    
};

#endif /* STATEGAMELOOP_H */
