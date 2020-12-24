#include<stdio.h>
#include<stdbool.h>

void reverse(char array[]);
int main()
{
    bool flag = true;
    bool table[100] = {1};
    int line = 0;
    int posit = 0;
    int temp_c = 0;
    char host[100][100];

    for (int i = 0; i < 100;i++){
        for (int k = 0; k < 100;k++)
            host[i][k] = 0;
    }

    while(1){
        temp_c = getchar();
        if(temp_c=='\n')
            break;
        if(temp_c>='A'&&temp_c<='z'){
            if(flag==false){
                line++;
                posit = 0;
                }
                host[line][posit] = temp_c;
                posit++;
                flag = true;
                table[line] = true;
            }
            else{
                if(flag==true){
                    line++;
                    posit = 0;
                }
                host[line][posit] = temp_c;
                posit++;
                flag = false;
                table[line] = false;
            }
        }

        for (int i = 0; i <= line;i++){
            if(table[i]==true)
            reverse(host[i]);
            printf("%s", host[i]);
        }
        

}

void reverse(char array[])
{
    int length = 0;
    char temp = 0;
    for (int i = 0; i < 100;i++){
        if(array[i]!=0)
            length++;
        else
            break;
    }

    for (int k=0; k < length / 2;k++){
        temp = array[k];
        array[k] = array[length - 1 - k];
        array[length - 1 - k] = temp;
    }
}