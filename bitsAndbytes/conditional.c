#include<stdio.h>

int fun(int x, int y, int z) {
    x=!(!x);
    
    int c = x ^ 1;
    
}

int main(void) {
   int x=3;
  int y=4;
    int z=5;
    
   printf("%d",fun(x,y,z));
    
    return 0;
}
