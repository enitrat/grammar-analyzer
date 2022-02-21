#pragma once

#include <string>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS",   "MULT",
                             "INT",     "FIN",      "ERREUR", "EXPR"};

class Symbole {
public:
  Symbole(int i) : ident(i) {}
  virtual ~Symbole() {}
  bool isTerminal() { return ident != EXPR; }
  operator int() const { return ident; }
  virtual int getValeur(){return -1;}
  virtual void Affiche();

protected:
  int ident;
};

class OpenPar : public Symbole {
public:
  OpenPar() : Symbole(OPENPAR){};
  ~OpenPar(){};
  virtual void Affiche();
};

class ClosePar : public Symbole {
public:
  ClosePar() : Symbole(CLOSEPAR) {}
  ~ClosePar(){};
  virtual void Affiche();
};

class Plus : public Symbole {

public:
  Plus() : Symbole(PLUS){}
  ~Plus(){};
  virtual void Affiche();
};

class Mult : public Symbole {
public:
  Mult() : Symbole(MULT) {}

  ~Mult() {}
  virtual void Affiche();
};

class Entier : public Symbole {
public:
  Entier(int v) : Symbole(INT), valeur(v) {}
  ~Entier() {}
  int getValeur() { return valeur; }
  virtual void Affiche();

protected:
  int valeur;
};

class Fin : public Symbole {
public:
  Fin() : Symbole(FIN){};
  ~Fin(){};
  virtual void Affiche();
};

class Erreur : public Symbole {
public:
  Erreur() : Symbole(ERREUR){};
  ~Erreur(){};
  virtual void Affiche();
};

class Expr : public Symbole {
public:
  Expr(int v) : Symbole(EXPR), valeur(v) {}
  ~Expr() {}
  int getValeur() { return valeur; }
  virtual void Affiche();
protected:
  int valeur;
};
