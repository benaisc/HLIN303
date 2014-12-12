#include"arbre.h"
ArbreBin creerArbreBin(int e, ArbreBin G, ArbreBin D){
  /* Res : renvoie une ArbreBin dont la racine vaut e, le sag G et le sad D   */
  NoeudSC b;
  ArbreBin A=&b;
  A->val=e;  A->fg=G;  A->fd=D;
  return A;}

void code(ArbreBin A){
  int i=0;
  if(A->fg!=NULL && A->fd!=NULL)
    {	
      if(A->parent==NULL)
	{
	  A->fg->code=realloc(A->fg->code, sizeof(char));
	  A->fd->code=realloc(A->fd->code, sizeof(char));
	  A->fg->code[0]='0';
	  A->fd->code[0]='1';
	  code(A->fd);
	  code(A->fg);
	}
      else
	{
	  if(A->fd->parent==A)
	    {
	      while(A->code[i]!='\0')
		{
		  i++;
		}
	      A->fd->code=realloc(A->fd->code, sizeof(char)*(i+1));
	      i=0;
	      while(A->code[i]!='\0')
		{
		  A->fd->code[i]=A->code[i];
		  i++;
		}
	      A->fd->code[i]='1';
	    
	      code(A->fd);
	    }
	  i=0;
	  if(A->fg->parent==A)
	    {
	      while(A->code[i]!='\0')
		{
		  i++;
		}
	      A->fg->code=realloc(A->fg->code, sizeof(char)*(i+1));
	      i=0;
	      while(A->code[i]!='\0')
		{
		  A->fg->code[i]=A->code[i];
		  i++;
		}
	      A->fg->code[i]='0';
	      
	      code(A->fg);
	    }
	}
      //printf("A->val=%d A->code=%s\n",A->val,A->code);
    }
}
    

 


