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

class StateGameOver : public State {
public:
    //StateGameLoop();
    //StateGameLoop(const StateGameLoop& orig);
    //virtual ~StateGameLoop();
    virtual State* GetNextState();
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual void setState(State* nextState); 
    
    static StateGameOver* Instance();
    
    protected:
        StateGameOver();
        StateGameOver(const StateGameOver & );
        StateGameOver &operator= (const StateGameOver & ){};
        
    private:
    static StateGameOver* _pinstance;
    
    
};
#endif /* STATEGAMEOVER_H */

