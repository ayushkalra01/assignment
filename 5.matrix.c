#include<stdio.h>


void reverse(int *a, int n) {
    
    for(int i=0;i<n/2;i++) {
        int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    
}

int main() {

    int n1, m1, n2, m2; //row and columns
   
        printf("Enter Dimentions\n");
        
            scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
    
    if(m1!=n2) {
        printf("ERROR");
        return 0;
    }
    
    int a[n1][m1];
    int b[n2][m2];
    
    
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m1;j++)
        scanf("%d",  &a[i][j]);
    }
    
    int res[n1][m2];
    
    for(int i=0;i<n2;i++) {
        for(int j=0;j<m2;j++)
        scanf("%d",  &b[i][j]);
    }
   
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m2;j++) {
            res[i][j]=0;
            
            for(int k=0;k<n2;k++) {
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m2;j++)
        printf("%d ",res[i][j]);
        printf("\n");
    }
    
    
    return 0;
}

