#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define SIZE 15 /* Size of Queue */
#define length 20
int f = 0, r = -1; /* Global declarations */

int left[SIZE];

typedef struct PRQ
{
   char ele[length];
   int pr;
} PriorityQ;

PriorityQ PQ[SIZE];

PQinsert(char elem[length], int pre)
{
   int i; /* Function for Insert operation */
   if (Qfull())
      printf("\n\n\t\t\t Overflow!!!!nn");
   else
   {
      i = r;
      ++r;
      while (PQ[i].pr >= pre && i >= 0) /* Find location for new elem */
      {
         PQ[i + 1] = PQ[i];
         i--;
      }
      strcpy(PQ[i + 1].ele, elem);
      PQ[i + 1].pr = pre;
   }
}

PriorityQ PQdelete()
{ /* Function for Delete operation */
   PriorityQ p;
   if (Qempty())
   {
      printf("\n\n\t\t\tUnderflow!!!!\n\n");
      p.pr = -1;
      return (p);
   }
   else
   {
      p = PQ[f];
      f = f + 1;
      return (p);
   }
}
void deleteSpecific(int i)
{
   for (int k = i; k > f; k--)
   {
      PQ[k] = PQ[k - 1];
   }
   f = f + 1;
}
void Modify()
{

   PriorityQ p;
   if (Qempty())
   {
      printf("\n\n\t\t\tUnderflow!!!!\n\n");
      return;
   }
   printf("\n\n\t\t\tBelow are all your tasks\n");
   display();
   printf("\n\t\t\tEnter option to modify\n\n");

   int d;
   printf("\t\t\t");
   scanf("%d", &d);

   if (f + d - 1 <= r)
   {
      int i = f + d - 1;
      printf("\n\n\t\t\tEdit the task\n\n");
      char e;

      printf("\t\t\t");
      scanf("%c", &e);

      fgets(p.ele, sizeof(p.ele), stdin);
      printf("\n\n\t\t\tChoose priority from given numbers\n\n");
      int flag = 0;
      left[PQ[i].pr] = 0;
      while (1)
      {

         printf("\t\t\t");
         for (int i = 1; i <= SIZE; i++)
         {
            if (left[i] == 0)
               printf("%d ", i);
         }
         printf("\n\n\t\t\t");

         scanf("%d", &p.pr);
         for (int i = 1; i <= SIZE; i++)
         {
            if (left[i] == 0)
            {
               if (i == p.pr)
               {
                  flag = 1;
                  break;
               }
            }
         }

         if (flag == 1)
         {
            break;
         }
         else
         {
            printf("\n\n\t\t\tINVALID PRIORITY\n\n\t\t\tTRY AGAIN\n\n");
         }
      }
      deleteSpecific(i);
      PQinsert(p.ele, p.pr);
      left[p.pr] = 1;
      return;
   }

   printf("\n\n\t\t\tINVALID\n\n");
}

int Qfull()
{ /* Function to Check Queue Full */
   if (r == SIZE - 1)
      return 1;
   return 0;
}

int Qempty()
{ /* Function to Check Queue Empty */
   if (f > r)
      return 1;
   return 0;
}

display()
{ /* Function to display status of Queue */
   int i;
   if (Qempty())
      printf("\t\t\tNo task");
   else
   {
      int count = 1;
      for (i = f; i <= r; i++)
         printf("\t\t\t%d-> %s \n", count++, PQ[i].ele, PQ[i].pr);
   }
}

void menu()
{

   int opn;
   PriorityQ p;
   do
   {

      system("cls");
      printf("\n\n\n\n\n\n\n\n\t\t\t ### ORGANISED DIARY Operations ### \n\n");
      printf("\n\n\t\t\t  Press 1-Insert\n\t\t\t\t2-Delete\n\t\t\t\t3-Display\n\t\t\t\t4-Modify\n\t\t\t\t5-Exit\n");
      printf("\n\n\t\t\t\t Your option ? ");
      scanf("%d", &opn);
      switch (opn)
      {
      case 1:
         printf("\n\n\t\t\tRead the Task\n\n");
         char d;
         printf("\t\t\t");
         scanf("%c", &d);
         fgets(p.ele, sizeof(p.ele), stdin);
         printf("\n\n\t\t\tChoose priority from given numbers\n\n");
         int flag = 0;
         while (1)
         {
            printf("\t\t\t");
            for (int i = 1; i <= SIZE; i++)
            {
               if (left[i] == 0)
                  printf("%d ", i);
            }
            printf("\n\n");
            printf("\t\t\t");
            scanf("%d", &p.pr);
            for (int i = 1; i <= SIZE; i++)
            {
               if (left[i] == 0)
               {
                  if (i == p.pr)
                  {
                     flag = 1;
                     break;
                  }
               }
            }

            if (flag == 1)
            {
               break;
            }
            else
            {
               printf("\n\n\t\t\tINVALID PRIORITY\n\n\t\t\tTRY AGAIN\n\n");
            }
         }
         PQinsert(p.ele, p.pr);
         left[p.pr] = 1;
         break;
      case 2:
         p = PQdelete();
         if (p.pr != -1)
         {
            printf("\n\n\t\t\t Completed task - > %s \n", p.ele);
            if (Qempty())
               printf("\n\n\t\t\tNO TASK LEFT");
            else
               printf("\n\n\t\t\t Upcoming task - > %s", PQ[f].ele);
            left[p.pr] = 0;
         }
         break;
      case 3:
         printf("\n\n\t\t\tTO DO's\n\n");
         display();
         break;
      case 4:
         Modify();
         break;
      case 5:
         printf("\n\n\t\t\t Terminating \n\n");
         break;
      default:
         printf("\n\n\t\tInvalid Option !!! Try Again !! \n\n");
         break;
      }
      printf("\n\n\t\t  Press a Key to Continue . . . ");
      getch();
   } while (opn != 5);
}

int main()
{
   /* Main Program */
   for (int i = 0; i < SIZE; i++)
      left[i] = 0;

   printf("\n\n\n\n\n\n\n\t\t\t\t<--:Organised Diary:-->");
   printf("\n\n\n\t\t\t\tPress any key to continue.");
   getch();
   menu();
   return 0;
}
