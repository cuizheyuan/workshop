#include<stdio.h>

//旨在测试考试中出现的奇奇怪怪的写法

int main()
{
    int m = 1;
    m += m * 3;
    printf("%d", m);

    int x[2][3] = {{1,2},{3,4},{5,6}};
    printf("%d", m);

    char a[10];
    char b[7][8];
    char *p1 = a + 3;
    char *p2 = &b[2][4];
    printf("%lld", p2-b[2]);
    printf("%d", p2[9]-b[3][5]);
    struct STRU
    {
        int a, b;
        char c;
        struct STRU *p1;
    };
    struct STRU fuu[10];

    int x1 = 1;
    int y1 = 2;
    int z1 = 3;
    printf("%d", z1);

    char arr[3][4] = {{"abcd"}, {"1234"},{"bomb"}};
    printf("%s", *arr+2);
}