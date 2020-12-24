#include<stdio.h>

int main()
{
    int temp = 0;
    int n = 0;
    int height=0;
    char paint_character;
    int end_point=0;
    int hightest = 0;
    int lowest = 31;
    scanf("%d", &temp);
    n = temp * 2 - 1;
    char chart[31][n];
    //对表格进行初始化
    for (int i = 0; i < 31;i++){
        for (int k = 0; k < n;k++)
            chart[i][k] = ' ';
    }
    //先画出中间的分割线
    for (int i = 0; i < n; i++){
        chart[15][i] = '-';
    }
    for (int i = 1; i < temp+1;i++){
        scanf("%d", &height);
        if(height>15||height<-15){
            paint_character = height % 10+'0';
            height = height / 10;
            getchar();
        }
        //拿到绘画字符，如果没有就填充为+
        else{
        paint_character = getchar();
        if(paint_character!=' '&&paint_character!='\n'){
            if(i!=n-1)
            getchar();
        }
        else{
            paint_character = '+';
        }
        }
        end_point = 15 + height;
        if(end_point>hightest)
            hightest = end_point;
        if(end_point<lowest)
            lowest = end_point;
        if(end_point<15){
            for (; end_point < 15;end_point++){
                chart[end_point][2*i-2] = paint_character;
            }
        }
        else{
            for (; end_point > 15;end_point--){
                chart[end_point][2*i-2] = paint_character;
            }
        }
    }
if(hightest<15)
    hightest = 15;
if(lowest>15)
    lowest = 15;
for (int i = hightest; i !=lowest-1;i--){
    for (int k = 0; k < n ;k++){
        printf("%c", chart[i][k]);
        }
        printf("\n");
    }
}