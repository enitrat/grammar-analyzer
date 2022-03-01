//
// Created by Mathieu Saugier on 14/02/2022.
//

#include "state.h"
#include "automate.h"
#include "symbole.h"

State::State() {}
State::~State() {}
State0::State0() : State() {}
State1::State1() : State() {}
State2::State2() : State() {}
State3::State3() : State() {}
State4::State4() : State() {}
State5::State5() : State() {}
State6::State6() : State() {}
State7::State7() : State() {}
State8::State8() : State() {}
State9::State9() : State() {}

bool State0::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State0" << endl;
  switch (*symbole) {
  case OPENPAR:
    a->decalage(new State2(), symbole);
    break;
  case INT:
    a->decalage(new State3(), symbole);
    break;
  case EXPR:
    a->decalage(new State1(), symbole);
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State1::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State1" << endl;
  switch (*symbole) {
  case PLUS:
    a->decalage(new State4(), symbole);
    break;
  case MULT:
    a->decalage(new State5(), symbole);
    break;
  case FIN:
    delete (symbole);
    return false;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State2::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State2" << endl;
  switch (*symbole) {
  case OPENPAR:
    a->decalage(new State2(), symbole);
    break;
  case INT:
    a->decalage(new State3(), symbole);
    break;
  case EXPR:
    a->decalage(new State6(), symbole);
    break;
  default:
    cout << "default" << endl;
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State3::transitionToState(Automate *a, Symbole *symbole) {
  cout << "state3" << endl;
  switch (*symbole) {
  case PLUS:
    a->reduction(1, new Plus());
    break;
  case MULT:
    a->reduction(1, new Mult());
    break;
  case CLOSEPAR:
    a->reduction(1, new ClosePar());
    break;
  case FIN:
    a->reduction(1, new Fin());
    break;
  }
  return true;
}

bool State4::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State4" << endl;
  symbole->Affiche();
  switch (*symbole) {
  case OPENPAR:
    a->decalage(new State2(), symbole);
    break;
  case INT:
    a->decalage(new State3(), symbole);
    break;
  case EXPR:
    a->decalage(new State7(), symbole);
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State5::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State5" << endl;

  switch (*symbole) {
  case OPENPAR:
    a->decalage(new State2(), symbole);
    break;
  case INT:
    a->decalage(new State3(), symbole);
    break;
  case EXPR:
    a->decalage(new State8(), symbole);
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State6::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State6" << endl;
  symbole->Affiche();
  switch (*symbole) {
  case PLUS:
    a->decalage(new State4(), symbole);
    break;
  case MULT:
    a->decalage(new State5(), symbole);
    break;
  case CLOSEPAR:
    a->decalage(new State9(), symbole);
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State7::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State7" << endl;
  switch (*symbole) {
  case MULT:
    a->decalage(new State5(), new Mult());
    break;
  case PLUS:
    a->reduction(3, new Plus());
    break;
  case FIN:
    a->reduction(3, new Fin());
    break;
  case CLOSEPAR:
    a->reduction(3, new ClosePar());
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State8::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State8" << endl;

  switch (*symbole) {
  case MULT:
    a->reduction(3, new Mult());
    break;
  case PLUS:
    a->reduction(3, new Plus());
    break;
  case CLOSEPAR:
    a->reduction(3, new ClosePar());
    break;
  case FIN:
    a->reduction(3, new Fin());
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }
  return true;
}

bool State9::transitionToState(Automate *a, Symbole *symbole) {
  cout << "State9" << endl;

  switch (*symbole) {
  case PLUS:
    a->reduction(3, new Plus);
    break;
  case MULT:
    a->reduction(3, new Mult);
    break;
  case CLOSEPAR:
    a->reduction(3, new ClosePar);
    break;
  case FIN:
    a->reduction(3, new Fin);
    break;
  default:
    delete (symbole);
    a->decalage(nullptr, new Symbole(ERREUR));
    return false;
  }

  return true;
}

bool State::transitionToState(Automate *a, Symbole *symbole) { return false; }
