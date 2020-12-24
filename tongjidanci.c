#include<stdio.h>
#include<stdbool.h>

int compare(char a[],char b[],int length_a,int length_b);
int main()
{
    int line = 0;
    int length = 0;
    int length_1[128] = {0};
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
    char host_char[1024] = {0};
    char judge[128][1024] = {0};
    char *pointer[128];
    bool table[128];
    for (int i = 0; i < 128;i++)
        table[i] = true;
        //judge中一共有128行存储不同的数字串，每个数字串可以存储1024个数字字符
    for (int i = 0; i < 1024;i++){
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
    //接下来进行整个文本中单词的判断
    for (int i = 0; i < 1024;i++){
        if(host_char[i]>=65&&host_char[i]<=90){
            host_char[i] = host_char[i] + 32;
        }
    }

    for (int k = 0; k <= length;k++){
        if(host_char[k]>=97&&host_char[k]<=122){
            judge[i][q] = host_char[k];
            flag_1 = 0;
            q++;
        }
        else{
            if(flag_1==0||host_char[k]==0){
            number++;
            i++;
            q = 0;
            }
            flag_1 = 1;
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
        counter[i] = counter_c;
    }

    for (int i = 0; i < 128;i++){
        if(length_1[i]<=1)
            table[i] = false;
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

        for (int t = number; t >= 0 ;t--){
            if(pointer[t]!=0){
            printf("%s ", pointer[t]);
            printf("%d\n", MAX);
            break;
            }
        }
    }
}



int compare(char a[],char b[],int length_a,int length_b)
{
    int flag = 1;
    for (int i = 0; i < 1024;i++){
    if(a[i]>b[i]){
        break;
    }
    if(a[i]==b[i]){
        continue;
    }
    else{
        flag = 0;
        break;
    }
    }
    return flag;
    //flag为0时a比b大，为1时b比a大
}