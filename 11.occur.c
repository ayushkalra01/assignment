#include<stdio.h>
int n,m;


int check(char c, char *s2) {
    for(int i=0;i<m;i++) {
        if(s2[i]==c)
            return 1;
    }   
    return 0;
}

int occur(char *s1, char *s2) {
    
    int c=0;
    for(int i=0;i<n;i++) {
        if(check(s1[i],s2)) {
            return i;
        }
    }
  
    return -1;
}

int main(void) {
    
    scanf("%d %d",&n,&m);
    
    char s1[n+1],s2[m+1];
    scanf("%s ",s1);
    scanf("%s",s2);
    
   printf("%d",occur(s1,s2));
    
}
