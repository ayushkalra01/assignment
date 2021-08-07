#include<stdio.h>
int main() {

        int num1=0,num2=0;

        printf("Enter numbers ");
        
	scanf("%d %d", &num1, &num2);
        
	num1 = num1 + num2;
        
	num2 = num1 - num2;
        
	num1 = num1 - num2;

        printf("Swapped numbers:%d %d", num1, num2);
        
	return 0;
}


