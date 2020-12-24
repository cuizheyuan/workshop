#include<stdio.h>

int loop(int sub,int round);
int main()
{
    int n, a, k ,result= 0;
    scanf("%d %d %d", &n, &a, &k);
    if (0 < n && n < 100 && 0 < a && a < 100 && 0 < k && k < 100 && n >= 2)
    {
    result = loop(k,n) + a;
    printf("%d", result);
    }
    else
    printf("Wrong Number");
    
}

int loop(int sub,int round)
{
    if(round==2)
    {
        return sub;
    }
    else
    {
        return sub + loop(sub,round - 1);
    }
}