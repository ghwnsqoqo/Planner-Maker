#include "common.h"
#include "selectmenu.h"
#define leapyear(year) ((year)%4==0 && ((year)%100!=0||(year)%400==0))	//�����Ǵܸ�ũ��

void textcolor(int color_number)	//���ڻ� ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void textcolor(int color_number);

void Exit();
void d_day();
void memo_menu();
void calendar_p();	//�޷¸������Լ�

void calendarimg()	
{
	int z;
	for (z = 0; z <= 15; z++)
	{
		textcolor(z);
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		printf("��������������������������������������������\n");
		Sleep(100);
		system("cls");
	}
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");

}

int year, month = 0;
int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int lastyear, day, i;

void calendar()	//�޷������� �Է¹޴��Լ�
{
	system("mode con:cols=100 lines=30");
	system("cls");
	today();

	
	printf("���(Ҵ)�� �޷��� ����Ͻðڽ��ϱ� ? ");
	scanf("%d", &year);
	printf("���(��)�� �޷��� ����Ͻðڽ��ϱ� ? ");
	scanf("%d", &month);
	printf("�޷��� �������Դϴ�. ��ø���ٷ��ּ���");
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

//�޴��κ�����	
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
	
	if (month == 2 && leapyear(year))	//�����Ǵ�
		totalday[2] = 29;

	lastyear = year - 1;
	{
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;

		for (i = 1; i < month; i++)
		{
			day += totalday[i];
			day %= 7;
		}
		//console�� ���
		printf("\n\t\t\t\t");
		textcolor(14);	//������۾��� �ٲ۴�.
		printf("\t\t%d�� %d��\n\n", year, month);
		textcolor(12);	//�������۾��ιٲ۴�.
		printf("\n\t\t\t  ��");
		textcolor(15);	//����۾��� ����
		printf("\t  ��\t  ȭ\t  ��\t  ��\t  ��");
		textcolor(9);	//�Ķ����۾��� �ٲ۴�.
		printf("\t  ��");


		textcolor(14);	//������۾��� �ٲ۴�.
		printf("\n\t\t\t  ===================================================");

		textcolor(15);	//�Ͼ���۾��κ���
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
				//������� ��� �Ķ������� ����Ѵ�.
				if ((i + day) % 7 == 6)	textcolor(9);
				//�Ͽ����� ��� ���������� ����Ѵ�.
				if ((i + day) % 7 == 0) textcolor(12);	printf("%4d\t", i + 1);
				//����۾��� ����
				textcolor(15);
			}
		}
	}
	printf("\n\n");
	
}