#include<stdio.h>

int main(void) {
    int n;
    
    scanf("%d ",&n);
    
    char s[n+1];
    s[n]='\0';
    for(int i=0;i<n;i++) {
        scanf("%c",&s[i]);
    }
    int i=0,j=n-1;
    int flag=1;
    while(i<j) {
        if(s[i]>='A'&&s[i]<='Z') {
            s[i] += ('a'-'A');
        }
        
        if(s[j]>='A'&&s[j]<='Z') {
            s[j] += ('a'-'A');
        }
        
        if(!(s[i]>='a'&&s[i]<='z')) i++;
       
        else if(!(s[j]>='a'&&s[j]<='z')) j--;
        
        else {
            
            if(s[i]!=s[j]) {
                flag=0;
                break;
            }
            i++;
            j--;
        }
    }
    
    if(flag)
        printf("YES");
    
    else 
        printf("NO");
}
