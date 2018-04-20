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

class StateStart : public State {
public:
    //StateGameLoop();
    //StateGameLoop(const StateGameLoop& orig);
    //virtual ~StateGameLoop();
    virtual State* GetNextState();
    virtual void test();
    virtual State* getState();
    virtual int getStateNumber();
    virtual void setState(State* nextState); 
    
    static StateStart* Instance();
    
    protected:
        StateStart();
        StateStart(const StateStart & );
        StateStart &operator= (const StateStart & ){};
        
    private:
    static StateStart* _pinstance;    
};
#endif /* STATESTART_H */
