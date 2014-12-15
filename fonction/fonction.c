#include "fonction.h"
int taille_c(char * p){//Il recoit un char car tabNoeud[i].code est passé comme une string qui sera lue "char" par "char"
  int j=0;
  while(p[j]!='\0')
    {
      j++;
    }
  return j;
}
int convert_b_d(char * p){
  int i,result=0; 
  for(i=0;i<8;i++){
    if(p[i]=='1'){
      result=result+deuxp(7-i);
    }
  }
  return result;
}
/*
unsigned int* convert_d_b(int a){
  int i;
  unsigned int *result=malloc(8*sizeof(unsigned int));
  for(i=7;i>-1;i--){
      if((a-deuxp(i))>=0){
	  result[i]=1;
	  a=a-deuxp(i);}
      else{
	  result[i]=0;}}
  return result;}

*/
char* convert_d_b(int a){
    int i=0;
    char* octet = malloc(8);
    for(i=0; i<8; i++){
        octet[i] = (a & 1) + '0';
        a >>= 1;
    }
    return octet;
}
int deuxp(int a){
  int result=1;
	while(a>0){
		result*=2;
		a--;
	}
  return result;
}
void plus_une_case(char * a){
  int t=taille_c(a);
 a=realloc(a, sizeof(char)*(t+1));
  a[t]='0';
  }

int reste(char* tab){
  int reste=0;  
  int i;
  for(i=0;i<8;i++){
    if(tab[i]=='2'){
      reste+=1;
    }
  }
 return reste;
  }

void init(char *tab){
  int i;
  for(i=0;i<8;i++){
    tab[i]='2';
      }
 }
