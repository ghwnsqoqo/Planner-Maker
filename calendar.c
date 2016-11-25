#include "common.h"
#define leapyear(year) ((year)%4==0 && ((year)%100!=0||(year)%400==0))	//윤년판단매크로
void SetConsoleTextColor(int bgcolor, int color);	//console 글씨색상을 바꾸는 함수
void memo();	//일정 등록 함수
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void textcolor(int color_number);

void calendarimg()
{
	int z;
	for (z = 0; z <= 15; z++)
	{
		textcolor(z);
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□■■■■□□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
		printf("□■□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
		printf("□■□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
		printf("□■□□□□□□□■■■□□■□□■■■□□■□■■□□□■■■■□□■■■□□■■□\n");
		printf("□■□□□□□□□□□□■□■□■□□□■□■■□□■□■□□□■□□□□□■□■□□\n");
		printf("□■□□□□□□□■■■■□■□■■■■■□■□□□■□■□□□■□□■■■■□■□□\n");
		printf("□■□□□□□□■□□□■□■□■□□□□□■□□□■□■□□□■□■□□□■□■□□\n");
		printf("□■□□□□■□■□□□■□■□■□□□■□■□□□■□■□□□■□■□□□■□■□□\n");
		printf("□□■■■■□□□■■■■□■□□■■■□□■□□□■□□■■■■□□■■■■□■□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		Sleep(100);
		system("cls");
	}
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□□■■■■□□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
	printf("□■□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
	printf("□■□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□□□\n");
	printf("□■□□□□□□□■■■□□■□□■■■□□■□■■□□□■■■■□□■■■□□■■□\n");
	printf("□■□□□□□□□□□□■□■□■□□□■□■■□□■□■□□□■□□□□□■□■□□\n");
	printf("□■□□□□□□□■■■■□■□■■■■■□■□□□■□■□□□■□□■■■■□■□□\n");
	printf("□■□□□□□□■□□□■□■□■□□□□□■□□□■□■□□□■□■□□□■□■□□\n");
	printf("□■□□□□■□■□□□■□■□■□□□■□■□□□■□■□□□■□■□□□■□■□□\n");
	printf("□□■■■■□□□■■■■□■□□■■■□□■□□□■□□■■■■□□■■■■□■□□\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

}

void calendar()
{
	system("cls");
	today();
	int year, month = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int lastyear, day, i;
	
	FILE * fp = fopen("calendar.txt", "wt"); //calendar.txt에출력하기위해오픈한다.

	printf("몇년(年)의 달력을 출력하시겠습니까 ? ");
	scanf("%d", &year);
	printf("몇월(月)의 달력을 출력하시겠습니까 ? ");
	scanf("%d", &month);
	printf("달력을 생성중입니다. 잠시만기다려주세요");
	for (int jum = 0; jum < 8; jum++)
	{
		Sleep(100);
		printf("..");
		
	}
	printf("\n");
	Sleep(1000);
	system("cls");
	today();
	if (month == 2 && leapyear(year))	//윤년판단
		totalday[2] = 29;

		lastyear = year - 1;
	{
			day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;

			for (i = 1; i < month; i++)
			{
				day += totalday[i];
				day %= 7;
			}
			//console에 출력
			printf("\n\t");
			SetConsoleTextColor(0x0, 0xe);	//노란색글씨로 바꾼다.
			printf("\t\t%d년 %d월\n", year, month);
			SetConsoleTextColor(0x0, 0xc);	//빨간색글씨로바꾼다.
			printf("\n   일");
			SetConsoleTextColor(0x0, 0xf);	//흰색글씨로 복귀
			printf("\t  월\t  화\t  수\t  목\t  금");
			SetConsoleTextColor(0x0, 0x9);	//파란색글씨로 바꾼다.
			printf("\t  토");
						
			
			SetConsoleTextColor(0x0, 0xf);	//하얀색글씨로복귀
			printf("\n  ===================================================");

			fprintf(fp, "\n			%d년%d월\n", year, month);
			fprintf(fp, "\n일\t월화\t수\t목\t금\t토");

			for (i = -day; i<totalday[month]; i++)
			{
				if ((i + day) % 7 == 0)
				{
					printf("\n");
					fprintf(fp, "\n");
				}
				if (i < 0)
				{
					printf("\t");
					fprintf(fp, "		");
				}
				else
				{
					//토요일의 경우 파란색으로 출력한다.
					if ((i + day) % 7 == 6)	SetConsoleTextColor(0x0, 0x9);
					//일요일의 경우 빨간색으로 출력한다.
					if ((i + day) % 7 == 0) SetConsoleTextColor(0x0, 0xc);	printf("%4d\t", i + 1);
					//흰색글씨로 복귀
					SetConsoleTextColor(0x0, 0xf);
					fprintf(fp, "%4d", i + 1);
				}
			}
	}
	printf("\n\n");
	fprintf(fp, "\n\n");
	fclose(fp);
	
	memo();
}

void SetConsoleTextColor(int bgcolor, int color)	
{
	bgcolor &= 0xf;
	color &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}





void memo()
{
	int day;
	printf("무엇을만들까 : ");
	scanf("%d",&day);
}


