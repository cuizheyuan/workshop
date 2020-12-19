#include<stdio.h>
#include<stdbool.h>

int isHuiWenshu(char number[]);
int compare(char a[],char b[],int length_a,int length_b);
int main()
{
    int line = 0;
    int length = 0;
    int length_1[65536] = {0};
    int number = -1;
    static int i = 0;
    int q = 0;
    int counter_c = 1;
    int counter_p = 1;
    int flag_1 = 1;
    int MAX = 0;
    int temp = 0;
    char *temp_1;
    int counter[128] = {0};
    char host_char[128] = {0};
    char judge[128][1024] = {0};
    char *pointer[128];
    bool table[128];
    for (int i = 0; i < 128;i++)
        table[i] = true;
        //judge中一共有128行存储不同的数字串，每个数字串可以存储1024个数字字符
    for (int i = 0; i < 65536;i++){
    temp=getchar();
    if(temp==-1||temp==26){
        host_char[i] = 10;
        break;
    }
    else
        host_char[i] = temp;
    }
    for (int i = 0; i < 65536; i++){
      if(host_char[i]!=0)
         length++;
      else{
         i = 0;
         break;
      }
    }
    //printf("%d\n", length); 
    //接下来进行整个文本中数字串的判断
    for (int k = 0; k <= length;k++){
        switch (host_char[k]){
        case 48://0
        case 49://1
        case 50://2
        case 51://3
        case 52://4
        case 53://5
        case 54://6
        case 55://7
        case 56://8
        case 57://9
            judge[i][q] = host_char[k];
            flag_1 = 0;
            q++;
            break;
        default:
            if(flag_1==0||host_char[k]==0){
            number++;
            i++;
            q = 0;
            }
            flag_1 = 1;
            break;
        }
    }
    //指针指向所有相同字符串
    for (i = 0; i < number;i++)
        pointer[i] = judge[i];
    int flag = 0;
    for (i = 0; i < number;i++){
        for (int k = i+1; k < number;k++){
            if(table[k]==true){
                for (int n = 0; n < 1024;n++){
                    if(judge[i][n]!=judge[k][n]){
                        flag = 1;
                        break;
                    }
                    else continue;
                }
            if(flag==0){
                pointer[k] = judge[i];
                table[k] = false;
            }
            flag = 0;
        }
        }
    }
    for (i = 0; i < 128; i++){
        for (int k = 0; k < 1024;k++)
            if (judge[i][k] != '\000')
                length_1[i]++;
            else{
         break;
      }
    }

    //对所有相同字符串进行计数
    for (i = 0; i < number;i++){
        counter_c = 1;
        if(table[i]==false)
            continue;
        for (int k = i+1; k <= number;k++){
            if(pointer[i]==pointer[k]){
            counter_c++;
            }
        }
        counter[i] = counter_c * isHuiWenshu(pointer[i]);
        if( ! isHuiWenshu(pointer[i])){
            table[i] = false;
        }
    }

    //找出回文数最多的情况
    for (i = 0; i < number;i++){
        if(table[i]!=false){
        if(MAX==counter[i]&&MAX!=0){
            counter_p++;
        }
        if(MAX<counter[i]){
        MAX = counter[i];
        line = i;
        }
        }
    }
    if(MAX==0)
    printf("None");
    else if(counter_p==1){
        printf("%s ", pointer[line]);
        printf("%d\n", MAX);
    }
    else{
    //下面对于指针进行排序
    for (int i = 0; i < number;i++){
        if(counter[i]<MAX)
            table[i] = false;
    }
    for (int i = 0; i < number;i++){
        for (int k = i+1; k < number;k++){
            if(table[i]&&table[k]){
            if(compare(judge[i],judge[k],length_1[i],length_1[k])){
                 temp_1 = pointer[i];
                 pointer[i] = pointer[k];
                 pointer[k] = temp_1;
            }
            }
        }
    }
    //显示回文数

        for (int t = 0; t < number;t++){
            if(table[t]!=false){
            printf("%s ", pointer[t]);
            printf("%d\n", MAX);
            }
        }
    }
}





int isHuiWenshu(char number[])
{
    int i = 0;
    int m = 0;
    int flag = 1;
    m = 0;
    flag = 1;
    if(number[0]=='0')
        return 0;
    for (i = 0; i < 100; i++){
      if(number[i]!='\000')
         m++;
      else{
         i = 0;
         //m = m - 1;
         break;
      }
    }
    if(m<=1)
        return 0;
    for (i = 0; i < m / 2;i++){
        if(number[i] != number[m-i-1]){
            flag = 0;
            break;
        }
        else{
            continue;
        }
        
    }
return flag;
    //flag为1时就是回文数
    //flag为0时就不是回文数
}

int compare(char a[],char b[],int length_a,int length_b)
{
    int flag = 1;
    if(length_a>length_b)
        return true;
    else if(length_a<length_b)
        return false;
    else{
    for (int i = 0; i < 1024;i++)
    if(a[i]>=b[i]){
        break;
    }
    else{
        flag = 0;
        break;
    }
    }
    return flag;
    //flag为0时a比b大，为1时b比a大
}