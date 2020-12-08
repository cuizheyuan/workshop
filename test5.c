#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n = 0;
    int score_high = 0;
    char search[100];
    scanf("%d %s",&n,search);
    char name[n][100];
    char ID[n][30];
    int score[n][30];
    int rank[n][2];
    bool flag[n];
    for (int i = 0; i < n;i++)
    {
        scanf("%s %s %d", name[i], ID[i], score[i]);
    }
    //下面进行排名
    for (int i = 0; i < n;i++)
    {
        if (*score[i] <= score_high)
            score_high = *score[i];
            
    }
    if (search[0] == 48 || search[0] == 49 || search[0] == 50 || search[0] == 51 || search[0] == 52 || search[0] == 53 || search[0] == 54 || search[0] == 55 || search[0] == 56 || search[0] == 57)
        {
            //如果输入的为身份证
        }
}