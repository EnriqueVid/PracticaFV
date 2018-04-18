/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.h
 * Author: carlos
 *
 * Created on 17 de abril de 2018, 20:06
 */

#ifndef STATE_H
#define STATE_H

class State {
public:
    //State();
    virtual State* GetNextState() = 0;
    virtual void test() = 0;
    virtual State* getState() = 0;
    virtual int getStateNumber() = 0;
    virtual void setState(State* nextState) = 0;
    //virtual ~State()
    
};

#endif /* STATE_H */

