#include<stdio.h>


int main()
{
    int *p;
    int n = 12;
    p = &n;
    //&为取地址符号，即取一个变量的地址
    //p变量本身存储的是地址数，使用*符号可以表示p所指向的地址的值
    printf("%d\n", &p);
    printf("%d\n", &n);
}