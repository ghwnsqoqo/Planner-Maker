#include "common.h"

void d_day()

{
	struct tm beg = { 0 };
	struct tm end = { 0 };
	int ay, am, ad;
	int zy, zm, zd;
	int d;

	printf("시작일을 입력하세요(년 월 일) ");
	scanf("%d %d %d", &ay, &am, &ad);
	printf("종료일을 입력하세요(년 월 일) ");
	scanf("%d %d %d", &zy, &zm, &zd);
	beg.tm_mday = ad;
	beg.tm_mon = am - 1;
	beg.tm_year = ay - 1900;
	end.tm_mday = zd;
	end.tm_mon = zm - 1;
	end.tm_year = zy - 1900;
	time_t x = mktime(&beg);
	time_t y = mktime(&end);

	if (x != (time_t)(-1) && y != (time_t)(-1))
	{

		double difference = difftime(y, x) / (60 * 60 * 24);
		printf("입력\n%d %d %d\n", ay, am, ad);
		printf("%d %d %d\n", zy, zm, zd);
		printf("출력\n");

		if (difference > 0)

			printf("D+%.0lf\n", difference);

		else if (difference == 0)

			printf("D-day\n");
		else

			printf("D%.0lf\n", difference);

	}
}