#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *next;
};

struct node *front;
struct node *rear;


void enqueue(int data)
{
   struct node *temp = (struct node*)malloc(sizeof(struct node));

   //isfull
   if(temp==NULL)
   {
       printf("Overflow");
       return;
   }
   else
   {
       temp->val=data;
       if(front==NULL)
       {
            front = temp;
            rear = temp;
            front->next = NULL;
            rear->next = NULL;
       }
       else
       {
           rear->next = temp;
           rear=temp;
           rear->next=NULL;
       }

   }
}

int dequeue()
{
    //isempty
    if(front==NULL)
    {
        printf("underflow");
    }
    else
    {
       struct node *temp = front;
       int data = temp->val;
       front=front->next;
       free(temp);
       return data;
    }
}

int peek()
{
    if(front==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        return front->val;
    }
}

void display()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("queue is empty");
    }
    else
    {
       while(temp!=NULL)
       {
           printf("%d ",temp->val);
           temp=temp->next;
       }
    }
}


int main()
{
 enqueue(1);
 enqueue(2);
 enqueue(3);
 display();
 printf("dequeued element :%d \n",dequeue());
 printf("dequeued element :%d \n",dequeue());


 enqueue(4);
 enqueue(5);
 enqueue(6);

 display();
 printf("peek element :%d \n",peek());
}
