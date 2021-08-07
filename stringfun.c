#include <stdio.h>

void copy(char *s1, char *s21, char *d, int n)
{
   int j = 0, i = 0;
   int k = n;
   while (s21[j] != '\0' && n > 0)
   {
      d[i++] = s21[j++];
      n--;
   }

   while (s1[k] != '\0')
   {
      d[i++] = s1[k++];
   }
}

void concat(char *s1, char *s2, char *d, int n)
{
   int i = 0, j = 0, k = 0;
   while (s1[i] != '\0')
   {
      d[j++] = s1[i++];
   }
   while (n > 0)
   {
      d[j++] = s2[k++];
      n--;
   }
   d[j] = '\0';
}

int compare(char *s1, char *s2, int n)
{
   int i = 0, j = 0;
   while (s2[j] != '\0' || s1[i] != '\0' && n-- > 0)
   {
      if (s1[i] == s2[j])
      {
         i++;
         j++;
      }
      else
      {
         return s1[i] > s2[j] ? 1 : -1;
      }
   }
   return 0;
}

int main()
{
   char s1[10];
   char s2[10];
   char d[20];

   int temp, n;

   scanf("%s", s1);

   scanf("%s", s2);

   printf("size of characters of their argument :");
   scanf("%d", &n);

   printf("Enter:\n");
   printf("1 to copy \n2 to concat \n3 to compare\n");
   scanf("%d", &temp);

   switch (temp)
   {
   case 1:
      copy(s1, s2, d, n);
      printf("Result :%s\n", d);
      break;
   case 2:
      concat(s1, s2, d, n);
      printf("Result :%s\n", d);
      break;
   case 3:
      printf("Result :%d\n", compare(s1, s2, n));
      break;
   default:
      printf("Invalid\n");
      break;
   }
}
