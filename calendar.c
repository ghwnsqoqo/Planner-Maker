#include "common.h"
#include "selectmenu.h"
#define leapyear(year) ((year)%4==0 && ((year)%100!=0||(year)%400==0))	//윤년판단매크로

void textcolor(int color_number)	//글자색 변경 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void textcolor(int color_number);

void Exit();
void d_day();
void memo_menu();
void calendar_p();	//달력모양출력함수

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

int year, month = 0;
int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int lastyear, day, i;

void calendar()	//달력정보를 입력받는함수
{
	system("mode con:cols=100 lines=30");
	system("cls");
	today();

	
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
	calendar_p();

//메뉴부분진입	
	while (1)
	{
		char ch2 = function_select_menu();
		switch (ch2)
		{
		case'1': memo_menu();	break;
		case'2': d_day();	break;
		case'3': Exit();	exit(0);
		}
	}
}


void calendar_p()
{
	
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
		printf("\n\t\t\t\t");
		textcolor(14);	//노란색글씨로 바꾼다.
		printf("\t\t%d년 %d월\n\n", year, month);
		textcolor(12);	//빨간색글씨로바꾼다.
		printf("\n\t\t\t  일");
		textcolor(15);	//흰색글씨로 복귀
		printf("\t  월\t  화\t  수\t  목\t  금");
		textcolor(9);	//파란색글씨로 바꾼다.
		printf("\t  토");


		textcolor(14);	//노란색글씨로 바꾼다.
		printf("\n\t\t\t  ===================================================");

		textcolor(15);	//하얀색글씨로복귀
		for (i = -day; i < totalday[month]; i++)
		{
			if ((i + day) % 7 == 0)
			{
				printf("\n\t\t\t");
			}
			if (i < 0)
			{
				printf("\t");
			}
			else
			{
				//토요일의 경우 파란색으로 출력한다.
				if ((i + day) % 7 == 6)	textcolor(9);
				//일요일의 경우 빨간색으로 출력한다.
				if ((i + day) % 7 == 0) textcolor(12);	printf("%4d\t", i + 1);
				//흰색글씨로 복귀
				textcolor(15);
			}
		}
	}
	printf("\n\n");
	
}