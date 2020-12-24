#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++) {
        int a, b, c, d;
        int temp = 0;
        scanf("%d %d %d %d", &a,&b,&c,&d);
        sort:
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        if(b>c){
            temp = b;
            b = c;
            c = temp;
        }
        if(c>d){
            temp = c;
            c = d;
            d = temp;
        }
        if(a<=b&&b<=c&&c<=d)
            goto output;
        else
            goto sort;
        // 读入4个整数，对这4个整数排序，并输出结果

        output:
            printf("%d %d %d %d\n", a, b, c, d);
        // 请将排序代码写在这里，不能使用循环语句
    }
    return 0;

}