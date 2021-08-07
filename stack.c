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
    
    void pop(struct stack *stk) {
        int ele=-1;
        if(stk->top==-1) {
            printf("Stack is empty\n");
        }
        else {
             ele = stk->a[stk->top];
            stk->a[stk->top] = -1;
            stk->top--;
            
        printf("%d\n", ele);
        }
        
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
    scanf("%d", &n);
    struct stack *stk = create(n);
    push(7,stk);
    push(9,stk);
    push(1,stk);
    peek(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    pop(stk);
    return 0;
}
