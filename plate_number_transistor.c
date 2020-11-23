#include<stdio.h>

int main()
{
    while(1)
    {
        int i = 0;
        char plate[1024] = {0};
        printf("Please enter plate number");
        scanf("%s", plate);
        /*
        for (int i = 0; i <= 20;i++)
        {
            printf("%x", plate[i]);
            printf("\n");
        }
        */
        long character;

        for (i = 0; i >= 0;)
        {
            if(plate[i]!=0)
            {
                if(plate[i]>=0xffffff00)
                {
                    character = (plate[i]-0xffffff00) * 0x100 + (plate[i+1]-0xffffff00);
                    switch(character)   
                    {
                        case 48809:printf("E4BAAC");break;//京
                        case 48626:printf("E6B4A5");break;//津
                        case 48038:printf("E6B2AA");break;//沪
                        case 54245:printf("E6B89D");break;//渝
                        case 48317:printf("E58680");break;//冀
                        case 54437:printf("E8B1AB");break;//豫
                        case 54470:printf("E4BA91");break;//云
                        case 49609:printf("E8BEBD");break;//辽
                        case 47834:printf("E9BB91");break;//黑
                        case 53222:printf("E6B998");break;//湘
                        case 52718:printf("E79A96");break;//皖
                        case 49843:printf("E9B281");break;//鲁
                        case 53442:printf("E696B0");break;//新
                        case 52181:printf("E88B8F");break;//苏
                        case 54755:printf("E6B599");break;//浙
                        case 47315:printf("E8B5A3");break;//赣
                        case 46837:printf("E98482");break;//鄂
                        case 47600:printf("E6A182");break;//桂
                        case 47306:printf("E79498");break;//甘
                        case 48634:printf("E6998B");break;//晋
                        case 50121:printf("E89299");break;//蒙
                        case 51650:printf("E99995");break;//陕
                        case 48298:printf("E59089");break;//吉
                        case 50166:printf("E997BD");break;//闽
                        case 47603:printf("E8B4B5");break;//贵
                        case 54465:printf("E7B2A4");break;//粤
                        case 51168:printf("E99D92");break;//青
                        case 45784:printf("E8978F");break;//藏
                        case 46248:printf("E5B79D");break;//川
                        case 50430:printf("E5AE81");break;//宁
                        case 51181:printf("E790BC");break;//琼
                        case 48815:printf("E8ADA6");break;//警
                        case 54182:printf("E5BA94");break;//应
                        case 48305:printf("E680A5");break;//急
                        case 47610:printf("E59BBD");break;//国
                        case 51897:printf("E4BDBF");break;//使
                        case 47570:printf("E68C82");break;//挂
                        case 49644:printf("E9A286");break;//领
                        case 47323:printf("E6B8AF");break;//港
                        case 45252:printf("E6BEB3");break;//澳
                        case 53671:printf("E5ADA6");break;//学
                        case 51924:printf("E8AF95");break;//试
                        case 45996:printf("E8B685");break;//超
                        case 49625:printf("E4B8B4");break;//临
                        case 50161:printf("E6B091");break;//民
                        case 47805:printf("E888AA");break;//航
                        case 41380:printf("C2B7");break;//·
                        default:
                            printf("Error");
                            return 1;
                    }
                    i = i + 2;//汉字占用两个数组位，直接跳过下一个数组
                }

                else
                {
                    printf("%c", plate[i]);
                    i++;
                }
            }
            else
            {
                printf("\n");
                break;
            }
            
        }
    }
}
