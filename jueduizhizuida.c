#include<stdio.h>

int main()
{
    int n = 0;
    long current = 0;
    long biggest = 0;
    int flag = 0;
    scanf("%d ",&n);
    for (int i = 0; i < n;i++){
        scanf("%ld ",&current);
        if(current<0){
            current = current * -1;
            if(current>biggest){
                biggest = current;
                flag = -1;
            }
            }
        else if(current>biggest){
            biggest = current;
                flag = 1;
            }

    }
    printf("%ld", biggest * flag);
}