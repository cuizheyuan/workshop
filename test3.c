#include<stdio.h>

char detecter(void);

int main()
{
    int n,flag,c = 0;
    scanf("%d", &n);
    char ch[1024]={0};
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch);
        for (int k = 0; k < 1024;k++)
        {
            if(ch[k]==0)
                break;
            {
            if(ch[k]!=65 && ch[k]!=83)
            {
                flag = 0;
                break;
            }
            else 
            {
                c = c + 1;
                if (ch[k] != 83)
            {
                flag = 0;
            }
            else if(ch[k+1]!=67)
            {
                flag = 0;
            }
            else if(ch[k+2]!=85)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                k = k + 3 + c;
            }
            }
            }
        }
    if(flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    }
    return 0;
}

