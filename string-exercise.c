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
	printf("%d\n",length);
    strcp(str, length);
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

void strcp(char str[],int length)
{
    int length_1 = 0;
    int length_2 = 0;
    char str_cp[1024] = {0};
    strcpy(str_cp, str);
    printf("%s\n", str_cp);
    length_1 = strnlen(str, 200);
    length_2 = strlen(str);
    printf("%d\n", length_1);
    printf("%d\n", length_2);
}