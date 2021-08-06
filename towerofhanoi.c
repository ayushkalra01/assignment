#include <stdio.h>

int c=0;


void tower(int n, char from, char to, char aux)
{
  if(n==0)
   {  
    return ;	 
   }

  tower(n-1,from,aux,to);

  printf("%c to %c\n",from,to);
  c++;

  tower(n-1,aux,to,from);
}

int main()
{
  int n;
    
  scanf("%d",&n);

  tower(n,'A','C','B');

  printf("\nTotal movements required: %d\n",c);

}
