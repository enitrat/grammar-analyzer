//
// Created by Mathieu Saugier on 14/02/2022.
//
#pragma once
#include <iostream>
#include "lexer.h"
#include "automate.h"
using namespace std;
class Automate;
class State
{
public:
    State();
    virtual bool transitionToState(Automate* a, Symbole* symbole);
    int getValeur(){return valeur;}
    void setValeur(int newValeur){valeur = newValeur;}
    ~State();
protected:
    int valeur;
};

class State0: public State{
public:
    State0();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State1: public State{
public:
    State1();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State2: public State{
public:
    State2();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State3: public State{
public:
    State3();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State4: public State{
public:
    State4();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State5: public State{
public:
    State5();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State6: public State{
public:
    State6();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State7: public State{
public:
    State7();
    bool transitionToState(Automate* a, Symbole* symbole);
};


class State8: public State{
public:
    State8();
    bool transitionToState(Automate* a, Symbole* symbole);
};

class State9: public State{
public:
    State9();
    bool transitionToState(Automate* a, Symbole* symbole);
};
