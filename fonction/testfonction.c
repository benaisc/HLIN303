#include "fonction.h"
int main(int argc, char* argv[]){
  int i,j,dec;
  int carre;
  unsigned int *bin;
  for(i=0;i<257;i++){
    bin=convert_d_b(i);
    carre=deuxp(i);
    printf("DEC:i=%d BIN:i=",i);
    for(j=0;j<8;j++)
      {
	printf("%d",bin[j]); 
      }
    printf("\n"); 
  }
  printf("ATTENTION!!!!!");
    for(i=0;i<257;i++){
      bin=convert_d_b(i);
      dec=convert_b_d(bin);
      printf("DEC:i=%d BIN:i=",dec);
      for(j=0;j<8;j++)
	{
	  printf("%d",bin[j]); 
	}
      printf("\n"); 
    }

  return 0;
}
