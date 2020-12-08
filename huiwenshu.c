#include<stdio.h>

int main()
{
    int i = 0;
    int m = 0;
    int n = 0;
    int flag = 0;
    char a[100]={0};
    scanf("%d", &n);
    for (int p = 0; p < n;p++)
    {
    m = 0;
    flag = 0;
    for (int r = 0; r < 100; r++)
    {
            a[r] = '0';
    }
    scanf("%s", a);
    for (i = 0; i < 100; i++)
    {
      if(a[i]!='\000')
         m++;
      else{
         i = 0;
         //m = m - 1;
         break;
      }
    }
    for (i = 0; i < m / 2;i++){
        if(a[i] != a[m-i-1]){
            flag = 1;
            break;
        }
        else{
            continue;
        }
        
    }
    if(flag==0)
        printf("Yes\n");
    else
        printf("No\n");
    }
}