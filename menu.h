#pragma once
char *smenu[] = { "\t\t\t\t\t1.����", "\t\t\t\t\t2.���� " };

char select_menu(void)
{
	char ch; //Ű���忡�� �Է¹��� ���ڿ��� ������ ���� ����.
	int i;
	calendarimg();
	Sleep(900);
	textcolor(14);
	printf("\n======================================================================================");
	Sleep(100);
	printf("\n======================================================================================");
	Sleep(200);
	textcolor(15);
	for (i = 0; i < sizeof(smenu) / sizeof(smenu[0]); i++)
	{
	
		printf("\n\n%s", smenu[i]);	//�޴����
		Sleep(200);
	}
	printf("\n\n\t\t\t\t�޴��� �������ּ��� : ");
	do 
	{
		ch = getchar();	//���ϴ� �޴� ����
		fflush(stdin); //���͸������� ���۸� �о��
	} while (ch<'1' || ch>'2'); //������ �޴��� 1~2 ���̰� �ƴҰ�� �ٽ� �Է�������
		return ch; //������ �޴��� �Լ��� ��������� �ǵ���;
		
}
