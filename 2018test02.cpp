#include<stdio.h>

int main()
{
	int n=0;
	int flag=0;
	scanf("%d",&n);
	getchar();
	double sum=0;
	double avr=0;
	for(int i=0;i<n+1;i++){
		int temp=0;
		int temp1=0;
		temp1=getchar();
		if(temp1<=57||temp>=48){
			ungetc(temp1,stdin);
			scanf("%d",&temp);
			getchar();
			sum=sum+temp;
			flag=1;
		}
		else{
			n=n-1;
			for(int k=0;k<3;k++)
			getchar(); 
		}
		

	}
	avr=sum/n;
	if(flag==1)
	printf("%.2lf",avr);
	else
	printf("n/a");
}
