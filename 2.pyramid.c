#include<stdio.h>
int main() {
    //height of pyramid
    int n;
    
    printf("Enter height ");    
    
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n-i;j++) {
            printf(" ");
        }
        for(int k=0;k<i;k++) {
            printf("# ");
        }
        for(int j=1;j<=n-i;j++) {
            printf(" ");
        }
    
    	printf("\n");
    }
}

