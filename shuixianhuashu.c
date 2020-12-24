#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        int range_max = 0;
        int range_min = 0;
        int min = 0;
        int num[100] = {0};
        int sub = 0;
        int temp = 0;
        int flag = 0;
        scanf("%d %d", &range_min, &range_max);
        sub = range_max - range_min;

            for (int k = 0; k <= sub; k++)
            {
                min = range_min;
                int counter = 0;
                do
                {
                    num[counter] = min % 10;
                    counter++;
                    min = min / 10;
                } while (min != 0);
                for (int k = 0; k < counter; k++)
                {
                    temp += num[k] * num[k] * num[k];
                }
                if (range_min == temp)
                {
                    printf("%d ", range_min);
                    flag = 1;
                }
                range_min++;
                temp = 0;
            }
        if(flag==0)
            printf("-1\n");
        else
            printf("\n");
    }
}