#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int isHuiWenshu(char number[]);
int compare(char a[],char b[]);
int main()
{
    int line = 0;
    int length[128] = {0};
    int length_1[128] = {0};
    int number = 0;
    int i = 0;
    int q = 0;
    int counter_c = 1;
    int counter_p = 0;
    int flag_1 = 1;
    int MAX = 0;
    int temp = 0;
    int temp_1 = 1;
    int counter[128] = {0};
    //char host_char[128]={0};
    char host_char_1[128][128];
    char judge[128][1024] = {0};
    char *pointer[128];
    bool table[128];
    for(int i=0;i<128;i++){
        for (int k = 0; k < 1024;k++)
            host_char_1[i][k] = 0;
    }
    for (int i = 0; i < 128;i++)
        table[i] = true;
        //judge中一共有128行存储不同的数字串，每个数字串可以存储1024个数字字符
/*
    while(1){
        temp = getchar();
        if(temp==-1)
            goto L;
        else
            ungetc(temp, stdin);
        fgets(host_char_1[temp_1], 128, stdin);
        temp_1++;
    }
*/

    for(int i=0;i<128;i++){
        for (int k = 0; k < 128;k++){
        temp=getchar();
        if(temp==-1||temp==26)
            goto L;
        else if(temp==10){
            host_char_1[i][k] = 10;
            break;
        }
        else
            host_char_1[i][k] = temp;
        }
    }

L:
for(int i=0;i<100;i++){
    for (int k = 0; k < 100; k++){
      if(host_char_1[i][k]!='\000')
         length[i]++;
      else{
          break;
      }
    }
}
    //printf("%d\n", length); 
    //接下来进行整个文本中数字串的判断
for (int r = 0; r < 128;r++){
    for (int k = 0; k <= length[r];k++){
        switch (host_char_1[r][k]){
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
            judge[i][q] = host_char_1[r][k];
            flag_1 = 0;
            q++;
            break;
        case 0:
            break;
        default:
            if(flag_1==0||host_char_1[r][k]==0){
            number++;
            i++;
            q = 0;
            }
            flag_1 = 1;
            break;
        }
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
    //对所有相同字符串进行计数
    for (i = 0; i < number;i++){
        if(table[i]==false)
        break;
        counter_c = 1;
        for (int k = i+1; k < number;k++){
            if(pointer[i]==pointer[k]){
            counter_c++;
            }
        }
        counter[i] = counter_c * isHuiWenshu(pointer[i]);
    }
    for (i = 0; i < 128; i++){
        for (int k = 0; k < 1024;k++)
            if (judge[i][k] != '\000')
                length_1[i]++;
            else{
         break;
      }
    }
    counter_p = 1;
    //找出回文数最多的情况
    for (i = 0; i < number;i++){
        if(table[i]!=false){
        //接下来判断哪个大，如果前者大就交换指针
        
        if(MAX==counter[i]&&MAX!=0){
            counter_p++;
            if(length_1[line]<length_1[i]){
                pointer[line] = judge[i];
                pointer[i] = judge[line];
            }
            else if(length_1[line]==length_1[i]){
                if (compare(pointer[i], pointer[line])){
                    pointer[line] = judge[i];
                    pointer[i] = judge[line];
                }
            }
        }
        else if(MAX<counter[i]){
        MAX = counter[i];
        line = i;
        }
        
        }
    }
    //显示回文数
    if(MAX==0)
    printf("None");
    else if(counter_p==1){
        printf("%s ", pointer[line]);
        printf("%d\n", MAX);
    }
    else{
        for (int t = 0; t < counter_p;t++){
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
    for (i = 0; i < 100; i++){
      if(number[i]!='\000')
         m++;
      else{
         i = 0;
         //m = m - 1;
         break;
      }
    }
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

int compare(char a[],char b[])
{
    int flag = 0;
    for (int i = 0; i < 1024;i++)
     if(a[i]>b[i])
        break;
    else{
        flag = 1;
        break;
    }
    return flag;
}