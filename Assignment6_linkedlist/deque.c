
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;
};

struct node *front;
struct node *rear;

//add an element at head
void addFront(int data)
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
       }
       else
       {
           temp->next = front;
           front->prev = temp;
           front = temp;
       }
   }
}


//add an element at tail
void addRear(int data)
{
   struct node *temp = (struct node*)malloc(sizeof(struct node));  
 
   if(temp==NULL)
   {
       printf("Overflow");
       return;
   }
   else
   {
       temp->val=data;
       if(rear==NULL)
       {
            front = temp;  
            rear = temp;   
       }
       else
       {
           temp->prev = rear;
           rear->next = temp;
           rear=temp;
           rear->next=NULL;
       }
       
   }
}

//remove element from head
int deleteFront()
{
    if(front==NULL)
    {
        printf("underflow");
    }
     else
    {
       struct node *temp = front;
       int data = temp->val;
       front=front->next;
       if(front==NULL)
       {
           rear=NULL;
       }
       else
       {
       front->prev = NULL;
       }
       free(temp);
       return data;
    }
}

//remove element from tail
int deleteRear()
{
    
    if(front==NULL)
    {
        printf("underflow");
    }
     else
    {
       struct node *temp = rear;
       int data = temp->val;
       rear=rear->prev;
       
       if(rear==NULL)
       {
           front=NULL;
       }
       else
       {
       rear->next = NULL;
       }
       free(temp);
       return data;
    }
}

int peekFront()
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


int peekRear()
{
    if(rear==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        return rear->val;
    }
}

//check if given element is present in deque or not

int isContain(int data)
{
    if(front==NULL)
    {
        return -1;
    }
    struct node *temp=front;
    
    while(temp!=NULL)
    {
      if(temp->val == data)
      {
          return 1;
      }
      temp=temp->next;
    }
    return -1;
    
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
   addFront(2);
   addFront(3);
   addFront(4);
   addFront(5);
   addRear(10);      
   addRear(9);
   addRear(8);

   printf("peekFront %d \n",peekFront());
   printf("peekRear %d \n",peekRear());

   printf("del front %d \n",deleteFront());
   printf("del rear %d \n",deleteRear());
   
   printf("peekFront %d \n",peekFront());
   printf("peekRear %d \n",peekRear());

   printf("%d \n",isContain(7));
   
   display();
   
}
