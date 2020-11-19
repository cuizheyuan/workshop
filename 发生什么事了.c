#include<stdio.h>

int main()
{
    char plate[9];
    scanf("%s", plate);
    for (int i = 0; i <= 8;i++)
        printf("%2x ", plate[i]);
    
    long province; 
    long type;
    province = (plate[0]-0xffffff00) * 0x100 + (plate[1]-0xffffff00);

    switch(province)   
    {
        case 48809:
            printf("京");
            break;
        case 50403: 
            printf("沪");
            break;
        default:
            printf("省份3");
    }


    for (int j = 1; j <= 6;j++)
        {
            printf("%c", plate[j]);
        }
        if (plate[8] != 0)
        {
            type = (plate[0] - 0xffffff00) * 0x100 + (plate[1] - 0xffffff00);
            switch (type)
            {
            default:
                printf("Nmsl");

            }
        }
        else
        {
            printf("%c",plate[7]);
        }
}