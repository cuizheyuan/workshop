#include<stdio.h>

//旨在测试考试中出现的奇奇怪怪的写法

int main()
{
    int m = 1;
    m += m * 3;
    printf("%d\n", m);

    int x[2][3] = {{1,2},{3,4},{5,6}};
    printf("%d\n", m);

    char a[10];
    char b[7][8];
    char *p1 = a + 3;
    char *p2 = &b[2][4];
    printf("%lld\n", p2-b[2]);
    printf("%d\n", p2[9]-b[3][5]);
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
    printf("%d\n", z1);

    char arr[3][4] = {{"abcd"}, {"1234"},{"bomb"}};
    printf("%s\n", *arr+2);
    printf("%s\n", arr[1] + 2);

}