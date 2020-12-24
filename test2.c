#include<stdio.h>

int main()
{
    double sub, quotient = 0;
    double temp[100][10];
    int k = 0;
    for (; k >= 0;k++){
    scanf("%lf %lf %lf %lf %lf", &temp[k][0], &temp[k][1], &temp[k][2], &temp[k][3], &temp[k][4]);
    if (temp[k][0] == 0 && temp[k][1] == 0 && temp[k][2] == 0 && temp[k][3] == 0 && temp[k][4] == 0)
        break;
    }
    int i = 0;
    for (; i <= k;i++){
    if (temp[i][0] == 0 && temp[i][1] == 0 && temp[i][2] == 0 && temp[i][3] == 0 && temp[i][4] == 0)
            break;
    else if (temp[i][0] == temp[i][1] && temp[i][1] == temp[i][2] && temp[i][2] == temp[i][3] && temp[i][3] == temp[i][4])
    {
        printf("case one\n");
        printf("%.0lf %.0lf %.0lf %.0lf %.0lf\n", temp[i][0], temp[i][1], temp[i][2], temp[i][3], temp[i][4]);
        printf("case two\n");
        printf("%.0lf %.0lf %.0lf %.0lf %.0lf\n", temp[i][0], temp[i][1], temp[i][2], temp[i][3], temp[i][4]);
        }
        else
        {
            if (((temp[i][0] - temp[i][1]) == (temp[i][1] - temp[i][2])) && ((temp[i][0] - temp[i][1]) == (temp[i][2] - temp[i][3])) && ((temp[i][2] - temp[i][3]) == (temp[i][3] - temp[i][4])))
            {
                sub = temp[i][1] - temp[i][0];
                printf("case one\n");
                printf("%.0lf %.0lf %.0lf %.0lf %.0lf\n", temp[i][4] + sub, temp[i][4] + 2 * sub, temp[i][4] + 3 * sub, temp[i][4] + 4 * sub, temp[i][4] + 5 * sub);
            }
            else if (temp[i][0] != 0 && temp[i][1] != 0 && temp[i][2] != 0 && temp[i][3] != 0 && temp[i][4] != 0)
            {
                if ((double)temp[i][1] / temp[i][0] == (double)temp[i][2] / temp[i][1] && (double)temp[i][1] / temp[i][0] == (double)temp[i][3] / temp[i][2] && (double)temp[i][1] / temp[i][0] == (double)temp[i][4] / temp[i][3])
                {
                    quotient = (temp[i][1] / temp[i][0]);
                    printf("case two\n");
                    printf("%.0lf %.0lf %.0lf %.0lf %.0lf\n", quotient * temp[i][4], quotient * quotient * temp[i][4], quotient * quotient * quotient * temp[i][4], quotient * quotient * quotient * quotient * temp[i][4], quotient * quotient *quotient * quotient * quotient * temp[i][4]);
                }
                else if(temp[i][4]==temp[i][3]+temp[i][2]&&temp[i][3]==temp[i][2]+temp[i][1]&&temp[i][2]==temp[i][1]+temp[i][0])
                {
                    printf("case three\n");
                    for (int r = 3; r <= 7;r++)
                    {
                        temp[i][r + 2] = temp[i][r] + temp[i][r + 1];
                        printf("%.0lf ", temp[i][r + 2]);
                    }
                    printf("\n");
                }
            }
        }
    }  
}
