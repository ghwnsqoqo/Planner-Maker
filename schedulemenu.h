//������޴��κб���
#pragma
char *s_smenu[] = {"1. �����Է�", "2. ��������", "3. �����˻�", "4. �������", "5. ��������", "6. ������"};

char schedule_select_menu(void)
{
	char ch1; //Ű���忡�� �Է¹��� ���ڿ��� ������ ���� ����.
	int i;

	printf("\t\t\t\t");
	for (i = 0; i < sizeof(s_smenu) / sizeof(s_smenu[0]) / 2; i++)
	{
		printf("%s\t", s_smenu[i]);	//�޴����
		Sleep(200);
	}
	printf("\n\n");
	printf("\t\t\t\t");
	for (i = 3; i < sizeof(s_smenu) / sizeof(s_smenu[0]); i++)
	{
		printf("%s\t", s_smenu[i]);	//�޴����
		Sleep(200);
	}
	
	printf("\n\n\n\n\t\t\t\t\t�޴��� �������ּ��� : ");
	do
	{
		ch1 = getchar();	//���ϴ� �޴� ����
		fflush(stdin); //���͸������� ���۸� �о��
	} while (ch1<'1' || ch1>'6'); //������ �޴��� 1~6 ���̰� �ƴҰ�� �ٽ� �Է�������
	return ch1; //������ �޴��� �Լ��� ��������� �ǵ���;

}
