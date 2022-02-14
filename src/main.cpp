#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {

   string chaine("(1+34)*123");

   Automate a(chaine);
   Lexer l(chaine);

   a.run();
   Symbole * s;
   cout<<*s<<endl;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<*s<<endl;
      cout<<endl;
      l.Avancer();
   }
   return 0;
}

