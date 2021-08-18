#include<stdio.h>

int sign(int a) {
    int b = a>>31;
    
    if(b)return 0;
    
    else return 1;
}
// 0 for positive
// 1 for negative
void main(void) {
    
    int a= 10;
    
    printf("%d ",sign(a));
    
    return 0;
}
