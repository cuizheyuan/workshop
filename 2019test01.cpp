#include<stdio.h>

int main()
{
	int num[22]={0};
	
for(int i=0;i<10;i++){
	scanf("%d",&num[i]);	
}
for(int i=1;i<10;i++){
		if(num[i]!=0){
			num[i]-=1;
			printf("%d",i);
			break;
		}
	}
	for(int i=0;i<10;i++){
		if(num[i]!=0){
			num[i]=num[i]-1;
			printf("%d",i);
			i=0;
		}
	}
}
