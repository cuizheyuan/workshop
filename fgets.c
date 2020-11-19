#include <stdio.h>
int main(void)
{
    int length;
    char str[1024];
    char *string = str;  
    printf("?????????? ");
    fgets(string, 9, stdin);
    length = sizeof(str);
    printf("%d", length);


    printf("%s", string);

}