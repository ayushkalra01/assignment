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

int fun(char c) {
    if(c=='*'||c=='/')return 4;
    if(c=='+'||c=='-') return 3;
    if(c=='('||c==')')return -1;
    return 0;
}

int main() {
    
    char s[50];
    
    scanf("%s", s);
    
    int n=strlen(s);
    
    struct stack *stk = create(n);
    char ans[50];
    int c=0;
    for(int i=0;i<n;i++) {
        int d = fun(s[i]);
        
        if(d == 0) {
            ans[c++] = s[i];
        }
        else if(empty(stk)||s[i]=='('||peek(stk)=='('){push(s[i],stk);}
        else {
                
                if(s[i]==')') {
                    while(peek(stk)!='(') {
                        if(fun(peek(stk))!=-1)
                        ans[c++]=peek(stk);
                            pop(stk);
                    }
                    pop(stk);
                }
                    else if(d>fun(peek(stk))) {
                        
                       push(s[i],stk);
                    }
                    else {
                        while(!empty(stk)&&peek(stk)!='('&&d<=fun(peek(stk))) {
                            ans[c++]=peek(stk);
                            pop(stk);
                        }
                        push(s[i],stk);
                    }
                
            }
        
    }
     while(!empty(stk)) {
            if(fun(peek(stk))!=-1)
                            ans[c++]=peek(stk);
                            
                            pop(stk);
                        }
    ans[c]='\0';
    printf("%s",ans);
}
