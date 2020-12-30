#include<stdio.h>

void sub(int a,int b,int c);
void switch_month(int month);
int is_MMDDYY(int month,int day,int year);
int is_run(int year);
int main()
{
	int a,b,c;
	int r1,r2;
	scanf("%d/%d/%d",&a,&b,&c); //MM/DD/YY  YY/MM/DD.
	r1=is_MMDDYY(a,b,c);
	r2=is_MMDDYY(b,c,a);
	if(r1&&r2)
	sub(a,b,c);
	else if(r1){
		switch_month(a);
	    printf("%d, ",b);
	    printf("20%d",c);
	}
	else{
		switch_month(b);
	    printf("%d, ",c);
	    printf("20%d",a);
	}
}

void switch_month(int month)
{
	switch(month)
	{
		case 1:printf("January ");
		break;
		case 2:printf("February ");
		break;
		case 3:printf("March ");
		break;
		case 4:printf("April ");
		break;
		case 5:printf("May ");
		break;
		case 6:printf("June ");
		break;
		case 7:printf("July ");
		break;
		case 8:printf("August ");
		break;
		case 9:printf("September ");
		break;
		case 10:printf("October ");
		break;
		case 11:printf("November ");
		break;
		case 12:printf("December ");
		break;
	}
}

int is_MMDDYY(int a,int b,int c)
{
	switch(a)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(b>31)
			return 0;
			else
			return 1;
		case 4:
		case 6:
		case 9:
		case 11:
			if(b>30)
			return 0;
			else
			return 1;
		case 2:
			if(is_run(c)){
				if(b>29)
				return 0;
				else
				return 1;
			}
			else{
				if(b>28)
				return 0;
				else
				return 1;
			}
		default:
		return 0;	
	}
}

int is_run(int year)
{
	if(year%4!=0)
	return 0;
	else{
		if(year%100==0)
		return 0;
		else
		return 1;
	}
}

void sub(int a,int b,int c)
{
	long temp1=0;
	long temp2=0;
	int year1,month1,day1; 
	int year2,month2,day2;
	temp1 = 10000 * a + 100 * b + c; //YY/MM/DD
	temp2 = 10000 * c + 100 * a + b; //MM/DD/YY
	if(temp1<temp2){//È«²¿ÕûÀíÎªYY/MM/DD 
		year2=c;
		month2=a;
		day2=b;
		year1=a;
		month1=b;
		day1=c;
	}
	else{
		year1=c;
		month1=a;
		day1=b;
		year2=a;
		month2=b;
		day2=c;
	}
	int counter=0;
	while(1){
		switch(month1)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		if(day1==31&&month1==12){
			day1 = 1;
			month1 = 1;
			year1 += 1;
			counter++;
			break;
		}
			if(day1==day2){
				if(month1==month2){
					if(year1==year2)
						goto p;
				}
				else{
					if(day1==31){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
			}
			else{
				if(day1==31){
					day1=1;
					month1+=1;
					counter++;
					}
				else{
					day1+=1;
					counter++;
				}
			}
			break;	
		case 4:
		case 6:
		case 9:
		case 11:
		if(day1==31&&month1==12){
			day1 = 1;
			month1 = 1;
			year1 += 1;
			counter++;
			break;
		}
			if(day1==day2){
				if(month1==month2){
					if(year1==year2)
						goto p;
					else{
					if(day1==30){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
				}
				else{
					if(day1==30){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
			}
			else{
				if(day1==30){
					day1=1;
					month1+=1;
					counter++;
					}
				else{
					day1+=1;
					counter++;
				}
			}
			break;	
		case 2:
		if(day1==31&&month1==12){
			day1 = 1;
			month1 = 1;
			year1 += 1;
			counter++;
			break;
			}
			if(is_run(year1)){
				if(day1==day2){
				if(month1==month2){
					if(year1==year2)
						goto p;
					else{
					if(day1==29){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
				}
				else{
					if(day1==29){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
			}
			else{
				if(day1==29){
					day1=1;
					month1+=1;
					counter++;
					}
				else{
					day1+=1;
					counter++;
				}
			}
			break;		
			}
			else{
				if(day1==day2){
				if(month1==month2){
					if(year1==year2)
						goto p;
						else{
					if(day1==28){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
				}
				else{
					if(day1==28){
						day1=1;
						month1+=1;
						counter++;
					}
					else{
						day1+=1;
						counter++;
					}
				}
			}
			else{
				if(day1==28){
					day1=1;
					month1+=1;
					counter++;
					}
				else{
					day1+=1;
					counter++;
				}
			}
			break;		
			}
	}
	
	}
	p:
	printf("%d",counter);
}