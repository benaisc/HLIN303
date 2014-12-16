#include <stdlib.h>
#include <stdio.h>

void plus_une_case(char* a);
//Tableau de char en entrée, tableau de char + 1 case en sortie
int deuxp(int a);
//2 puissance a
char* convert_d_b(char a);
//Entrée un caractère ASCII, Sortie son code binaire
int convert_b_d(char* p);
//Entrée un octet de char, Sortie la valeur de l'octet binaire en Entier
int taille_c(char* p);
//Entrée un tableau de char, Sortie longueur tab
void init(char *tab);
//Initialisation de l'octet de compression à '2'
int reste(char *tab);
//Entrée octet, Sortie nombre de '2'