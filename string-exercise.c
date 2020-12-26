#include<stdio.h>
#include<string.h>
#define N 1024

void strcp(char str[], int length);
int func_length(char str[]);
int main()
{
	int length = 0;
	char str[128][N]={0};
    int counter = 0;
    while(1){
        char temp = 0;
        scanf("%s", str[counter]);
        temp = getchar();
        counter++;
        if(temp==-1||temp==10)
            break;
    }
    for (int i = 0; i < counter;i++)
    {
        length = func_length(str[i]);
        printf("%d\n", length);
        strcp(str[i], length);
    }
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
    //一般时候用strlen就好。strnlen比strlen多一个参数，
    //就是数据总体长度，当检测到字符串长度比数据总体长度还长
    //（就是给定数据长度范围内没有结束符'\0'）时就会终止扫描。
    //strnlen这个函数一般用于检测不可信的数据（如网络数据），因为这种数据中可能没有'\0'，
    //这时如果用strlen的话会一直扫描无法停止（直到越界触碰到无效内存），
    //而strnlen限制住了扫描范围所以不会出事。
    int length_1 = 0;
    int length_2 = 0;
    int length_3 = 0;
    char str_cp[1024] = {0};
    strcpy(str_cp, str);
    printf("%s\n", str_cp);
    length_1 = strnlen(str, 200);
    length_2 = strlen(str);
    printf("%d\n", length_1);
    printf("%d\n", length_2);
    //length_3 = sizeof(str[0]);
    //printf("%d\n", length_3);
    //sizeof函数不适用于字符串元素的判断
}