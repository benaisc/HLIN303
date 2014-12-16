#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct noeud {
  int val;
  char symbole;
  char* code;
  struct noeud *parent;
  struct noeud *fd;
  struct noeud *fg;
  } NoeudSC;
typedef NoeudSC *ArbreBin;

ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D);
//Sortie : un ArbreBin dont la racine vaut e, le sag G et le sad D
void code(ArbreBin A);
//Entrée un ArbreBin, Sortie l'ArbreBin[i<nbfeuille].code