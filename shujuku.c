#include<stdio.h>


int r = 0;
int c = 0;
int flag_r = 0;
int flag_c = 0;
int table[1001][51];      //操作的源表格
int table_swap[1001][51]; //操作之后生成的新表格
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
    for (int i = 0; i < r;i++)//通过遍历方式输入表格
    {
        for (int k = 0; k < c;k++)
            scanf("%d", &table[i + 1][k + 1]);
    }
    int command = 0;
    scanf("%d", &command);//读取指令数量
    getchar();            //吸收换行符
    for (int i = 0; i < command;i++)
    {
        for (int k = 0; k < 10;k++)
            command_list[k] = 0;
        fgets(command_list,10,stdin); //每次读取一条指令
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
    //以下为最后的输出结果部分
    for (int i = 0; i < r ;i++){
        for (int k = 0; k < c ;k++){
            printf("%d ", table[i+1][k+1]);
        }
        printf("\n");
    }
        return 0;
}

void SR(void)//交换行
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

void SC(void)//交换列
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

void DR(void)//删除行
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

void DC(void)//删除列
{
    int q = 0;
    q = command_list[3] - 48;
    c--;
    for (int i = 0; i < r;i++)
    {
        for (int k = 0; k < c;k++)
            if(k<q-1){
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

void IR(void)//插入行
{
    int p = 0;
    p = command_list[3] - 48;
    r++;
    for(int k=0;k<c+1;k++)
        table_swap[p][k] = 0;//提前先把插入的行写满0
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

void IC(void)//插入列
{
    int q = 0;
    q = command_list[3] - 48;
    c++;
    for(int i=0;i<r;i++)
        table_swap[i+1][q] = 0;//提前把插入的列写满0
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

