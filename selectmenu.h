#pragma once
char *select_smenu[] = { "\t\t\t\t\t1.����", "\t\t\t\t\t2.D-Day", "\t\t\t\t\t3.������"};
void textcolor(int color_number);

char function_select_menu(void)
{
	char ch2; //Ű���忡�� �Է¹��� ���ڿ��� ������ ���� ����.
	int i;
	Sleep(900);
	textcolor(14);
	printf("\n===================================================================================================");
	Sleep(100);
	printf("\n==================================================================================================="); 
	Sleep(200);
	textcolor(15);

	for (i = 0; i < sizeof(select_smenu) / sizeof(select_smenu[0]); i++)
	{

		printf("\n\n\t%s", select_smenu[i]);	//�޴����
		Sleep(200);
	}
	printf("\n\n\t\t\t\t\t�޴��� �������ּ��� : ");
	do
	{
		ch2 = getchar();	//���ϴ� �޴� ����
		fflush(stdin); //���͸������� ���۸� �о��
	} while (ch2<'1' || ch2>'3'); //������ �޴��� 1~2 ���̰� �ƴҰ�� �ٽ� �Է�������
	return ch2; //������ �޴��� �Լ��� ��������� �ǵ���;

}
