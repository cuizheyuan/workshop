#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        int num = 0;
        int output[100]={0};
        int counter = 0;
        scanf("%d", &num);
        if(num==4){
            printf("2*2\n");
            continue;
        }
        for (int k = 2; k <= num;k++){
            if(num%k==0){
                output[counter] = k;
                counter++;
                num = num / k;
                k = 1;
            }
        }
        for (int k = 0; k < counter-1;k++){
            printf("%d*",output[k]);
        }
        printf("%d\n", output[counter-1]);
    }
}

