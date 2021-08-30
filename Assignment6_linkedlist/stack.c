#include <stdio.h>
#include<stdlib.h>

struct node
{
  int val;
  struct node *next;
};

struct node *head;


void push(int x)
{
  struct node *p = (struct node*)malloc(sizeof(struct node));

  // is full condition
  if(p==NULL)
  {
      printf("stack overflow :(");
  }
  else
  {
     if(head==NULL)
     {
         p->val = x;
         p->next = NULL;
         head = p;
     }
     else
     {
         p->val = x;
         p->next = head;
         head = p;
     }
  }
}

int pop()
{
  int value=-1;

  struct node *p;

  // is empty condition
  if( head== NULL)
  {
      printf("stack undeflow");
  }
  else
  {
     value = head->val;
     p=head;
     head=head->next;
     free(p);
  }
  return value;
}

int peek()
{
    if(head==NULL)
    {
        printf("stack is empty");
    }
    return head->val;
}

void display()
{
    struct node *p;
    p = head;

    if(p==NULL)
    {
        printf("Empty");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d ",p->val);
            p=p->next;
        }
    }
}


int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pop();

printf(" peek element :%d \n",peek());
  display();

}
