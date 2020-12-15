#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n);
int main()
{
    long n = 0;
    long x, y;
    scanf("%ld", &n);
    if(n%2==0&&n>=6){
        for (int i = 1; i <= n / 2;i++)
        {
            x = i * 2 + 1;
            y = n - x;
            if(isPrime(x)&&isPrime(y)){
                if(x<=n/2)
                printf("%ld %ld\n", x, y);
            }
        }
    }

    else{
        printf("ERROR");
    }
}

bool isPrime(int n)
{
for(int i=2;i*i<=n;i++){
    if(n%i==0)return false;
}
return true;
}