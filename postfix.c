#include<stdio.h>
#include<stdlib.h>
struct stack {
  
    int top;
    int size;
    int *a;
   
};


    void is_empty(struct stack *stk) {
        if(stk->top==-1)
            printf("Empty");
        else
            printf("Not Empty");
             printf("\n");
    }
    
    void is_full(struct stack *stk) {
       if(stk->top==stk->size-1)
           printf("Full");
        else
            printf("Not full");
        printf("\n");
    }
    
    void push(int x, struct stack *stk) {
        
        if(stk->top==stk->size-1) {
            printf("Stack if full\n");
        }
        
        else {
            stk->top+=1;
            stk->a[stk->top] = x;
        }
    }
    
    int pop(struct stack *stk) {
        int ele=-1;
        if(stk->top==-1) {
            printf("Stack is empty\n");
        }
        else {
             ele = stk->a[stk->top];
            stk->a[stk->top] = -1;
            stk->top--;
        }
        return ele;
    }
    
    void peek(struct stack *stk) {
        printf("%d\n", stk->a[stk->top]);
    }
    

struct stack *create(int n) {
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = n;
    stk->a = (int*)malloc(n*sizeof(int));
    return stk;
}


int main() {
    
    int n;
    printf("Enter size of string and string: "); 
    scanf("%d", &n);
    char s[n+1];
    
    //enter string without spaces
    //assuming only one digit numbers
    scanf("%s", s);
    
    struct stack *stk = create(n);
    
    for(int i=0; i<n; i++) {
        if(s[i]>='0' && s[i]<='9') {
            push(s[i]-48,stk);
        }
        
        else {
            int b = pop(stk);
            int a = pop(stk);
            int ans;
            switch (s[i]) {
                case '+':
                ans=a + b;
                break;
                
                case '-':
                ans=a - b;
                break;
                
                case '*':
                ans=a * b;
                break;
                
                case '/':
                ans=a / b;
                break;
            }
            
            push(ans,stk);
        }
    }
    printf("%d",pop(stk));
    return 0;
}
