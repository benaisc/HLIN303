#include <stdlib.h>
#include <stdio.h>

void plus_une_case(char* a);
//Tableau de char en entr�e, tableau de char + 1 case en sortie
int deuxp(int a);
//2 puissance a
char* convert_d_b(char a);
//Entr�e un caract�re ASCII, Sortie son code binaire
int convert_b_d(char* p);
//Entr�e un octet de char, Sortie la valeur de l'octet binaire en Entier
int taille_c(char* p);
//Entr�e un tableau de char, Sortie longueur tab
void init(char *tab);
//Initialisation de l'octet de compression � '2'
int reste(char *tab);
//Entr�e octet, Sortie nombre de '2'