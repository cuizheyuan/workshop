#include<stdio.h>

int main(void)
{
    char a[] = "字";
    char b[3] = {0x61fe0c};
    printf("%s\n",a);
    printf("%s\n",b);
    printf("%lx\n",a);
    printf("%lx",b);
}