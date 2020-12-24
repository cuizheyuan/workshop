#include<stdio.h>

int main()
{
    int counter = 0;
    int temp_c = 0;
    do
    {
    temp_c = getchar();
        if(temp_c!='\n'){
            counter++;
        }
    } while (temp_c!='\n');
    printf("%d", counter);
}