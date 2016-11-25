#include"common.h"

char* timeToString(struct tm *t);




void today()
{
	struct tm *t;
	time_t timer;

	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	printf("\t\t\t Today : ");
	printf("%s\n", timeToString(t));
	printf("\n\n");

	return 0;
}




char* timeToString(struct tm *t) 
{
	static char s[20];
	
	sprintf(s, "%04d-%02d-%02d %02d:%02d",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
		t->tm_hour, t->tm_min);

	return s;
}