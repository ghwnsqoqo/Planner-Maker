#include"common.h"

char* timeToString(struct tm *t);




void today()
{
	struct tm *t;
	time_t timer;

	timer = time(NULL);    // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

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