#include "automate.h"
#include "lexer.h"
#include <iostream>

int main(void) {

  string chaine("(1+34)*123");
  Automate *a = new Automate(chaine);
  a->run();
//  Symbole *s;
//  cout << *s << endl;
//  while (*(s = l.Consulter()) != FIN) {
//    s->Affiche();
//    cout << *s << endl;
//    cout << endl;
//    l.Avancer();
//  }
  return 0;
}
