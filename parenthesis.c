#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack {
  
    int top;
    int size;
    int *a;
   
};


    int empty(struct stack *stk) {
        if(stk->top==-1)
            return 1;
        else
            return 0;
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
    
    int peek(struct stack *stk) {
        return stk->a[stk->top];
    }
    

struct stack *create(int n) {
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = n;
    stk->a = (int*)malloc(n*sizeof(int));
    return stk;
}
int main() {
    
    char s[50];
    
    scanf("%s", s);
    
    int n=strlen(s);
    
    struct stack *stk = create(n);
    
    for(int i=0;i<n;i++) {
        if(s[i]=='('||s[i]=='['||s[i]=='{') {
            push(s[i],stk);
        }
        
        else  {
            
            if(empty(stk)) {
                printf("False");
                return 0;
            }
            
            // flag to check if my closing bracket is the correct bracket of opening bracket
            int flag = 0;
            // printf("%c %c",s[i],peek(stk));
            switch (s[i]) {
                case ')':
                flag = peek(stk) == '(';
                break;
                case '}':
                flag = peek(stk) == '{';
                break;
                case ']':
                flag = peek(stk) == '[';
                break;
            }
            if(flag) {
                pop(stk);
            }
        }
    }
    
    // if not empty it means i am not able to balance them
        if(!empty(stk)) {
                printf("False");
               
            }
    else {
        printf("True");
    }
    return 0;
}
