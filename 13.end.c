#include<stdio.h>
int n,m;

int occur(char *s1, char *s2) {
    
    int c=m-1;
    for(int i=n-1;i>=0;i--) {
        if(c<0)break;
        if(s1[i]!=s2[c])return 0;
        c--;
    }
  
    return c<=0;
}

int main(void) {
    
    scanf("%d %d",&n,&m);
    
    char s1[n+1],s2[m+1];
    scanf("%s ",s1);
    scanf("%s",s2);
    
   printf("%d",occur(s1,s2));
    
}
