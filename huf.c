#include "./arbre/arbre.h"
#include "./fonction/fonction.h"

int main(int argc, char* argv[]){
//Test d'ouverture
	if(argc!=3){
    printf("Syntax Error.\n");
    return 1;
  }

//Test du fichier
	FILE *f=fopen(argv[1],"r");
	if(!f){
		printf("%s non reconnu.\n",argv[1]);
		fclose(f);
		return 2;
	}
	int c=fgetc(f);
	if(c==EOF){
		printf("%s est vide.\n",argv[1]);
		fclose(f);
		return 3;
	}
	fclose(f);
//Initialisation des occurences a 0
	int occ[256];
	unsigned int i=0;
	for(i=0;i<256;i++){
		occ[i]=0;
	}

//Creation du tableau de caractères et de leur fréquence
	float tailledep=0;
	f=fopen(argv[1],"r");
	while(EOF!=(c=fgetc(f))){
		occ[c]+=1;
		tailledep+=8;
	}
	printf("Fichier de %.2f bits, soit %.2f octets(char)\n",tailledep,(tailledep/8));
	fclose(f);
	int nbfeuille=0;
	for(i=0;i<256;i++){
		if(occ[i]!=0){
			nbfeuille+=1;
		}
	}
printf("Fichier contenant %d caracteres differents\n",nbfeuille);

  int val[(2*nbfeuille)-1];
  int fg[(2*nbfeuille)-1]; 
  int fd[(2*nbfeuille)-1]; 
  int parent[(2*nbfeuille)-1];
  char car[nbfeuille];
//Initialisation tableaux
  for(i=0;i<2*nbfeuille-1;i++){
    val[i]=-1;
    parent[i]=-1;
    fg[i]=-1;
    fd[i]=-1;
  }

  printf("Indice (caractère) : occurences\n");
  int indice=0;
  for(i=0;i<256;i++){
    if(occ[i]!=0){
      val[indice]=occ[i];
      car[indice]=i;
      printf("%d (%c):%d\n",indice,car[indice],val[indice]);
      indice+=1;
    }
  }

//***_Creation Arbre_***
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
/*
printf("CHECK l'Arbre\n");
	for(i=0;i<2*nbfeuille-1;i++){
		if(i<nbfeuille){
			printf("Ind:%d Car:%c Val:%d fg:%d fd:%d parent:%d\n",i,car[i],val[i],fg[i],fd[i],parent[i]);
		}
		else{
			printf("Ind:%d   /   Val:%d fg:%d fd:%d parent:%d\n",i,val[i],fg[i],fd[i],parent[i]);
		}
	}
*/
//***_Remplissage Structure_***
  NoeudSC tabNoeud[2*nbfeuille-1];
  tabNoeud[2*nbfeuille-2].parent=NULL;
  tabNoeud[2*nbfeuille-2].fd=&tabNoeud[fd[2*nbfeuille-2]];
  tabNoeud[2*nbfeuille-2].fg=&tabNoeud[fg[2*nbfeuille-2]];
  for(i=0;i<2*nbfeuille-2;i++){//Les feuilles et les noeuds
    tabNoeud[i].val=val[i];
	tabNoeud[i].parent=&tabNoeud[parent[i]];
	tabNoeud[i].code=malloc(sizeof(char));
	tabNoeud[i].code[0]='\0';
	}
  for(i=0;i<nbfeuille;i++){//Les feuilles ont un car et pas de fils
      tabNoeud[i].symbole=car[i];
      tabNoeud[i].fd=NULL;
      tabNoeud[i].fg=NULL;
    }
  for(i=nbfeuille;i<2*nbfeuille-2;i++){//Les noeuds ont un fils
      tabNoeud[i].fd=&tabNoeud[fd[i]];
      tabNoeud[i].fg=&tabNoeud[fg[i]];
    }
//***_Remplissage codes_***
  if (nbfeuille == 1){
	  tabNoeud[0].val=val[0];
	  tabNoeud[0].code=malloc(2*sizeof(char));
	  tabNoeud[0].code[0]='0';
	  tabNoeud[0].code[1]='\0';	  
  }
  else{
    ArbreBin Arbre=&(tabNoeud[2*nbfeuille-2]);
    code(Arbre);
}
/*AFFICHAGE ARBRE
    for(i=0;i<nbfeuille;i++){
      printf("tabNoeud[%d]symbole : %c nombre d'occurence : %d code:%s \n",i,tabNoeud[i].symbole,tabNoeud[i].val,tabNoeud[i].code);
    }
*/
//***_Creation de l'entete du fichier compresser_***
//Compte nombre de "bits" à lire
	unsigned int cptBits=0;
	unsigned int nbBits=0;
	for(i=0;i<nbfeuille;i++){
		nn=0;
		cptBits=0;
    while(tabNoeud[i].code[nn] != '\0'){
		cptBits+=1;
		nn+=1;
    }
    cptBits=cptBits*tabNoeud[i].val;
    nbBits+=cptBits;
  }

//EN ENTETE DES DONNEES DE DECODAGE
	// du code a lire jusqu'a &&
	float taillefin=0;
	unsigned char *CODE_BIN;
	CODE_BIN=int_to_bin(nbBits);
	unsigned int lcode=0;
	lcode=taille_c(CODE_BIN);
	char ppconv;
	ppconv=lcode;
  	FILE* fic=NULL;
	fic=fopen(argv[2],"w");
	fwrite(&ppconv,sizeof(char),1,fic);
	taillefin+=8;
	
	unsigned int rest=8;
	unsigned int m=0;
	unsigned char *tabCode=malloc(sizeof(char)*9);
	init_octet(tabCode);
	m=lcode;
	i=0;
	unsigned int pp=0;
	while(CODE_BIN[i]!='\0'){
    if(m <= rest){
    	int j=0;
    	while(m>0){
			tabCode[8-rest]=CODE_BIN[i];
        	i+=1;
        	rest-=1;
        	m-=1;
      	}
      	int CPT=rest;//bits de completion
      	for(j=0;j<CPT;j++){
      		tabCode[8-rest]='0';
      		rest-=1;
      	}
     tabCode[8]='\0';
     pp=bin_to_dec(tabCode);
     ppconv=pp;
     fwrite(&ppconv,sizeof(char),1,fic);
     taillefin+=8;
      m-=1;
    }
    else{
      while(rest!=0){
		tabCode[8-rest]=CODE_BIN[i];
		i+=1;
		rest-=1;
      }
      tabCode[8]='\0';
      pp=bin_to_dec(tabCode);
      ppconv=(char) pp;
      fwrite(&ppconv,sizeof(char),1,fic);
      taillefin+=8;
      m-=8;
      rest=8;
    }
  }

	fwrite("&",sizeof(char),1,fic);
	free(tabCode);
	taillefin+=16;
	unsigned int Lcode;
	char Tcar;
	char LcodeChar;
	for(i=0;i<nbfeuille;i++){
		Lcode=taille_c(tabNoeud[i].code);
		LcodeChar='0'+Lcode;
		Tcar=tabNoeud[i].symbole;
		fwrite(&Tcar,sizeof(char),1,fic);//le char
		fwrite(&LcodeChar,sizeof(char),1,fic);//la taille de son code
		fwrite(tabNoeud[i].code,Lcode*sizeof(char),1,fic);//le code
		taillefin+=16+(Lcode*8);
	}
	fwrite("&",sizeof(char),1,fic);
	fwrite("&",sizeof(char),1,fic);
	taillefin+=16;
	fclose(fic);

//Remplissage d'un fichier compressé

	FILE *x=fopen(argv[1],"r");
	FILE *y=fopen(argv[2],"a");
	char k=0;
	unsigned char *tabCodes=malloc(sizeof(char)*9);
	init_octet(tabCodes);
	
	while(EOF!=(k=fgetc(x))){
		i=0;
		while(k!=tabNoeud[i].symbole){
      i+=1;
    }
    rest=reste(tabCodes);
    lcode=taille_c(tabNoeud[i].code);
    nn=0;
    if(lcode = rest){
	  int j=0;
      for(j=0;j<lcode;j++){
        tabCodes[8-rest]=tabNoeud[i].code[nn];
        nn+=1;
        rest-=1;
		}
	tabCodes[8]='\0';
    pp=bin_to_dec(tabCodes);
    ppconv=pp; 
    fwrite(&ppconv,sizeof(char),1,y);
    taillefin+=8;
    init_octet(tabCodes);
    rest=reste(tabCodes);
	}
    else if(lcode < rest){
      int j=0;
      for(j=0;j<lcode;j++){
        tabCodes[8-rest]=tabNoeud[i].code[nn];
        nn+=1;
        rest-=1;
      }
    }
    else{
      while(rest!=0){
		tabCodes[8-rest]=tabNoeud[i].code[nn];
		nn+=1;
		rest-=1;
      }
	tabCodes[8]='\0';
    pp=bin_to_dec(tabCodes);
    ppconv=pp; 
    fwrite(&ppconv,sizeof(char),1,y);
    taillefin+=8;
    init_octet(tabCodes);
    rest=reste(tabCodes);
	while((nn<lcode) && (rest>0)){
		tabCodes[8-rest]=tabNoeud[i].code[nn];
		nn+=1;
		rest-=1;
	}
    }
  }

//Vidage du buffer tabCodes s'il y à des restes
  if (k==EOF){
    unsigned char *temp=malloc(sizeof(char)*9);
    for(i=0;i<8;i++){
      if(tabCodes[i] != '2'){
	     temp[i]=tabCodes[i];
      }
      else{
	     temp[i]='0';
      }
    }
    tabCodes[8]='\0';
    int der=0;
    der=bin_to_dec(temp);
    char derconv=der;
    fwrite(&derconv,sizeof(char),1,y);
    taillefin+=8;
    free(temp);
  }
  free(tabCodes);
  fclose(x);
  fclose(y);


//Calcul longeur moyenne de codage
taillefin-=1;
  float lm=0;
  int p=0;
  i=0;
  for(i=0;i<nbfeuille;i++){
    while(tabNoeud[i].code[p]!='\0'){
      p+=1;
    }
    lm+=p*tabNoeud[i].val;
    p=0;
  }
  lm=lm/(tailledep/8);
  printf("Longeur moyenne de codage=%.2f bits\n",lm);
  printf("Taille originelle : %d bits soit %d octets\nTaille compressée: %d bits soit %d octets\nGain=%.2f\%\n",(int)tailledep,(int)tailledep/8,(int)taillefin,(int)taillefin/8,((tailledep-taillefin)/tailledep)*100);

  return 0;
}
