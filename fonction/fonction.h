#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void plus_une_case(unsigned char* a);
//Tableau de char en entrée, tableau de char + 1 case en sortie
int deuxp(int a);
//2 puissance a
char* convert_d_b(char a);
//Entrée un caractère ASCII, Sortie son code binaire
int convert_b_d(char* p);
//Entrée un octet de char, Sortie la valeur de l'octet binaire en Entier
unsigned int taille_c(unsigned char *p);
//Entrée un tableau de char, Sortie longueur tab
int reste(unsigned char *tab);
//Entrée octet, Sortie nombre de '2'
unsigned char* int_to_bin(unsigned int nbBits);
//Prend un entier quelconque et retourne son code binaire dans un char*
void init_octet(unsigned char *tab);
//Initialisation de l'octet de compression à '2'
unsigned long int bin_to_dec(unsigned char *p);
