//
// Created by Mathieu Saugier on 14/02/2022.
//

#include "Automate.h"
#include "State.h"
#include "symbole.h"

Automate::Automate(string s)
{
    State0* state0 = new State0();
    this->_lexer = new Lexer(s);
    _statesStack.push(state0);
}

Automate::~Automate() {
}

bool Automate::run(){
    bool nextState = true;
    Symbole* curSymbol;
    while(nextState){
        curSymbol = _lexer->Consulter();
        _lexer->Avancer();
        nextState = _statesStack.top()->transitionToState(this,curSymbol);
    }

    if(*curSymbol==FIN){
        return true;
    }else{
        return false;
    }

}

void Automate::decalage(State *state, Symbole* symbole) {
    _statesStack.push(state);
    _symboleStack.push(symbole);

}
void Automate::reduction(int i) {

    stack<Symbole *> tempSymbolStack;

    for (int j = 0; j <= i; j++) {
        delete (_statesStack.top());
        _statesStack.pop();
        tempSymbolStack.push(_symboleStack.top());
        _symboleStack.pop();
    }

    int valeur = _statesStack.top()->getValeur();

    if (i == 1) {
        valeur = tempSymbolStack.top()->getValeur();
    } else if (i == 2) {
        int temp = tempSymbolStack.top()->getValeur();
        tempSymbolStack.pop();
        if (*tempSymbolStack.top() == MULT) {
            valeur = valeur * temp;
        } else {
            valeur = valeur + temp;
        }
    } else if (i == 3) {
        tempSymbolStack.pop();
        valeur = tempSymbolStack.top()->getValeur();
        tempSymbolStack.pop();
        tempSymbolStack.pop();
    }
    _statesStack.top()->setValeur(valeur);

}