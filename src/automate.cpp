//
// Created by Mathieu Saugier on 14/02/2022.
//
#include "automate.h"
#include "symbole.h"

/**
 * Initialise un automate à l'état 0 pour une phrase s
 * @param s
 */
Automate::Automate(string s) {
  State0 *state0 = new State0();
  this->_lexer = new Lexer(s);
  _statesStack.push(state0);
}

Automate::~Automate() {}

/**
 *
 * @return
 */
bool Automate::run() {
  bool nextState = true;
  while (nextState) {
    Symbole* curSymbol = _lexer->Consulter();
    // cout<<endl;
    _lexer->Avancer();
    curSymbol->Affiche();
    nextState = _statesStack.top()->transitionToState(this, curSymbol);
  }

  if (*_symboleStack.top() == FIN) {
    return true;
  } else {
    return false;
  }
}

void Automate::decalage(State *state, Symbole *symbole) {
  cout<<"decalage"<<endl;
  _statesStack.push(state);
  _symboleStack.push(symbole);
}
void Automate::reduction(int i, Symbole *symbole) {

  cout<<"reduction"<<endl;
  symbole->Affiche();
  stack<Symbole *> tempSymbolStack;
  for (int j = 0; j < i; j++) {
    delete (_statesStack.top());
    // cout<<"reduc"<<endl;
    _statesStack.pop();
    tempSymbolStack.push(_symboleStack.top());
    _symboleStack.pop();
  }

  int valeur;

  if (i == 1) {
    valeur = tempSymbolStack.top()->getValeur();
  } else if (i == 3) {

    tempSymbolStack.pop();
    tempSymbolStack.top()->Affiche();

    if (*tempSymbolStack.top() == OPENPAR) {
      tempSymbolStack.pop();
      valeur = tempSymbolStack.top()->getValeur();
    } else {
      int e1 = tempSymbolStack.top()->getValeur();
      tempSymbolStack.pop();
      if (*tempSymbolStack.top() == MULT) {
        tempSymbolStack.pop();
        int e2 = tempSymbolStack.top()->getValeur();
        valeur = e1 * e2;
      } else {
        cout<<"hehe"<<endl;
        cout<<e1<<endl;
        tempSymbolStack.pop();
        int e2 = tempSymbolStack.top()->getValeur();
        valeur = e1 + e2;
      }
    }
  }
  //cout<<_statesStack.size()<<endl;
  _statesStack.top()->transitionToState(this, new Expr(valeur));
  _lexer->addSymbol(symbole);
}