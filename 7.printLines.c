#include<stdio.h>

int main() {
    
    int n;
    
    //No. of lines 
    
    printf("Total lines: ");
    
    scanf("%d", &n);
    
    while(n-->=0) {
        
        char s[10000];
        
        //scan my line
       	
	fgets(s,10000,stdin);
        
	int i;
        
        for(i=0;s[i]!='\0'&&i<=80;i++); 
            
        if(i>80) printf("%s\n", s);
       
    }
    return 0;
}
