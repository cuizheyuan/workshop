#include<stdio.h>

void sort(int array[], int length);
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    getchar();
    int a[1024]={0};
    int b[1024]={0};
    int c[2048]={0};
    int counter = 0;
    while(1){
        scanf("%d",&a[counter]);
        counter++;
        if(getchar()=='\n')
            break;
        }
        counter=0;
    while(1){
        scanf("%d",&b[counter]);
        counter++;
        if(getchar()=='\n')
            break;
    }
    for (int i = 0; i < n;i++){
        c[i] = a[i];
    }
    for (int i = 0; i < m;i++){
        c[i + n] = b[i];
    }
    sort(c,n+m);
    for (int i = 0; i < n + m;i++)
        printf("%d ", c[i]);
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