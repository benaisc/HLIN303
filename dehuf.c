#include "./arbre/arbre.h"
#include "./fonction/fonction.h"

int main(int argc, char* argv[]){

//TESTS INTEGRITE
if (argc!=3){
printf("Syntax Error.\n");
return 1;
}
FILE *fic=fopen(argv[1],"r");
if(!fic){
printf("Fichier non trouvé.\n");
fclose(fic);
return 2;
}
int c=fgetc(fic);
if(c==EOF){
printf("Fichier vide.\n");
fclose(fic);
return 3;
}
fclose(fic);

//***_Decodage de l'entete_***
	FILE *x=fopen(argv[1],"r");//argv[1] = fichierhuf.txt
	unsigned char car;
	car=fgetc(x);
//printf("1er char lu = %d\n",car);
	unsigned int nbBitsLire=((int) car);
//printf("Bits à lire : %d\n",nbBitsLire);//nombre de bits a lire dans les char qui suivent pour connaitre le nombre de bits à lire une fois la table d'encodage crée
 	unsigned char* CODE_BIN;
	car=fgetc(x);
//printf("2e char lu : %d\n",car);
 	CODE_BIN=int_to_bin((int)car);
//printf("Son code binaire : %s\n",CODE_BIN);
	unsigned char* CODE_BIN_SUP=malloc(nbBitsLire*sizeof(char)+1);

	if(nbBitsLire<=8){
	 	int i=0;
		for(i=0;i<nbBitsLire;i++){
			CODE_BIN_SUP[i]=CODE_BIN[i];
		}
	CODE_BIN_SUP[i+1]='\0';
	car=fgetc(x);//car=&
	//printf("CODE_BIN_SUP=%s\n",CODE_BIN_SUP);
	}
	else{
		int i=0;
		for(i=0;i<8;i++){
			CODE_BIN_SUP[i]=CODE_BIN[i];
		}
		car=fgetc(x);
		CODE_BIN=int_to_bin((int)car);
		int j=8;
		while(car != '&'){
		i=0;
			while((j < nbBitsLire)&&(i < 8)){
				CODE_BIN_SUP[j]=CODE_BIN[i];
				j+=1;
				i+=1;
			}
		CODE_BIN_SUP[nbBitsLire]='\0';
		car=fgetc(x);//car=&
		}
//printf("CODE_BIN_SUP=%s\n",CODE_BIN_SUP);
	free(CODE_BIN);
	}
	unsigned int nbBitsTotal=bin_to_dec(CODE_BIN_SUP);
	printf("nbBits d'encodage=%d\n",nbBitsTotal);
	free(CODE_BIN_SUP);

//***_Remplissage d'une structure de décodage_***
	NoeudSC *Arbre=NULL;
	int nbnoeud=0;
	int ind=0;
	int i=-1;
	int k=0;
	char CHECK=NULL;
	car=fgetc(x);
//printf("Car de départ = %c\n",car);
	while((car != '&')&&((CHECK=fgetc(x)) != '&')){
//printf("STAGE %d : car = %c - CHECK=%c avec i=%d\n",nbnoeud,car,CHECK,i);
		if(i==-1){
			nbnoeud+=1;
			Arbre=realloc(Arbre,nbnoeud*sizeof(NoeudSC));
			Arbre[nbnoeud-1].symbole=car;
			i-=1;
//printf("i==-1 -> Arbre[%d].symbole=%c\n",nbnoeud-1,Arbre[nbnoeud-1].symbole);
			car=CHECK;
		}
		else{
			ind=((int) car)-48;
//printf("Taille du code : ind=%d\n",ind);
			Arbre[nbnoeud-1].code=malloc((ind+1)*sizeof(char));
			for(k=0;k<ind;k++){
				Arbre[nbnoeud-1].code[k]=CHECK;
				CHECK=fgetc(x);
			}
		Arbre[nbnoeud-1].code[ind]='\0';
		car=CHECK;
		i=-1;
//printf("i==-2 -> Arbre[%d].code=%s\n",nbnoeud-1,Arbre[nbnoeud-1].code);
		}
	}

/*   
	while(CPT<nbBitsTotal){
		mettre bit à bit dans un char* et tester tous les codes, CPT++
		si un code correspond coller le symbole
	}
*/

	int G=0;
	for(G=0;G<nbnoeud;G++){
		printf("Arbre[%d] : symbole=%c code=%s\n",G,Arbre[G].symbole,Arbre[G].code);
	}
 
free(Arbre);
return 0;
}
