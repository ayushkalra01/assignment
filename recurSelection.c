#include <stdio.h>


int n;

int minimum(int *a, int i) {
    
    if(i==n-1) {
        return i;
    }
    
    int k=minimum(a,i+1);
    
    if(a[i] > a[k]) return k;
    
    else return i;
}

void selectionsort(int *a, int i) {
    
    if(i==n) {
        return;
    }

   int mini=minimum(a, i);
    
    if(mini != i) {
        
        int temp = a[i];
        
        a[i] = a[mini];
        
        a[mini] = temp;
        
    }
    
    selectionsort(a, i + 1);
}

int main() {
    
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    
    selectionsort(a, 0);
    
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    
    return 0;
}
