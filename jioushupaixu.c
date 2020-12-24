#include<stdio.h>

void sort(int array[], int);
int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n;i++){
        int counter_odd = 0;
        int counter_even = 0;
        int judge = 0;
        int odd[100] = {0};
        int even[100] = {0};
        /*
        do
        {
            temp_c = getchar();
            if(temp_c!=' '&&temp_c!='\n'){
                if(temp_c%2!=0){
                    odd[counter_odd] = temp_c-48;
                    counter_odd++;
                }
                else{
                    even[counter_even] = temp_c-48;
                    counter_even++;
                }
            }
        } while (temp_c!='\n');
        */
        while(1){
            scanf("%d",&judge);
            if(judge%2!=0){
                odd[counter_odd] = judge;
                counter_odd++;
            }
            else{
                even[counter_even] = judge;
                counter_even++;
            }
            if(getchar()=='\n')
                break;
        }

        sort(odd, counter_odd);
        sort(even, counter_even);
        for (int r = 0; r < counter_odd;r++){
            printf("%d ", odd[r]);
        }
        if(counter_even>0){
        int l=0;
        for (; l < counter_even-1;l++){
            printf("%d ", even[l]);
            }
            printf("%d\n", even[l]);
        }
        else
            printf("\n");
    }
}

void sort(int array[], int length)
{
    int temp = 0;
    for (int i = 0; i < length;i++){
        for (int k = i + 1; k < length;k++){
            if(array[i]>array[k]){
                temp = array[i];
                array[i] = array[k];
                array[k] = temp;
            }
        }
    }
}