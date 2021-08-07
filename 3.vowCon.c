#include<stdio.h>

int main() {

    int n;
    //length of string
    printf("Enter Length:");
    scanf("%d", &n);
    
    char s[n+1];
    
    for(int i=0;i<n;i++) {
        scanf("%c", &s[i]);
    }
    s[n]='\0';
    
    
    int vow=0,con=0; //vowels consonants
    
    for(int i=0;i<n;i++) {
        char c=s[i];
        
        if(c>='A'&&c<='Z') {
            c = c + ('a'-'A');
        }
        
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')vow++;
           
           else
           con++;
    }
    printf("Vowels:%d\nConsonants:%d\n", vow, con);
    return 0;
}

