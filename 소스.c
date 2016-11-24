#include <stdio.h>
#include <windows.h>   // �ֻܼ������ٲٱ����ؼ�����
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //����������ũ��
// Console �۾��������ٲٴ��Լ�
void SetConsoleTextColor(int bgcolor, int color);





//FILE * fp = fopen(".txt", "wt");  txt���� �����Ŀ� �����ϱ�




int main(void)
{
	int year, month = 0;
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int lastyear, day, i;
	FILE * fp = fopen("output5.txt", "wt"); //output5.txt������ϱ����ؿ����Ѵ�.

	printf("����Ǵ޷�������Ͻðڽ��ϱ�?: ");
	scanf("%d", &year);
	printf("����Ǵ޷�������Ͻðڽ��ϱ�?: ");
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
		// console�����
		printf("\n           ");
		SetConsoleTextColor(0x0, 0xe);              // ������۾��ιٲ۴�.
		printf("%d��%d��\n", year, month);
		SetConsoleTextColor(0x0, 0xc);              // �������۾��ιٲ۴�.
		printf("\n  ��");
		SetConsoleTextColor(0x0, 0xf);              // ����۾��κ���
		printf("  ��  ȭ  ��  ��  �� ");
		SetConsoleTextColor(0x0, 0x9);              // �Ķ����۾��ιٲ۴�.
		printf(" ��");
		SetConsoleTextColor(0x0, 0xf);              // ����۾��κ���

													// ���Ͽ����
		fprintf(fp, "\n           %d��%d��\n", year, month);
		fprintf(fp, "\n  �Ͽ�ȭ�������");

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
				// ������ϰ�쿡���Ķ�����������Ѵ�
				if ((i + day) % 7 == 6)   SetConsoleTextColor(0x0, 0x9);
				// �Ͽ����ϰ�쿡�»�������������Ѵ�.
				if ((i + day) % 7 == 0)   SetConsoleTextColor(0x0, 0xc);printf("%4d", i + 1);
				// ��������۾��κ��ͽ�Ų��.
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


// Console �۾��������ٲٴ��Լ�
void SetConsoleTextColor(int bgcolor, int color)
{
	bgcolor &= 0xf;
	color &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}