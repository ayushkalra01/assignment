#include <stdio.h>

int gcd (int x,int y) {
    if(y==0)
        return x;
    
    return gcd(y, x%y);
}

int main() {
    
    int x, y;
    
    scanf("%d %d",&x, &y);
    
   int ans = gcd(x,y);
    
   printf("%d ",ans); 
    return 0;
}
