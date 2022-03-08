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

Automate::~Automate() {
  delete(_lexer);
  while (!_statesStack.empty())
  {
    delete (_statesStack.top());
    _statesStack.pop();
  }

  while (!_symboleStack.empty())
  {
    delete (_symboleStack.top());
    _symboleStack.pop();
  }
}

/**
 *
 * @return
 */
bool Automate::run() {

  bool nextState = true;
  while (nextState) {
    Symbole *curSymbol = _lexer->Consulter();
    _lexer->Avancer();
    nextState = _statesStack.top()->transitionToState(this, curSymbol);
  }

  if (*_symboleStack.top() != ERREUR) {
    int resultat = _symboleStack.top()->getValeur();
    cout << "L'expression rentrée est correcte" << endl << "Résultat : " << resultat << endl;
    return true;
  } else {
    cout << "L'expression rentrée est invalide" << endl;
    return false;
  }
}

void Automate::decalage(State *state, Symbole *symbole) {

  _statesStack.push(state);
  _symboleStack.push(symbole);

  if (symbole->isTerminal()) {
    _lexer->Avancer();
  }
}
void Automate::reduction(int i, Symbole *symbole) {

  stack<Symbole *> tempSymbolStack;
  for (int j = 0; j < i; j++) {
    delete (_statesStack.top());
    _statesStack.pop();
    tempSymbolStack.push(_symboleStack.top());
    _symboleStack.pop();
  }

  int valeur;

  if (i == 1) {
    valeur = tempSymbolStack.top()->getValeur();
  } else if (i == 3) {
    if (*tempSymbolStack.top() == OPENPAR) {
      delete(tempSymbolStack.top());
      tempSymbolStack.pop();
      valeur = tempSymbolStack.top()->getValeur();
    } else {
      int e1 = tempSymbolStack.top()->getValeur();
      delete(tempSymbolStack.top());
      tempSymbolStack.pop();
      if (*tempSymbolStack.top() == MULT) {
        delete(tempSymbolStack.top());
        tempSymbolStack.pop();
        int e2 = tempSymbolStack.top()->getValeur();
        valeur = e1 * e2;
      } else {
        delete(tempSymbolStack.top());
        tempSymbolStack.pop();
        int e2 = tempSymbolStack.top()->getValeur();
        valeur = e1 + e2;
      }
    }
  }
  delete(tempSymbolStack.top());
  tempSymbolStack.pop();
  _statesStack.top()->transitionToState(this, new Expr(valeur));
  _lexer->addSymbol(symbole);
}