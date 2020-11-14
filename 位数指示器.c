#include<stdio.h>

int main(void)
{
    int x,y;
    printf("Enter the number ");
    scanf("%d", &x);
    int i;
    for (i = 1; x >= 10; i++)
    {
        y = x % 10;
        x = x - y;
        x = x / 10;
    }
    printf("\nThere are %d digit(s) in the number.", i);
    return 0;
}