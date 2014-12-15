#include "fonction.h"
int main(int argc, char* argv[]){

 int i,j;
 int carre;
 char dec;
 char *bin;
  for(i=0;i<256;i++){
    bin=convert_d_b((char)i);
    carre=deuxp(i);
    printf("2^%d= %d    ",i,carre);
    printf("i=%d DEC:i=%c BIN:i=%s",i,(char)i,bin);
    printf("\n"); 
  }
   printf("ATTENTION!!!!!");
    for(i=0;i<256;i++){
      bin=convert_d_b((char)i);
      dec=convert_b_d(bin);
      printf("i=%d DEC:i=%c BIN:i=%s",i,dec,bin);
      printf("\n"); 
    }
  
  return 0;
}
