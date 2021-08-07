#include<stdio.h>
#include<stdlib.h>
struct queue {
  
    int rear, front;
    
    int size;
    int *a;
   
};

struct queue *create(int n) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    
    q->front = -1;
    q->rear = -1;
    q->size = n;
    q->a = (int*)malloc(n*sizeof(int));
    
    return q;
}

void enqueue(int x, struct queue *q) {
    
    if(q->front == (q->rear + 1) % q->size) {
        printf("Full\n");
    }
    else {
        //empty
        if(q->rear== -1 && q->front == -1) {
            q->rear=0;
            q->front=0;
            q->a[q->rear] = x;
        }
        else {
        q->rear = (q->rear + 1) % q->size;
        q->a[q->rear] = x;
        }
    }
}

int dequeue (struct queue *q) {
    
    int t=-1;
    //empty
    if(q->front == -1 && q->rear == -1) {
         printf("empty\n");
    }
    
  else  if(q->front==q->rear) {
       // last value
        
        t=q->a[q->front];
        q->front = -1;
        q->rear = -1;
        
        printf("%d\n",t);
    }
    else {
         t = q->a[q->front];
        q->a[q->front] = -1;
        
        q->front = (q->front + 1) % q->size;
        printf("%d\n",t);
    }
    
    return t;
}

int peek (struct queue *q) {
    printf("%d\n", q->a[q->front]);
    
    return q->a[q->front];
}

int is_empty(struct queue *q) {
    if(q->front == -1 && q->rear == -1) {
        printf("Empty");
    }
    else {
        printf("Not empty");
    }
    
    return q->front==q->rear;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
   struct queue *q= create(n);
    
    
    enqueue(66,q);
    enqueue(15,q);
    enqueue(25,q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(95,q);
    dequeue(q);
    
    return 0;
}
