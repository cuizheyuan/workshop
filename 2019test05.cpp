#include<stdio.h>
#include<string.h>


int main()
{
	int n,w;
	int o=0;
	int num_ori[1024];
	int num[1024];
	scanf("%d %d",&w,&n);
	getchar();
		do
		{
			scanf("%d",&num_ori[o]);
			o++;	
		}while(getchar()!='\n');
		
		for(int i=0;i<n;i++){
		num[i]=num_ori[i];
		}
		for(int i=0;i<(n-(w/2)*2);i++){
			int sub_arr[128]={0};
			for(int k=0;k<w;k++){
				sub_arr[k]=num_ori[k+i];
			}
			int temp=0;
			for(int p=0;p<w;p++){
				for(int q=p+1;q<w;q++){
					if(sub_arr[p]>sub_arr[q]){
						temp=sub_arr[p];
						sub_arr[p]=sub_arr[q];
						sub_arr[q]=temp;
					}
				}
			}
			num[i+(w/2)]=sub_arr[w/2];
		}
		if(w%2==0)
		printf("ERROR");
	else{
		for(int i=0;i<n;i++)
		printf("%d ",num[i]);
	}
	
}
