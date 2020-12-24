#include<stdio.h>

int main()
{
    long int a, b, c;
    int n = 0;
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        flag = 0;
        scanf("%ld %ld %ld", &a, &b, &c);
        if(a>0&&b>0&&c>0){
        if(a*a==b*b+c*c){
            flag = 1;
        }
        else if(b*b==a*a+c*c){
            flag = 1;
        }
        else if(c*c==b*b+a*a){
            flag = 1;
        }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}