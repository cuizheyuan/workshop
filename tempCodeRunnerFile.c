#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	unsigned long long arr[64][64];
	unsigned long long arr_new[64][64];
	unsigned long long arr_temp[64][64];
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			scanf("%lld",&arr[i][k]);
		}
	}
	for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				arr_new[i][k]=arr[i][k];
			} 
		}
	int sum=0;
	for(int o=1;o<m;o++){
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				for(int r=0;r<n;r++){
					sum+=arr[i][r]*arr_new[r][k];
				}
			arr_temp[i][k]=sum;
			sum = 0;
			}
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				arr_new[i][k]=arr_temp[i][k];
			} 
		}
	}
	for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				printf("%lld ",arr_new[i][k]);
			} 
		printf("\n");
		}
}