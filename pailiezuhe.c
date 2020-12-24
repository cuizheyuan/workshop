#include<stdio.h>
/*
计算n个不同整数的所有的组合
输入
第1行是一个整数m，表示随后有m组数据。
每组数据占一行，第一个整数n表示随后有n个不同的整数。
输出
对每组数据，输出这n个不同整数的不同组合，含空组合。每个组合输出前输出“--> ”。
要求必须按照上课讲的递归方法来写，先输出包含该元素的情况，再输出不包含的情况，这样才能保证输出顺序和标准答案一致。
*/
int ch[100];
void loop(int length, int length_delete, int conuter1,int counter2);
int main()
{
	int num = 0;
	int length = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		length = getchar() - 48;
		scanf("%d", ch);
		loop(length,0,0,0);
	}
}

//loop函数用于进行递归
void loop(int length,int length_delete,int counter1,int counter2)
{
	int array_sub = 0;
	if(length==length_delete)   //如果元素全部被削除完，输出空箭头
		printf("-->");
	else if(counter1==(length-length_delete)*length_delete){   //如果位移元素个数达到全部个数,则再少一个元素
		length_delete++;
		counter1 = 0;
	}
	else if(length_delete<=counter1){
		for (int i=0; i < length-length_delete;i++){
			if()
			printf("%d ", ch[i]);
		}
	}

}