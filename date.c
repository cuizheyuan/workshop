#include<stdio.h>

//程序：带星期计算的日期输出
//作者:崔哲源 2020141460101

int main(void)
{
	int month, day, year;
	int week, c, year1, month1;       //使用month1,year1代替原变量参与运算，防止后续输出混乱
	c = 20 ;                          //因为程序只考虑21世纪的情况，所以直接赋值为20
	 
	printf("Enter date (mm/dd/yy)");
	scanf("%d /%d /%d",&month, &day, &year);
	
	if (month <= 2)
	{
		year1 = year;
		year1 = year1 - 1;
		month1 = month;
		month1 = month1 + 12;   	//在蔡琴公式中某一年的1、2月要看作上一年的13、14月
	}
	else
	{
		year1 = year;
		month1 = month;
	}
	
	week = ( ( year1 + ( year1 / 4 ) + ( c / 4 ) - 2 * c + ( ( 26 * ( month1 + 1 ) ) / 10 ) + day - 1 ) % 7 );
	//利用蔡琴公式计算星期，用7取余
	
	printf("Dated this %d",day);
	switch (day)                             //在日期后加后缀
		{
		case 1: case 21 : case 31:
			printf ("st");
			break;
		case 2: case 22:
			printf ("nd");
			break;
		case 3: case 23:
			printf ("rd");
			break;
		default:
			printf ("th");
			break;
		} 
	
	printf (" day of ");
	
	switch (month)                    //选择对应月份的英文
		{
		case 1:  printf("Jaunary");    break;
		case 2:  printf("February");   break;
		case 3:  printf("March");      break;
		case 4:  printf("April");      break;
		case 5:  printf("May");        break;
		case 6:  printf("June");       break;
		case 7:  printf("July");       break;
		case 8:  printf("August");     break;
		case 9:  printf("September");  break;
		case 10: printf("October");    break;
		case 11: printf("November");   break;
		case 12: printf("December");   break;
		}
	
	printf(", ") ;
	
	switch (week)                   //选择对应星期的英文
		{
		case 1: printf("Monday");      break;
		case 2: printf("Tuesday");     break;
		case 3: printf("Wednesday");   break;
		case 4: printf("Thursday");    break;
		case 5: printf("Friday");      break;
		case 6: printf("Saturday");    break;
		case 0: printf("Sunday");      break;
		default:printf("Error");       break;
		}
	
	printf(", 20%.2d.\n", year);
	return 0;
}