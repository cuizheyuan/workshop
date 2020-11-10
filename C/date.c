#include<stdio.h>

//���򣺴��������жϵ��������
//���ߣ�����Դ 2020141460101 
//����  2020��11��9�� 

int main(void)
{
	int month, day, year;             //�������ڲ��� 
	int week, c, year1, month1;       //���ò��ٹ�ʽ�������� ��year1 ,month1���ں���ļ��㣬��ֹ�����ظ�ֵ��ʹ���������� 
	c = 20 ;                          //����ֻ����21���͵����������ֱ�Ӹ����͸�ֵ
	 
	printf("Enter date (mm/dd/yy)");
	scanf("%d /%d /%d",&month, &day, &year);
	
	if (month <= 2)
	{
		year1 = year;
		year1 = year1 - 1;
		month1 = month;
		month1 = month1 + 12;   	//�ڲ��ٹ�ʽ��һ�¶��¿�����һ���ʮ���£�ʮ���� 
	}
	else
	{
		year1 = year;
		month1 = month;
	}
	
	week = ( ( year1 + ( year1 / 4 ) + ( c / 4 ) - 2 * c + ( ( 26 * ( month1 + 1 ) ) / 10 ) + day - 1 ) % 7 );
	//������������ʽ
	
	printf("Dated this %d",day);
	switch (day)                             //�����ں���Ӻ�׺ 
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
	
	switch (month)                    //�ж��·� 
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
	
	switch (week)                    //�ж����ڼ� 
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
