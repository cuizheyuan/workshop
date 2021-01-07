#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main()
{	
	char ch;
	int line=0;
	int row=0;
	char arr[64][50];
	bool flag= true ;
	for(int i=0;i<64;i++){
		for(int k=0;k<50;k++)
		arr[i][k]=0;
	}
	while(1){
		ch=getchar();
		if(ch==(-1)){
			break;
		}
		else if(ch>=65&&ch<=90){
			if(flag == false){
				line += 1;
				row =0;
			}
			flag=true;
			arr[line][row]=ch+32;
			row++;
		}
		else if(ch>=97&&ch<=122){
			if(flag == false){
				line += 1;
				row = 0;
			}
			flag=true;
			arr[line][row]=ch;
			row++;
		}
		else
			flag=false;
	}
	line+=1;
	/*
	for(int i=0;i<line;i++){
		for(int k=i+1;k<line;k++){
			if(strcmp(arr[i],arr[k])>0){
				char temp[50];
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[k]);
				strcpy(arr[k],temp);
			}
		}
	}
	*/
	bool table[128]={false};
	int counter[128]={0};
	for(int i=0;i<line;i++){
		if(table[i]==true)
		continue;
		for(int k=i+1;k<line;k++){
			if(strcmp(arr[i],arr[k])==0){
			table[k]=true;
			counter[i]++;
			}
		}
	}
	
	int max=-1;
	int max_p=0;
	for(int i=0;i<line;i++){
		if(table[i] == false){
			if(max<counter[i]){
			max = counter[i];
			max_p=i;
			}
			else if(max==counter[i]){
				if(strcmp(arr[max_p],arr[i])<0){
					max = counter[i];
					max_p=i;
				}
			}
		}
	}
	printf("%s ",arr[max_p]);
	printf("%d\n",max+1);
}

