#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n][n];
	int arr_new[n][n];
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			scanf("%d",arr[i][k]);
			getchar();
		}
	}
	int sum=0;
	for(int o=0;o<m;o++){
		for(int i=0;i<n;n++){
			for(int k=0;k<n;k++){
				for(int r=0;r<n;k++){
					sum+=arr[i][r]*arr[r][k];
				}
			arr_new[i][k]=sum;
			}
		}
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				arr[i][k]=arr_new[i][k];
			} 
		}
	}
	for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				printf("%d ",arr[i][k]);
			} 
		printf("\n");
		}
}
