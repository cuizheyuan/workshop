/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 4096
int main()
//
//{
// char buf[MAX_LINE];   *缓冲区*/
//   FILE *fp;             /*文件指针*/
//   int len;              /*行字符个数*/
//   if((fp = fopen("input.txt","r")) == NULL)
//   {
//   perror("fail to read");
 //  exit (1) ;
//   }
//     while(fgets(buf,MAX_LINE,fp) != NULL)
//   {
//   len = strlen(buf);
//  buf[len-1] = '\0';  /*去掉换行符*/
//   printf("%s %d \n",buf,len - 1);
//   }
//  return 0;
//  }

#include <stdio.h>
#include <string.h>


int main()
{      
  char buffer[4096] = {0};
  int len = 0;
  FILE *fp = fopen("input.txt", "r");    

  if(NULL == fp)     
    {          
      printf("failed to open input.txt\n");          
      return 1;         
    }

  while(!feof(fp))  
    {          
      memset(buffer,0, sizeof(buffer));                 
      fgets(buffer,sizeof(buffer) - 1, fp); // 包含了换行符          
      printf("%s",buffer);      
    }
  
  fclose(fp);  
  printf("\n");        
  return 0;

}
