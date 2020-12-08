#include <stdio.h>
 
 
int main( )
{
   int n = 0;
   int i = 0;
   int m = 0;
   scanf("%d", &n);
   char str[100]={0};
   char str_c[100]={0};
   getchar();
   fgets(str,100,stdin);
   for (i = 0; i < 100; i++)
   {
      if(str[i]!='\n')
         m++;
      else{
         i = 0;
         break;
      }
   }

   for (i = 0; i < m ;i++)
      {
         if((i+n)<m)
            str_c[i + n] = str[i];
         else
            str_c[i + n - m] = str[i];
      }
      for (i = 0; i <m ;i++)
         printf("%c", str_c[i]);
      return 0;
}