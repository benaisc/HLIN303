//Hlin303:Huffman
#include "./arbre/arbre.h"
#include "./fonction/fonction.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

/*TESTS INTEGRITE*/
if (argc!=3){
printf("Syntax Error.\n");
return 1;
}
FILE *f=fopen(argv[1],"r");
if(!f){
printf("Fichier non trouvé.\n");
fclose(f);
return 2;
}
int c=fgetc(f);
if(c==EOF){
printf("Fichier vide.\n");
fclose(f);
return 3;
}


// ./dehuf fichierhuf.txt
/*Remplissage d'un tab avec l'en-tete*/
 printf("test0\n");
 FILE *x=fopen(argv[1],"r");//argv[1] = fichierhuf.txt
 char car=43;
 int nbnoeud=-1,indice=0;
 int i=-1;
 int temp1=-128,temp2=-129;
 NoeudSC *Arbre=malloc(sizeof(NoeudSC));
 nbnoeud=0;indice=0;
 while(!((temp1=='&')&& (temp2=='&'))){
   car=fgetc(x);
   temp2=temp1;
   temp1=(int)car; //entier du code ascii correspondant ex: nbnoeud:74 
   if(car=='&'){
   }
   else{
     if(temp2=='&'){
       nbnoeud+=1;
       Arbre=realloc(Arbre,nbnoeud*sizeof(NoeudSC));
       Arbre[nbnoeud-1].symbole=car;
       i-=1;
       indice=0;
     }
     else if (i==-1){
       nbnoeud+=1;

       Arbre=realloc(Arbre,nbnoeud*sizeof(NoeudSC));
       if(Arbre==NULL) {
	 printf("PUTAIN DE MERDE");
       }
       Arbre[nbnoeud-1].symbole=car;
       i-=1;
       indice=0;
     }
     else if (i==-2){
       i=atoi(&car)-1;
       printf("car=%d\n",i+1);
       Arbre[nbnoeud-1].code=malloc((i+1)*sizeof(char));
       Arbre[nbnoeud-1].code[i]='\0';

       if(Arbre[nbnoeud-1].code==NULL) {
	 printf("LA BITCH");
       }
     }
     else{
       Arbre[nbnoeud-1].code[indice]=car;
       i-=1;
       indice+=1;
     }  
   }
 }
 int GRR=0;
 printf("test6\n");
 for(GRR=0;GRR<nbnoeud;GRR++){
   int taille=0;
taille= taille_c(Arbre[GRR].code);
  printf("Arbre[%d].symbole=%c Arbre[%d].code=%s de taille=%d\n",GRR,Arbre[GRR].symbole,GRR,Arbre[GRR].code,taille);
 }
/*Remplissage de tableaux d'octets*/

FILE *y=fopen(argv[2],"w");

char* octet = malloc(8*sizeof(char));
int carr=0;

while(EOF!=(car=fgetc(x))){
  octet=convert_d_b(carr);
  printf("__%s__\n",octet);
 }

 while(A->fg != NULL && A->fg != NULL){
   if(octet[i]='0'){
     A=A->fg;
   }
   else{
     A=A->fd;
     }
 }
 fwrite(tabNoeud[i].symbole,sizeof(char),1,y);
 A=Arbre;

 for(GRR=0;GRR<nbnoeud;GRR++){
   free(Arbre[GRR].code);
 }
 free(Arbre);

return 0;
}
