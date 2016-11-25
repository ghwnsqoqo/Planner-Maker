#include "common.h"
#define leapyear(year) ((year)%4==0 && ((year)%100!=0||(year)%400==0))	//�����Ǵܸ�ũ��
void SetConsoleTextColor(int bgcolor, int color);	//console �۾������� �ٲٴ� �Լ�
void memo();	//���� ��� �Լ�
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

void calendar()
{
	system("cls");
	today();
	int year, month = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int lastyear, day, i;
	
	FILE * fp = fopen("calendar.txt", "wt"); //calendar.txt������ϱ����ؿ����Ѵ�.

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
			printf("\n\t");
			SetConsoleTextColor(0x0, 0xe);	//������۾��� �ٲ۴�.
			printf("\t\t%d�� %d��\n", year, month);
			SetConsoleTextColor(0x0, 0xc);	//�������۾��ιٲ۴�.
			printf("\n   ��");
			SetConsoleTextColor(0x0, 0xf);	//����۾��� ����
			printf("\t  ��\t  ȭ\t  ��\t  ��\t  ��");
			SetConsoleTextColor(0x0, 0x9);	//�Ķ����۾��� �ٲ۴�.
			printf("\t  ��");
						
			
			SetConsoleTextColor(0x0, 0xf);	//�Ͼ���۾��κ���
			printf("\n  ===================================================");

			fprintf(fp, "\n			%d��%d��\n", year, month);
			fprintf(fp, "\n��\t��ȭ\t��\t��\t��\t��");

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
					//������� ��� �Ķ������� ����Ѵ�.
					if ((i + day) % 7 == 6)	SetConsoleTextColor(0x0, 0x9);
					//�Ͽ����� ��� ���������� ����Ѵ�.
					if ((i + day) % 7 == 0) SetConsoleTextColor(0x0, 0xc);	printf("%4d\t", i + 1);
					//����۾��� ����
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
	printf("����������� : ");
	scanf("%d",&day);
}


