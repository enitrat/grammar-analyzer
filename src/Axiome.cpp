//
// Created by Mathieu Saugier on 14/02/2022.
//

#include "State.h"
#include "Automate.h"

class Axiome: public State
{
public:
    void transitionToState(Automate a){
        Symbole* symbole = a.readSymbol();

    }
};