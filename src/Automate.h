//
// Created by Mathieu Saugier on 14/02/2022.
//

#ifndef LEXER_AUTOMATE_H
#define LEXER_AUTOMATE_H
#include <stack>
#include "lexer.h"
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
    void reduction(int i);
    Symbole* readSymbol();
};

#endif //LEXER_AUTOMATE_H
