#include<stdio.h>
#include<math.h>

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double w=0;
		double res=0;
		scanf("%lf",&w);
		if(w>=0){
		res=sqrt(w);
		printf("%.2lf\n",res);	
		}
		else{
			printf("ERROR\n");
		}
	}
}
