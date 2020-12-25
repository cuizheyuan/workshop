#include<stdio.h>
#define N 1024

int func_length(char str[]);
int main()
{
	int length = 0;
	char str[N]={0};
	scanf("%s",str);
	length=func_length(str);
	printf("%d",length);
	return 0;
}
int func_length(char str[])
{
	int n=0;
	for(int i=0;i<1024;i++){
		if(str[i]!=0)
		n++;
		else
		break;
	}
	return n;
}
