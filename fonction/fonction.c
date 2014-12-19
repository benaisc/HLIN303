#include "fonction.h"

unsigned int taille_c(unsigned char *p){//Il recoit un char car tabNoeud[i].code est passé comme une string qui sera lue "char" par "char"
  unsigned int j=0;
  while(p[j]!='\0')
    {
      j++;
    }
  return j;
}
int convert_b_d(char *p){
  int i,result=0; 
  for(i=0;i<8;i++){
    if(p[i]=='1'){
      result=result+deuxp(7-i);
    }
  }
  return result;
}

char* convert_d_b(char a){
  int i;
  char *result=malloc(8*sizeof(char));
  int b=(int)a;
  if(b<0){
    b=b+256;
  }
  for(i=0;i<8;i++){
      if((b-deuxp(7-i))>=0){
	  result[i]='1';
	  b=b-deuxp(7-i);}
      else{
	  result[i]='0';}}
  return result;}


int deuxp(int a){
  int result=1;
	while(a>0){
		result*=2;
		a--;
	}
  return result;
}
void plus_une_case(unsigned char *a){
  unsigned int t=taille_c(a);
  a=realloc(a, sizeof(char)*(t+1));
  a[t]='0';
  }

int reste(unsigned char* tab){
  int reste=0;  
  int i;
  for(i=0;i<8;i++){
    if(tab[i]=='2'){
      reste+=1;
    }
  }
  tab[8]='\0';
 return reste;
  }

//Prend un entier retourne un char* de son binaire
unsigned char* int_to_bin(unsigned int nbBits){
    int i = 0;
    unsigned char* octet = malloc(sizeof(char));
    octet[0]='\0';
    
    while(nbBits != 0){
		if(nbBits%2 == 0){
			octet=realloc(octet,sizeof(char)*(i+2));
			octet[i]='0';
			octet[i+1]='\0';
		}
		else{
			octet=realloc(octet,sizeof(char)*(i+2));
			octet[i]='1';
			octet[i+1]='\0';
		}
		nbBits=nbBits/2;
		i+=1;
    }
    unsigned char* octet_revers = malloc(sizeof(char)*i+1);
    int ind=0;
	while(i>0){
		octet_revers[ind]=octet[i-1];
		i-=1;
		ind+=1;
	}
	octet_revers[ind]='\0';
	return octet_revers;
}
//Transforme un char* en int
unsigned long int bin_to_dec(unsigned char *p){
	int ind=0;
	while(p[ind]!='\0'){
		ind+=1;
	}
	unsigned long int result=0;
	int i=0;
	while(p[i]!='\0'){
		if(p[i]=='1'){
			result=result+deuxp(ind-i-1);
			i+=1;
		}
		else{
			i+=1;
		}
	}
return result;
}
void init_octet(unsigned char *tab){
	int i;
	for(i=0;i<8;i++){
		tab[i]='2';
    }
tab[8]='\0';
}
