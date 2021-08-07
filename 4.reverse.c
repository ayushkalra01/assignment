#include<stdio.h>


void reverse(int *a, int n) {
    
    for(int i=0;i<n/2;i++) {
        int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    
}

int main() {

    int n;
    //length of string
    printf("Enter Length:");
    scanf("%d", &n);
    
    int a[n];
    
    for(int i=0;i<n;i++) {
        scanf("%d",  &a[i]);
    }
    //function to reverse an array
    reverse(a,n);
    
    printf("Reversed array: ");
    
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    return 0;
}

