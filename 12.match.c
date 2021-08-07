#include<stdio.h>
int n,m;


int check(char* s1, char *s2,int k) {
    for(int i=0;i<m;i++) {
        if(k==n)return 0;
        if(s1[k]!=s2[i])return 0;
        k++;
    }   
    return 1;
}

int occur(char *s1, char *s2) {
    
    int c=-1;
    for(int i=0;i<n;i++) {
        if(check(s1,s2,i)) {
            c=i;
        }
    }
  
    return c;
}

int main(void) {
    
    scanf("%d %d",&n,&m);
    
    char s1[n+1],s2[m+1];
    scanf("%s ",s1);
    scanf("%s",s2);
    
   printf("%d",occur(s1,s2));
    
}
