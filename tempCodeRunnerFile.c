#include<stdio.h>
/*
有一个r行c列(1<=r,c<=50)的电子表格，行从上到下编号为1~r，列从左到右编号是1~c。上面定义了几种操作：(x, y等都是整数)
SR x1 x2
交换x1行和x2行
SC y1 y2
交换y1列和y2列
DR x
删除x行
DC y
删除y列
IR x
在x行上面插入一行，新插入的行的所有单元格值为0
IC y
在y列前面插入一列，新插入的列的所有单元格值为0
输入
第一行是2个整数r, c，表示电子表格有r行c列。接下来的r行，每行c个整数，表示每个单元格的值。再接下来的一行有1个整数n，
表示随后有n行，每行是一个操作命令。
输出
输出经过这n次操作后的电子表格内容。
*/

//以下为所需的全局变量，对多个函数共享
int r = 0;
int c = 0;
int flag_r = 0;
int flag_c = 0;
int table[1001][51];
int table_swap[1001][51];
char command_list[10];

void SR(void);
void SC(void);
void DR(void);
void DC(void);
void IR(void);
void IC(void);

int main()
{
    scanf("%d %d", &r, &c);
    getchar();
    for (int i = 0; i < r;i++)//如何输入电子表格数据
    {
        for (int k = 0; k < c;k++)
            scanf("%d", &table[i + 1][k + 1]);
    }
    int command = 0;
    scanf("%d", &command);
    getchar();
    for (int i = 0; i < command;i++)
    {
        for (int k = 0; k < 10;k++)
            command_list[k] = 0;
        fgets(command_list,10,stdin);
        if(command_list[0]=='S' && command_list[1]=='R'){
            SR();
        }
        else if(command_list[0]=='S' && command_list[1]=='C'){
            SC();
        }
        else if(command_list[0]=='D' && command_list[1]=='R'){
            DR();
        }
        else if(command_list[0]=='D' && command_list[1]=='C'){
            DC();
        }
        else if(command_list[0]=='I' && command_list[1]=='R'){
            IR();
        }
        else if(command_list[0]=='I' && command_list[1]=='C'){
            IC();
        }
    }
    for (int i = 0; i < r ;i++){
        for (int k = 0; k < c ;k++){
            printf("%d ", table[i+1][k+1]);
        }
        printf("\n");
    }
        return 0;
}

void SR(void)
{
    int p = 0;
    int q = 0;
    p = command_list[3] - 48;
    q = command_list[5] - 48;
    for (int i = 0; i < r ;i++){
        if((i+1) != p && (i+1) != q){
        for (int k = 0; k < c;k++)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
        }
        else if((i+1) ==p){
            for (int k = 0; k < c;k++){
                table_swap[p][k + 1] = table[q][k + 1];
            }
        }
        else
            for (int k = 0; k < c;k++)
            table_swap[q][k + 1] = table[p][k + 1];
    }
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

void SC(void)
{
    int p = 0;
    int q = 0;
    p = command_list[3] - 48;
    q = command_list[5] - 48;
    for (int i = 0; i < r ;i++){  
        for (int k = 0; k < c;k++){
            if((k+1) != p && (k+1) != q)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
            else if((k+1) ==p)
            table_swap[i + 1][p] = table[i + 1][q];
            else
            table_swap[i + 1][q] = table[i + 1][p];
        }
    }
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

void DR(void)
{
    int p = 0;
    p = command_list[3] - 48;
    r--;
    for(int k=0;k<c;k++)
        table_swap[p][k] = 0;
    for (int i = 0; i < r-1;i++)
    {
        if(i+1 < p){
        for (int k = 0; k < c;k++)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
        }
        else{
            for (int k = 0; k < c;k++)
            table_swap[i + 1][k + 1] = table[i + 2][k + 1];
        }
    }
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

void DC(void)
{
    int q = 0;
    q = command_list[3] - 48;
    c--;
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k+1 < c;k++)
            if(k<q){
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
            }
            else{
            table_swap[i + 1][k + 1] = table[i + 1][k + 2];
            }
    }
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

void IR(void)
{
    int p = 0;
    p = command_list[3] - 48;
    r++;
    for(int k=0;k<c;k++)
        table_swap[p][k] = 0;
    for (int i = 0; i < r;i++)
    {
        if(i+1 < p){
        for (int k = 0; k < c;k++)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
        }
        else{
        for (int k = 0; k < c;k++)
            table_swap[i + 2][k + 1] = table[i + 1][k + 1];
        }
    }
    for (int i = 0; i < r+1;i++)
    {
        for (int k = 0; k < c;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

void IC(void)
{
    int q = 0;
    q = command_list[3] - 48;
    c++;
    for(int i=0;i<r;i++)
        table_swap[i+1][q] = 0;
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c+1;k++)
            if(k+1<q)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
            else
            table_swap[i + 1][k + 2] = table[i + 1][k + 1];
    }
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c+1;k++)
            table[i + 1][k + 1] = table_swap[i + 1][k + 1];
    }
}

