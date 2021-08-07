#include<stdio.h>

int main(void) {
    int n;
    
    scanf("%d ",&n);
    
    char s[n+1];
    s[n]='\0';
    for(int i=0;i<n;i++) {
        scanf("%c",&s[i]);
    }
 
    
    for(int i=0;i<n/2;i++) {
        char temp;
        temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
    
    for(int i=0;i<n;i++) {
        if(s[i]==' ')continue;
        
        int j=i;
        
        while(j!=n&&s[j]!=' ') {
            j++;
        }
        
        int c=1;
        int k=i;
        int size=(j-i)/2;
        
        while(size--) {
            char temp =s[k];
            s[k]=s[j-c];
            s[j-c]=temp;
            c++;
            k++;
        }
        i=j;
    }
    printf("%s",s);
}
