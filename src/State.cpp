//
// Created by Mathieu Saugier on 14/02/2022.
//

#include "State.h"
#include "Automate.h"

bool State0::transitionToState(Automate *a, Symbole* symbole) {
    switch(*symbole){
        case OPENPAR :
            a->decalage(new State2(),symbole);
            break;
        case INT:
            a->decalage(new State3(),symbole);
            break;
        case EXPR:
            a->decalage(new State1(),symbole);
        default:
            break;
    }
    return false;
}

bool State1::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State2::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State3::transitionToState(Automate *a, Symbole *symbole) {
    a->reduction(1);
}

bool State4::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State5::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State6::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State7::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State8::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State9::transitionToState(Automate *a, Symbole *symbole) {
    return State::transitionToState(a, symbole);
}

bool State::transitionToState(Automate *a, Symbole *symbole) {
    return false;
}
