//为了弥补之前填错邮箱造成的损失
//我决定每天写一点实用的小代码块
//考试还要用烦人的dev c，此今天开始我用devc写程序 
//顺便也练练手方便考试使用

#include<stdio.h>
#define N 100

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
