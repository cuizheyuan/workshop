#include<stdio.h>
#include<string.h>
#define N 1024

void strcp(char str[], int length);
int func_length(char str[]);
int main()
{
	int length = 0;
	char str[N]={0};
	scanf("%s",str);
	length=func_length(str);
	printf("%d",length);
	return 0;
    strcp(str, length);
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

void strcp(char str[],int length)
{
    char str_cp[1024] = {0};
    strcpy(str_cp, str);
    printf("%s", str_cp);
}