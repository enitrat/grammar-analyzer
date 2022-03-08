#include "automate.h"
#include "lexer.h"
#include <iostream>

int main(void) {

  string in;
  while(true) {
    cout << "Entrez l'expression à calculer ou 'exit' pour quitter le programme "
         << endl;
    getline(cin, in);
    if (in == "exit") {
      cout << "Au revoir !" << endl;
      break;
    }

    Automate *a = new Automate(in);
    a->run();
    delete (a);
  }
  return 0;
}
