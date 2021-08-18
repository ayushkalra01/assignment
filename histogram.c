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
    
    void push(struct stack *stk,int x) {
        
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

int largestRectangleArea(int* arr, int n)
{

     struct stack *s = create(n);

      // right boundary

     int r[n];
     push(s,n-1);
     r[n-1]=n;

     for(int i=n-2;i>=0;i--)
     {
        while( s->top>=0 && arr[i]<=arr[peek(s)])
        {
           pop(s);
        }
        if(empty(s))
        {
           r[i]=n;
        }
        else
        {
           r[i]=peek(s);
        }
         push(s,i);
     }

     //left boundary
    while(!empty(s))
     {
         pop(s);
     }

     int l[n];
     push(s,0);
     l[0]=-1;

     for(int i=1;i<n;i++)
     {
        while( s->top>=0 && arr[i]<=arr[peek(s)])
        {
           pop(s);
        }
        if(s->top == -1)
        {
           l[i]=-1;
        }
        else
        {
           l[i]=peek(s);
        }
         push(s,i);
     }

     //max area

     int max=0;
        for(int i=0;i<n;i++)
        {
           int width = r[i]-l[i]-1;
           int area = arr[i] * width;
           if(area > max)
           {
              max = area;
           }
        }
        return max;


}
