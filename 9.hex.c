#include<stdio.h>

int value(char a) {
    
    if(a>='0'&&a<='9')
    return (a-'0');
    
    int p=(a-'a')+10;
    
    return p;
    
}

int main() {
    
    //length of a string
    
    printf("Enter length:"); 
    int n;
    
    scanf("%d", &n);
    
    char s[n+1];
    
    scanf("%s", s);
    
   int ans=0;
    
    int c=1;
    
    for(int i=n-1;i>=2;i--) {
        ans = ans + c * value(s[i]);
        
        c = c * 16;
    }
    
    printf("%d\n", ans);
    return 0;
}
