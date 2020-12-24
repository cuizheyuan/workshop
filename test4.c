#include <stdio.h>
  


int main()
{
    int n=0;
    int score =0;
    int score_hight = 0;
    int score_low = 101;
    char name [30]={0};
    char name_low [30]={0};
    char name_hight [30]={0};
    char id [30]={0};
    char id_low [30]={0};
    char id_hight [30]={0};
    char trash[30] = {0};
    int error_code = 0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        
        error_code = scanf("%s %s %d",name,id,&score);
        if (error_code == 2){
            scanf("%s", trash);
            continue;
            }
        else if(name_hight[0]==0 && name_low[0]==0){
            sprintf(name_low,"%s",name);
            sprintf(id_low,"%s",id);
            sprintf(name_hight,"%s",name);
            sprintf(id_hight,"%s",id);
        }
        else if(score > score_hight)
        {    score_hight = score ;
            sprintf(name_hight,"%s",name);
            sprintf(id_hight,"%s",id);
        }
        else if(score == score_hight)
        {
            for (int k = 0; k < 29; k++)
            {
                if (name[k] < name_hight[k]){
                sprintf(name_hight,"%s",name);
                sprintf(id_hight,"%s",id);
                break;
                }
                else if(name[k] >= name_hight[k])
                    continue;
            }
        }
        else if(score < score_low )
        {
            score_low = score;
            sprintf(name_low,"%s",name);
            sprintf(id_low,"%s",id);
        }
        else if(score == score_low)
        {
            for (int k = 0; k < 29; k++)
            {
                if (name[k] > name_hight[k]){
                sprintf(name_low,"%s",name);
                sprintf(id_low,"%s",id);
                break;
                }
                else if(name[k] <= name_low[k])
                    continue;
            }
        }
    }

    printf("%s %s \n",name_hight,id_hight);
    printf("%s %s \n",name_low,id_low);

    return 0;

}