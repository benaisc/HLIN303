
#include"./arbre/arbre.h"

int main(int argc, char* argv[]){
  /*Test nombre d'arguments*/
  if (argc!=2){
    printf("Syntax Error.\n");
    return 1;
  }
  int occ[256];
  int nbfeuille=0;
  int i=0;
float tailledep=0;
  
  /*Initialisation des occurences a 0*/
  for(i=0;i<256;i++){
    occ[i]=0;
  }

  /*Test du fichier*/
  FILE *f=fopen(argv[1],"r");
  int c=0;
  if(!f){
    printf("Fichier non trouvé.\n");
    return 2;
  }
  c=fgetc(f);
 if(c==EOF){
    printf("Fichier vide.\n");
    fclose(f);
    return 3;
 }

  fclose(f);

  /*Creation du tableau de caractères et de leur fréquence*/
  f=fopen(argv[1],"r");
  while(EOF!=(c=fgetc(f))){
    occ[c]+=1;
    tailledep+=8;
  }
  fclose(f);
  for(i=0;i<256;i++){
    if(occ[i]!=0){
      nbfeuille+=1;
    }
  }
  int indice=0;
  int val[(2*nbfeuille)-1];
  int fg[(2*nbfeuille)-1]; 
  int fd[(2*nbfeuille)-1]; 
  int parent[(2*nbfeuille)-1];
  char car[nbfeuille];
  NoeudSC tabNoeud[2*nbfeuille-1];
 
  for(i=0;i<2*nbfeuille-1;i++){
    val[i]=-1;
    parent[i]=-1;
    fg[i]=-1;
    fd[i]=-1;
  }

  printf("Indice (caractère) : occurences\n");

  for(i=0;i<256;i++){
    if(occ[i]!=0){
      val[indice]=occ[i];
      car[indice]=i;
      printf("%d (%c):%d\n",indice,i,occ[i]);
      indice+=1;
    }
  }

  printf("nbfeuille=%d\nindice=%d\n",nbfeuille,indice);

  printf("\n_____________________Remplissage tableaux______________________\n");
int imini=-1, imini2=-1, nn=2*nbfeuille-1;
 for(nn=nbfeuille;nn<2*nbfeuille-1;nn++){
   for(i=0;i<nn;i++){
     if(parent[i]==-1){
       if(imini==-1){
     imini=i;
       }
       else if(imini2==-1){
     if(val[i]<val[imini]){
       imini2=imini;
       imini=i;
     }
     else{
       imini2=i;
     }
       }
       else if(val[i]<val[imini2]){
     if(val[i]<val[imini]){
       imini2=imini;
       imini=i;
     }
     else{
       imini2=i;
     }
       }
     }
   }
   val[nn]=val[imini]+val[imini2];
   fg[nn]=imini;
   fd[nn]=imini2;
   parent[imini]=nn;
   parent[imini2]=nn;
   imini=-1;
   imini2=-1;
 }
 
 printf("Affichage tableaux\n");
 for(i=0;i<2*nbfeuille-1;i++){
   if(i<nbfeuille){
     printf("Ind:%d Car:%c Val:%d fg:%d fd:%d parent:%d\n",i,car[i],val[i],fg[i],fd[i],parent[i]);
   }
   else{
     printf("Ind:%d   /   Val:%d fg:%d fd:%d parent:%d\n",i,val[i],fg[i],fd[i],parent[i]);
   }
 }
 printf("___________________________Remplissage tabNoeud___________________________\n");
 for(i=0;i<2*nbfeuille-1;i++)
   {
     tabNoeud[i].val=val[i];
     //printf(" tabNoeud[%d].val =%d et  Val[%d]:%d\n",i,tabNoeud[i].val,i,val[i]);
     if(i!=2*nbfeuille-2)
       {
	 tabNoeud[i].parent=&tabNoeud[parent[i]];
       }
     else
       {
	 tabNoeud[i].parent=NULL;
       }
     //printf(" tabNoeud[%d].parent =%d parent[%d]=%d\n" ,i,tabNoeud[i].parent,i,parent[i]);
   }

 for(i=0;i<nbfeuille;i++)
   {
     tabNoeud[i].symbole=car[i];
     //printf("%c=%c\n",tabNoeud[i].symbole,car[i]);
   }
 for(i=0;i<nbfeuille;i++)
   {
     tabNoeud[i].fd=NULL;
     tabNoeud[i].fg=NULL;
     // printf(" tabNoeud[%d].fd =%d fd[%d]=%d tabNoeud[%d].fg =%d fg[%d]=%d\n" ,i,tabNoeud[i].fd,i,fd[i],i,tabNoeud[i].fg,i,fg[i]);
   }   
 for(i=nbfeuille;i<2*nbfeuille-1;i++)
   {
     tabNoeud[i].fd=&tabNoeud[fd[i]];
     tabNoeud[i].fg=&tabNoeud[fg[i]];
     // printf(" tabNoeud[%d].fd =%d fd[%d]=%d tabNoeud[%d].fg =%d fg[%d]=%d\n" ,i,tabNoeud[i].fd,i,fd[i],i,tabNoeud[i].fg,i,fg[i]);
   }
 for(i=0;i<2*nbfeuille-1;i++)
   {
     tabNoeud[i].code=NULL;
     //printf("symbole : %c nombre d'occurence : %d code: %s \n",tabNoeud[i].symbole,tabNoeud[i].val,tabNoeud[i].code);
   }
 
 /*printf("Affichage tabNoeud\n");
 for(i=0;i<2*nbfeuille-1;i++)
   {
     if(i<nbfeuille)
       {
	 printf("tabNoeud[%d]: val:%d code:%s  parent:%d fgval: fdval: \n",i,tabNoeud[i].val,tabNoeud[i].code,tabNoeud[i].parent->val);
       }
     else if(i==2*nbfeuille-2)
       {
	 printf("tabNoeud[%d]: val:%d code:%s  parent: fgval:%d fdval:%d \n",i,tabNoeud[i].val,tabNoeud[i].code,tabNoeud[i].fg->val,tabNoeud[i].fd->val);
       }
     else
       {
	 printf("tabNoeud[%d]: val:%d code:%s  parent:%d fgval:%d fdval:%d \n",i,tabNoeud[i].val,tabNoeud[i].code,tabNoeud[i].parent->val,tabNoeud[i].fg->val,tabNoeud[i].fd->val);
       }
   }
 */

 
 printf("_______________Remplissage codes_______________\n");
 if(2*nbfeuille-2==0)
   {
   tabNoeud[0].code="0";
    printf("symbole : %c nombre d'occurence : %d code:%s \n",tabNoeud[0].symbole,tabNoeud[0].val,tabNoeud[0].code);
   }
 else
   {
     ArbreBin A=&(tabNoeud[2*nbfeuille-2]);
     //printf("val:%d code:%s  fgval:%d fdval:%d \n",A->val,A->code,A->fg->val,A->fd->val);
     code(A);
     for(i=0;i<nbfeuille;i++)
       {
	 printf("symbole : %c nombre d'occurence : %d code:%s \n",tabNoeud[i].symbole,tabNoeud[i].val,tabNoeud[i].code);
       }
   }
 printf("_Crée un nouveau fichier texte en fonction du code associé à chaque lettre_\n");
 FILE *g=fopen(argv[1],"r");
 FILE *h=fopen("file.txt","a");
 int lu=0;
 i=0;
 int j=0;
float taillefin=0;
 while(EOF!=(lu=fgetc(g))){
   while(lu!=tabNoeud[i].symbole)
     {
       i++;
     }
   while(tabNoeud[i].code[j]!='\0')
     {
       // printf("i\n");
       j++;
     }
   fwrite(tabNoeud[i].code,j,sizeof(char),h);
   taillefin+=1;
   j=0;

 }
 fclose(g);
 fclose(h);
 //affichage de la longeur moyenne de codage
 float lm=0;
 for(i=0;i<nbfeuille;i++){
while(tabNoeud[i].code[j]!='\0')
     {
       j++;
     }
 lm=lm+j*tabNoeud[i].val;
 j=0;
 }
 lm=lm/(tailledep/8);
 printf("Longeur moyenne de codage=%.2f bits\n",lm);
 //affichage des tailles
 printf("Taille originelle : %d bits soit %d octets\nTaille compressée: %d bits soit %d octets\nGain=%.2f\%\n",(int)tailledep,(int)tailledep/8,(int)taillefin,(int)taillefin/8,((tailledep-taillefin)/tailledep)*100);

 return 0;
}
