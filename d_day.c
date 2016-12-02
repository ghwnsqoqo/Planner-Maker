#include "common.h"

void d_day();
void swap(int *a, int *b);	//d_day간 음수생성 방지를 위해 swap함수 구현
long d_totalday(int y, int m, int d);
void d_day()
{
	int sy, sm, sd;
	int fy, fm, fd;

	int dates;
	
	system("cls");
	today();
	calendar_p();

	printf("년 월 일 날짜 입력\n");
	printf("ex)1994 4 30 : ");
	scanf("%d %d %d", &fy, &fm, &fd);
	Sleep(1000);
	textcolor(14);	//노란색 글씨로 출력
	printf("첫번째 날짜 입력 완료!\n");
	textcolor(15);  //흰색 글씨로 출력
	Sleep(1000);

	printf("년 월 일 날짜 입력\n");
	printf("ex)1994 4 30 : ");
	scanf("%d %d %d", &sy, &sm, &sd);
	Sleep(1000);
	textcolor(14); //노란색 글씨로 출력
	printf("두번째 날짜 입력 완료!\n");
	
	Sleep(1000);
	//잘못기입한 사용자를 위한 swap함수를 이용한 조건문 작성
	if (fy > sy)
	{
		swap(&fy, &sy);
		swap(&fm, &sm);
		swap(&fd, &sd);
	}

	if (fy == sy)
	{
		if (fm > sm)
		{
			swap(&fy, &sy);
			swap(&fm, &sm);
			swap(&fd, &sd);
		}
		if (fm == sm)
		{
			if (fd > sd)
			{
				swap(&fy, &sy);
				swap(&fm, &sm);
				swap(&fd, &sd);
			}
		}
	}

	dates = d_totalday(sy, sm, sd) - d_totalday(fy, fm, fd);
	textcolor(12);	//빨간색 글씨로 출력
	printf("\n\n %d년 %d월 %d일 과 %d년 %d월 %d일 사이의 총 날짜 수 : %ld일", fy, fm, fd, sy, sm, sd, dates);
	textcolor(15);	//흰색 글씨로 복귀
	return 0;
}

long d_totalday(int y, int m, int d)
{
	int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;
	long total = 0L;

	total = (y - 1) * 365L + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;

	if (!(y % 4) && y % 100 || !(y % 400))
		months[1]++;
	for (i = 0; i<m - 1; i++)
		total += months[i];

	total += d;

	return total;
}


void swap(int* a, int* b) 
{
	int temp = *a; 
	*a = *b; 
	*b = temp;
}