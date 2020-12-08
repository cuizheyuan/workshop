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
int table[1001][51];
int table_swap[1001][51];
char command_list[10];

int main()
{
    scanf("%d %d", &r, &c);
    getchar();
    for (int i = 0; i < r-1;i++)//如何输入电子表格数据
    {
        for (int k = 0; k < c;k++)
            scanf("%d ", &table[i + 1][k + 1]);
    }
    int command = 0;
    scanf("%d", &command);
    for (int i = 0; i < command;i++)
    {
        for (int k = 0; k < 10;k++)
            command_list[k] = 0;
        scanf("%s", command_list);
        if(command_list[0]=='S' && command_list[1]=='R'){
            //此处执行交换行指令
        }
        else if(command_list[0]=='S' && command_list[1]=='C'){
            //此处执行交换列命令
        }
        else if(command_list[0]=='D' && command_list[1]=='R'){
            //此处执行删除行命令
        }
        else if(command_list[0]=='D' && command_list[1]=='C'){
            //此处执行删除列命令
        }
        else if(command_list[0]=='I' && command_list[1]=='R'){
            //此处执行插入行命令
        }
        else if(command_list[0]=='I' && command_list[1]=='C'){
            //此处执行插入列命令
        }
    }
        return 0;
}

void SR(void)
{
    for (int i = 0; i < r-1;i++)//如何输入电子表格数据
    {
        for (int k = 0; k < c;k++)
            table_swap[i + 1][k + 1] = table[i + 1][k + 1];
    }
}