#include<stdio.h>
#include<stdlib.h>


int		getFirstDay(int year,int month);
int		getDayCode(int year);
void	CalendarArraySave(int year, int month);
void	writeCalendarFile( FILE *fp );

static int montharry[12][42];

int main()
{
	int		i, j, k, l, t, year;
	FILE	*fp;
	char	buff[255];



	year = atoi(buff);									

	fp = fopen("./cal.out", "w");						
	if (fp == NULL)
	{
		printf("cal.out 파일 오픈 에라입니다.");
		return 0;
	}
	
	printf("                                          %d\n", year);
	fprintf(fp, "                                             %d\n", year);

	for( i = 1; i <= 12; i++ )							
	{
		CalendarArraySave(year,i);
	 }


	writeCalendarFile(fp);							

	fclose(fp);


	return 0;
}
void	writeCalendarFile( FILE *fp )
{
	int		i, j, k, l, t;

	
	for (i = 0; i < 4; i++ )								
	{
		printf("            %d                               %d                               %d\n", (3*i)+1, (3*i)+2, (3*i)+3);
		fprintf(fp, "            %d                               %d                               %d\n", (3*i)+1, (3*i)+2, (3*i)+3);
		for (t = 0; t < 3 ; t++ )						
		{
		printf("%s  %s  %s  %s  %s  %s  %s","Su","Mo","Tu","We","Th","Fr","Sa");
			fprintf(fp, "%s  %s  %s  %s  %s  %s  %s","Su","Mo","Tu","We","Th","Fr","Sa");
			printf("      ");
			fprintf(fp, "      ");
		}
		printf("\n");
		fprintf(fp, "\n");

		for ( l = 0; l < 6; l++)						
		{
			for (k = 0; k < 7;  k++)							
			{
				if (montharry[(i*3)][k+(l*7)] == 0)
				{
					printf("    ");
					fprintf(fp, "    ");
				}
				else {
					if (montharry[(i*3)][k+(l*7)] < 10){
						printf("%d   ", montharry[(i*3)][k+(l*7)]);
						fprintf(fp,"%d   ", montharry[(i*3)][k+(l*7)]);
					}
					else{
						printf("%d  ", montharry[(i*3)][k+(l*7)]);
						fprintf(fp,"%d  ", montharry[(i*3)][k+(l*7)]);
					}
				}
			}
			printf("   ");
			fprintf(fp, "   ");
			for (k = 0; k < 7;  k++)					
			{
				if (montharry[(i*3)+1][k+(l*7)] == 0)
				{
					printf("    ");
					fprintf(fp,"    ");
				}
				else {
					if (montharry[(i*3)+1][k+(l*7)] < 10)
					{
						printf(" %d  ", montharry[(i*3)+1][k+(l*7)]);
						fprintf(fp," %d  ", montharry[(i*3)+1][k+(l*7)]);
					}
					else
					{
						printf("%d  ", montharry[(i*3)+1][k+(l*7)]);
						fprintf(fp,"%d  ", montharry[(i*3)+1][k+(l*7)]);
					}
				}
			}
		    printf("     ");
			fprintf(fp,"     ");
			for (k = 0; k < 7;  k++)						
			{
				if (montharry[(i*3)+2][k+(l*7)] == 0)
				{
					printf("    ");
					fprintf(fp,"    ");
				}
				else {
					if (montharry[(i*3)+2][k+(l*7)] < 10)	
					{
						printf("%d   ", montharry[(i*3)+2][k+(l*7)]);
						fprintf(fp,"%d   ", montharry[(i*3)+2][k+(l*7)]);
					}
					else
					{
						printf("%d  ", montharry[(i*3)+2][k+(l*7)]);
						fprintf(fp,"%d  ", montharry[(i*3)+2][k+(l*7)]);
					}
				}
			}
			printf("\n");
			fprintf(fp,"\n");
		
		}
		printf("\n");
		fprintf(fp,"\n");
	}

	return;
}
int getFirstDay(int year,int month)
{
	 int fday = getDayCode(year);
	 int num_days=0; 
	 int dCode=getDayCode(year);

	 switch(month){
		 case 12: num_days+=30;
		 case 11: num_days+=31;
		 case 10: num_days+=30;
		 case 9: num_days+=31;
		 case 8: num_days+=31;
		 case 7: num_days+=30;
		 case 6: num_days+=31;
		 case 5: num_days+=30;
		 case 4: num_days+=31;
		 case 3: num_days+=28;
		 case 2: num_days+=31;
	 }

	 if(month==1) return(fday);
	 else if((year%4==0) || (year%400==0) && month>2) return (num_days+1+dCode)%7 ;
	
	 else return (num_days+dCode)%7;
 }
int getDayCode(int year)
{
	 int fday;

	 fday=(((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400)+1)%7;

	 return fday;
}

void CalendarArraySave(int year, int month)
{

	int	fday_month = getFirstDay(year, month);
	int	code[7]={0,1,2,3,4,5,6};
	char	*Day[7]={"Su","Mo","Tu","We","Th","Fr","Sa"};
	char	*Month[12]={"1","2","3",
						"4","5","6",
						"7","8","9",
						"10","11","12"};
	int num_days,i;
	int	nArrayIndex = 0;
														
	if(month==1||month==3||month==5||month==7|| month==8|| month==10|| month==12)
		 num_days=31;
	else if(month==2)
	{											
		 if((year%4==0) || (year%400==0)) num_days=29;
		 else num_days=28;
	}
	else num_days=30;

	nArrayIndex = month - 1;

	int j = 0;
	for(i = 1; i <= fday_month; i++)
	{
		montharry[nArrayIndex][j] = 0;
		j++;
	}
	int d = 1;
	int con = 0;

	while(d <= num_days)
	{
		montharry[nArrayIndex][j] = d;			

		j++;
		d++;
	 }
}
