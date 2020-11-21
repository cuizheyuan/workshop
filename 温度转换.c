#include <stdio.h>
int main(){
    int n;
    double m[1024];
    double F;
    int i,j;
    printf("请输入您想转换的温度原数据个数：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("请输入您需要转换的第%d个F值:",(i+1));
        scanf("%lf",&F);
        m[i]=5*(F-32)/9;
    }
    for(j=0;j<n;j++){
        printf("T[%d]=%.5lf\n",j,m[j]);
    }
    return 0;
}