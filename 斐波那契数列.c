#include<stdio.h>

int main(void)
{
    int a[2], i;    //这里的数组只需要三个位置，存放

    for (i = 0; i <= 49; i++)
    {
        a[0] = 1;
        a[1] = 1;
       a[i + 2] = a[i] + a[i + 1];
       printf("%d ", a[i]);
    }
}