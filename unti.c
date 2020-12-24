#include<stdio.h>
int main(void)
{
	int i;
	double a[10];
	
	for(;;){
    
    for(i=0;i<5;i++){
    	scanf("%lf",&a[i]);
	}

    if(a[4]==a[3]&&a[3]==a[2]&&a[2]==a[1]&&a[1]==a[0]&&a[0]==0)
	  return 0;

	if(a[4]-a[3]==a[3]-a[2]&&a[3]-a[2]==a[2]-a[1]&&a[2]-a[1]==a[1]-a[0]){
		printf("case one\n");
		for(i=5;i<10;i++){
			a[i]=a[i-1]+(a[1]-a[0]);
		    printf("%.0lf ",a[i]);
		}
		printf("\n");
	}
	if(a[4]/a[3]==a[3]/a[2]&&a[3]/a[2]==a[2]/a[1]&&a[2]/a[1]==a[1]/a[0]){
		printf("case two\n");
		for(i=5;i<10;i++){
			a[i]=a[i-1]*(a[1]/a[0]);
			printf("%.0lf ",a[i]);
		}
		printf("\n");
	}
	if(a[4]==a[3]+a[2]&&a[3]==a[2]+a[1]&&a[2]==a[1]+a[0]){
		printf("case three\n");
		for(i=5;i<10;i++){
			a[i]=a[i-1]+a[i-2];
			printf("%.0lf ",a[i]);
		}
		printf("\n");
	}
    }
}