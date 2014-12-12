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
void code(ArbreBin A);

