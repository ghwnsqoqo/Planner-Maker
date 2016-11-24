#include <stdio.h>
#include <windows.h>   // 콘솔색상을바꾸기위해서선언
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //윤년판정매크로
// Console 글씨색상을바꾸는함수
void SetConsoleTextColor(int bgcolor, int color);





//FILE * fp = fopen(".txt", "wt");  txt파일 만든후에 실행하기




int main(void)
{
	int year, month = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int lastyear, day, i;
	FILE * fp = fopen("output5.txt", "wt"); //output5.txt에출력하기위해오픈한다.

	printf("몇년의달력을출력하시겠습니까?: ");
	scanf("%d", &year);
	printf("몇월의달력을출력하시겠습니까?: ");
	scanf("%d", &month);
	if (month == 2 && leapyear(year))
		totalday[2] = 29;

	lastyear = year - 1;
	{
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;
		
		for (i = 1;i < month;i++)
		{
			day += totalday[i];
			day %= 7;
		}
		// console에출력
		printf("\n           ");
		SetConsoleTextColor(0x0, 0xe);              // 노란색글씨로바꾼다.
		printf("%d년%d월\n", year, month);
		SetConsoleTextColor(0x0, 0xc);              // 빨간색글씨로바꾼다.
		printf("\n  일");
		SetConsoleTextColor(0x0, 0xf);              // 흰색글씨로복귀
		printf("  월  화  수  목  금 ");
		SetConsoleTextColor(0x0, 0x9);              // 파란색글씨로바꾼다.
		printf(" 토");
		SetConsoleTextColor(0x0, 0xf);              // 흰색글씨로복귀

													// 파일에출력
		fprintf(fp, "\n           %d년%d월\n", year, month);
		fprintf(fp, "\n  일월화수목금토");

		for (i = -day; i<totalday[month]; i++)
		{
			if ((i + day) % 7 == 0)
			{
				printf("\n");
				fprintf(fp, "\n");
			}
			if (i<0)
			{
				printf("    ");
				fprintf(fp, "    ");
			}
			else
			{
				// 토요일일경우에는파란색으로출력한다
				if ((i + day) % 7 == 6)   SetConsoleTextColor(0x0, 0x9);
				// 일요일일경우에는빨간색으로출력한다.
				if ((i + day) % 7 == 0)   SetConsoleTextColor(0x0, 0xc);printf("%4d", i + 1);
				// 원래흰색글씨로복귀시킨다.
				SetConsoleTextColor(0x0, 0xf);
				fprintf(fp, "%4d", i + 1);
			}
		}
	}
	printf("\n\n");
	fprintf(fp, "\n\n");
	fclose(fp);
	return 0;
}


// Console 글씨색상을바꾸는함수
void SetConsoleTextColor(int bgcolor, int color)
{
	bgcolor &= 0xf;
	color &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}