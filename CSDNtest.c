#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d",&n) && n!=0){
        int count=0;
        for(int i=2;i<n/2;i++){
            if(isPrime(i)&&isPrime(n-i)){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}