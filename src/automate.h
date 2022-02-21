//
// Created by Mathieu Saugier on 14/02/2022.
//

#pragma once
#include <stack>
#include "lexer.h"
#include "state.h"
#include "symbole.h"

using namespace std;
class State;
class Automate {

private:
    Lexer *_lexer;
    stack<State*> _statesStack;
    stack<Symbole*> _symboleStack;
public:
    Automate(string s);
    virtual ~Automate();
    bool run();
    void decalage(State* state,Symbole* symbole);
    void reduction(int i, Symbole* symbole);
    Symbole* readSymbol();
};

