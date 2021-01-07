#include<stdio.h>

int main()
{
	int n=0;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		int n1=0;
		scanf("%d",&n1);
		getchar();
		int arr[1024]={0};
		for(int k=0;k<n1;k++){
			scanf("%d",&arr[k]);
			getchar();
		}
		for(int o=0;o<n1;o++){
			for(int r=o+1;r<n1;r++){
				if(arr[o]>arr[r]){
					int temp =0;
					temp=arr[r];
					arr[r]=arr[o];
					arr[o]=temp;
				}
			}
		}
		int min=arr[0];
		int flag=0;
		for(int l=0;l<n1;l++){
			if(arr[l]>min){
			printf("%d\n",arr[l]);
			flag =1;
			break;
			}
		}
		if(flag==0)
			printf("ERROR\n");
	}
}
