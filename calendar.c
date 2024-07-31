#include<stdio.h>
int daysinmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{
	int year;
	
	printf("Please Enter a year: ");
	scanf("%d", &year);
	return year;
}
int dayscode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int leapyears(int year)
{
	if(year% 4 ==0 && year%100!= 0 || year%400 == 0)
	{
		daysinmonth[2] = 29;
		return 1;
	}
	else
	{
		daysinmonth[2] = 28;
		return 0;
	}
}

void calendar(int year,int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s [ %d ]", months[month],year);
		printf("\n-----------------");
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		for ( day = 1; day<=1+daycode*5;day++ )
		{
			printf(" ");
		}
		for ( day = 1; day <= daysinmonth[month]; day++ )
		{
			printf("%2d", day );
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
				printf("\n " );
		}
			daycode = ( daycode + daysinmonth[month] ) % 7;
	}
}

int main(void)
{
	int year, daycode, leapyear,ch;
	year = inputyear();
	daycode = dayscode(year);
//printf("\nEnter Your Choice: ");
//scanf("%d",&ch);
	leapyears(year);
	calendar(year,daycode);
	printf("\n");
}


