#include<stdio.h>

int main(){
	long type[2048]={1000000};
	int temp=0;
	int counter=0;
	int flag=0;
		int n=0;
		scanf("%d",&n);
		getchar();;
		for(int k=0;k<n;k++){
			scanf("%d",&temp);
			for(int i=0;i<=counter;i++){
				if(temp==type[i]){
				 flag=1;
				}
			}
			if(flag==0){
			type[counter]=temp;
			counter++;
			}
			flag=0;
		}
		printf("%d\n",counter);
	}


