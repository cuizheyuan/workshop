#include<stdio.h>

int main(int argc,char* argv[])
{
    FILE *fp;
    char name[50];
    char content[128];
    scanf("%s", name);
    fp = fopen(name, "r");
    fscanf(fp, "%s", content);
    fprintf(stdout, "%s", content);
}