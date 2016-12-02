#include "common.h"

void d_day();
void swap(int *a, int *b);	//d_day�� �������� ������ ���� swap�Լ� ����
long d_totalday(int y, int m, int d);
void d_day()
{
	int sy, sm, sd;
	int fy, fm, fd;

	int dates;
	
	system("cls");
	today();
	calendar_p();

	printf("�� �� �� ��¥ �Է�\n");
	printf("ex)1994 4 30 : ");
	scanf("%d %d %d", &fy, &fm, &fd);
	Sleep(1000);
	textcolor(14);	//����� �۾��� ���
	printf("ù��° ��¥ �Է� �Ϸ�!\n");
	textcolor(15);  //��� �۾��� ���
	Sleep(1000);

	printf("�� �� �� ��¥ �Է�\n");
	printf("ex)1994 4 30 : ");
	scanf("%d %d %d", &sy, &sm, &sd);
	Sleep(1000);
	textcolor(14); //����� �۾��� ���
	printf("�ι�° ��¥ �Է� �Ϸ�!\n");
	
	Sleep(1000);
	//�߸������� ����ڸ� ���� swap�Լ��� �̿��� ���ǹ� �ۼ�
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
	textcolor(12);	//������ �۾��� ���
	printf("\n\n %d�� %d�� %d�� �� %d�� %d�� %d�� ������ �� ��¥ �� : %ld��", fy, fm, fd, sy, sm, sd, dates);
	textcolor(15);	//��� �۾��� ����
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