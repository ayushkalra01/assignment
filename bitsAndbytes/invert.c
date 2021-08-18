#include<stdio.h>
#include<math.h>
int fun(int x,int p,int n) {

    int k= pow(2,n)-1;

   int y = k << (p-n); 
   
    return y ^ x;    
}

int main(void) {
   int x=37;
   int p=6;
   int n=3;
   printf("%d",fun(x,p,n));
    
    return 0;
}
