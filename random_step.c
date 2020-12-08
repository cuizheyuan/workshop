/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int direction(int round);

int main(void)
{
    srand((unsigned)time(NULL));
    int line, straight = 0;
    int direc = 0;
    line = rand()%10;
    straight = rand()&10;
    char a[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10;k++)
        {
            a[i][k] = '.';
        }
    }

    a[line][straight] = 'A';
    for (int i = 1; i < 27; i++)
    {
        //0 up,1 right,2 down,3right

            switch (direction(i))
            {
            case 0:
                if (line != 0)
                {
                    a[line - 1][straight] = 'A' + i;
                    line--;
                }
                else
                case 1:
                    if (straight != 9)
                    {
                        a[line][straight + 1] = 'A' + i;
                        straight++;
                    }
                    else
                    case 2:
                        if (line != 9)
                        {
                            a[line + 1][straight] = 'A' + i;
                            line++;
                        }
                        else
                        case 3:
                            if (straight != 0)
                            {
                                a[line][straight - 1] = 'A' + i;
                                straight--;
                            }
                            else
                            default:
                                goto L;
            }
}

    {L:
        for (int k = 0; k < 10;k++)
        {
            for (int j = 0; j < 10;j++)
            {
                printf("%c", a[k][j]);
            }
        printf("\n");
        }
    }
    while(1){}
}


int direction(int round)
{
    int direction;
    srand((unsigned)time(NULL));
    direction = rand() % 4;
    return direction;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 
#define N 10
 
int main(void){
    // 棋盘初始化
    char ch[N][N];

    for(int i =0 ; i < N ; i++){
        for(int j = 0; j < N ;j++){
            ch[i][j]='.';
        }
    }
    
    srand((unsigned int) time(NULL));    // 生成随机数前，先调用 srand 函数
    bool point[N][N]={false};    // 此bool型所有元素，必须先初始化。因为我调试了好久发现，如果不初始化，程序运行后，棋盘有的为true,有的为fale。
    int ptx = 0,pty = 0;        // 数组元素的横纵坐标
    
    ch[0][0] = 'A';            // 给 A 一个初始化，程序总是从ch[0][0] = 'A' 开始打印的
    point[0][0] = 1;
 
//简单讲个小故事，分析一下代码~~~~~~~~~~~此段可略过
//    现在假设我们站在十字路口——即一个 crossroads[4][3],
//    我们面临4个方向,但是要随机产生一个方向通过,
//    0:表示这个点没有字母，为false。
//    某个位置的字母这样表示 ch[temp_ptx][temp_pty]
//    temp_ptx：以"十字路口"为起点，下一个字母所在位置的temp_ptx值，
//    temp_pty：以"十字路口"为起点，下一个字母所在位置的temp_pty值。
//    所以，我们要全力打造出如下形式的数组，冲鸭！！！
//    int crossroads[4][3] = {
//        {0,temp_ptx,temp_pty},
//        {0,temp_ptx,temp_pty},
//        {0,temp_ptx,temp_pty},
//        {0,temp_ptx,temp_pty}
//    };
 
    int k = 0;  // 根据k的值，可以判断crossroads数组元素有几个（十字路口的出口个数）
    int m = 0 , n = 0;  // crossroads 下标
    int letusgo = 0;    // 出口方向——冲鸭！！！
 
    for(int Alphabet = 0; Alphabet < 25; Alphabet++){ //'A'已经有了,剩余那25个在此等候
    
    // crossroads 的 4 种出口情况
        m = 0 ; n = 0 ;    // m ,n 出口下标清零
        k = 0;      //根据 k 的值，计算出口的个数
        int crossroads[4][3];
        int temp_ptx = ptx;  // 每次循环，用临时变量temp_ptx和temp_pty记住上次所在位置，
        int temp_pty = pty; // 要是直接用全局变量ptx和pty，你会迷路的！！！嘿嘿！
//  第一种情况：南下
        if((ptx+1)>0 && (ptx+1)<=9){
            temp_ptx = ptx + 1;
            temp_pty = pty;
            if(!point[temp_ptx][temp_pty]){
                crossroads[m][n] = point[temp_ptx][temp_pty];
                crossroads[m][n+1] = temp_ptx;
                crossroads[m][n+2] = temp_pty;
                k++;
            }
        }
//  第二种情况：右路
        if((pty+1)>0 && (pty+1)<=9){
            
            temp_ptx = ptx;
            temp_pty = pty + 1;
            if(!point[temp_ptx][temp_pty]){
                if(k!=0){    // 在m++前，别忘了判断 k 的值，
                    m++;    //否则程序怎么知道crossroads[0][0] 有没有元素。
                }
                crossroads[m][n] = point[temp_ptx][temp_pty];
                crossroads[m][n+1] = temp_ptx;
                crossroads[m][n+2] = temp_pty;
                k++;
            }
        }
//  第三种情况：北上
        if((ptx-1)>=0 && (ptx-1)<10){
           
            temp_ptx = ptx - 1;
            temp_pty = pty;
            if(!point[temp_ptx][temp_pty]){
                if(k!=0){
                    m++;
                }
                crossroads[m][n] = point[temp_ptx][temp_pty];
                crossroads[m][n+1] = temp_ptx;
                crossroads[m][n+2] = temp_pty;
                k++;
            }
        }
//  第四种情况：左路
        if((pty-1)>=0 && (pty-1)<10){
            
            temp_ptx = ptx;
            temp_pty = pty - 1;
            if(!point[temp_ptx][temp_pty]){
                if(k!=0){
                    m++;
                }
                crossroads[m][n] = point[temp_ptx][temp_pty];
                crossroads[m][n+1] = temp_ptx;
                crossroads[m][n+2] = temp_pty;
                k++;
            }
        }
        
        if(k == 0 ){
            break;
        }else{
            letusgo = (int)(rand() % k );    // 根据k得知有几条路可选，随机选择一条路
            
            temp_ptx = crossroads[letusgo][1];
            temp_pty = crossroads[letusgo][2];
            point[temp_ptx][temp_pty] = 1;  // 确定下一个点，赋值为true,这个点下次就不能再经过了
            ch[temp_ptx][temp_pty] = ch[ptx][pty]+1 ;// 按字母表顺序，确定下一个字母
            ptx = temp_ptx;        // 把上一个点的位置覆盖，然后进入下一个循环
            pty = temp_pty;
 
        }
 
    }
    
 
//**********  打印最终结果  ***************
    for(int i =0 ; i < N ; i++){
        for(int j = 0; j < N ;j++){
            printf("%c ", ch[i][j]);
        }
        printf("\n");
    }
//****************************************
    return 0;
}
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define N 10
#define WAY 4
 
int main(void)
{
	bool a[N][N] = {false};
	char b[N][N];
	int i, j;
	
	//初始化表 
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			b[i][j] = '.';
		}
	}
	
	srand((unsigned) time(NULL));
	int ways;
	i = 0; j = 0;
	b[0][0] = 'A';
	a[0][0] = true;
	
	for (int m = 0; m < 25; ) {
		 //余0表上， 1表下， 2表左， 3表右 
		ways = rand() % WAY;      
		
		if (ways == 0) {
			//如果往上走出表格了，continue重新循环试试别的方向 
			if (i - 1 < 0) {
				continue;
			} 
			//如果往上走有字母了， 进行判断 
			else if (a[i - 1][j] == true){
				//如果四面都是字母，退出 
				if ((a[i + 1][j] == true && a[i][j - 1] == true && a[i][j + 1] == true)
				// 考虑左边和左下角情况 
					|| j - 1 < 0 && a[i + 1][j] == true && a[i][j + 1] == true
					|| j - 1 < 0 && i + 1 > 9 && a[i][j + 1] == true
				// 右边和右下角
					|| j + 1 > 9 && a[i + 1][j] == true && a[i][j - 1] == true
					|| j - 1 < 0 && i + 1 > 9 && a[i][j + 1] == true
				//下边
					|| i + 1 > 9 && a[i][j + 1] == true && a[i][j - 1] == true) break;
				//如果都不是，重新选方向 
				continue;
			} else {				
				a[i - 1][j] = true;
				b[i - 1][j] = 'B' + m;
				m++;
				i--;
				continue;
			}
		} 
		
		if (ways == 1) {
			if (i + 1 > 9) {
				continue;
			} else if (a[i + 1][j] == true){
				if (a[i - 1][j] == true && a[i][j - 1] == true && a[i][j + 1] == true
				//右边和右上角 
					|| j + 1 > 9 && a[i][j - 1] == true && a[i - 1][j] == true
					|| j + 1 > 9 && i - 1 < 0 && a[i][j - 1] == true
				//左边 
					|| j - 1 < 0 && a[i - 1][j] == true && a[i][j + 1] == true
				//上边 
					|| i - 1 < 0 && a[i][j + 1] == true && a[i][j - 1] == true) break;
				continue;
			} else {				
				a[i + 1][j] = true;
				b[i + 1][j] = 'B' + m;
				m++;
				i++;
				continue;
			}
		} 
		
		if (ways == 2) {
			if (j - 1 < 0) {
				continue;
			} else if (a[i][j - 1] == true){
				if (a[i + 1][j] == true && a[i - 1][j] == true && a[i][j + 1] == true
				// 考虑下边和右下角情况 
					|| i + 1 > 9 && a[i - 1][j] == true && a[i][j + 1] == true
					|| j + 1 > 9 && i + 1 > 9 && a[i - 1][j] == true
				// 上边和右上角
					|| i - 1 < 0 && a[i + 1][j] == true && a[i][j + 1] == true
					|| j + 1 > 9 && i - 1 < 0 && a[i][j + 1] == true
				// 右边
					|| j + 1 > 9 && a[i - 1][j] == true && a[i + 1][j] == true) break;
				continue;
			} else {				
				a[i][j - 1] = true;
				b[i][j - 1] = 'B' + m;
				m++;
				j--;
				continue;
			}
		} 
		
		if (ways == 3) {
			if (j + 1 > 9) {
				continue;
			} else if (a[i][j + 1] == true){
				if (a[i + 1][j] == true && a[i][j - 1] == true && a[i - 1][j] == true
				//左边和左下角 
					|| j - 1 < 0 && a[i - 1][j] == true && a[i + 1][j] == true
					|| j - 1 < 0 && i + 1 > 9 && a[i - 1][j] == true
				//下边 
					|| i + 1 > 9 && a[i - 1][j] == true && a[i][j - 1] == true
				//上边 
					|| i - 1 < 0 && a[i][j - 1] == true && a[i + 1][j] == true) break;
				continue;
			} else {				
				a[i][j + 1] = true;
				b[i][j + 1] = 'B' + m;
				m++;
				j++;
				continue;
			}
		} 
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}