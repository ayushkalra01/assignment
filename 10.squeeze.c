#include<stdio.h>
#include<stdlib.h>
int n,m;


int check(char c, char *s2) {
    for(int i=0;i<m;i++) {
        if(s2[i]==c)
            return 0;
    }   
    return 1;
}

char *squeeze(char *s1, char *s2) {
    
    char *s=(char*)(calloc(n+1,sizeof(int)));
    int c=0;
    for(int i=0;i<n;i++) {
        if(check(s1[i],s2)) {
            s[c]=s1[i];
            c++;
        }
    }
    s[c]='\0';
    return s;
}

int main(void) {
    
    scanf("%d %d",&n,&m);
    
    char s1[n+1],s2[m+1];
    scanf("%s ",s1);
    scanf("%s",s2);
    
   printf("%s",squeeze(s1,s2));
    
}
