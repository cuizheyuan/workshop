#include<stdio.h>

int main(int argc,char* argv[])
{
    //FILE *fp;
    //char name[50];
    //char content[128];
    char in[50] = {0, 'a', 's',5,12,77,'l'};
    int out[50] = {0};
    //scanf("%s", name);
    //fp = fopen(name, "r");
    //fgets(content, 128, fp);
    //fprintf(stdout, "%s", content);
    for (int i = 0; i < 8;i++)
        sprintf((char*)out, "%d %d %d", in[0],in[1],in[2]);
    printf("%s ", (char*)out);
}