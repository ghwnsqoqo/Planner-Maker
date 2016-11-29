//스케쥴메뉴부분구현
#pragma
char *s_smenu[] = {"1. 일정입력", "2. 일정삭제", "3. 일정검색", "4. 일정출력", "5. 일정저장", "6. 나가기"};

char schedule_select_menu(void)
{
	char ch1; //키보드에서 입력받은 문자열을 저장할 변수 선언.
	int i;

	printf("\t\t\t\t");
	for (i = 0; i < sizeof(s_smenu) / sizeof(s_smenu[0]) / 2; i++)
	{
		printf("%s\t", s_smenu[i]);	//메뉴출력
		Sleep(200);
	}
	printf("\n\n");
	printf("\t\t\t\t");
	for (i = 3; i < sizeof(s_smenu) / sizeof(s_smenu[0]); i++)
	{
		printf("%s\t", s_smenu[i]);	//메뉴출력
		Sleep(200);
	}
	
	printf("\n\n\n\n\t\t\t\t\t메뉴를 선택해주세요 : ");
	do
	{
		ch1 = getchar();	//원하는 메뉴 선택
		fflush(stdin); //엔터를누르면 버퍼를 읽어옴
	} while (ch1<'1' || ch1>'6'); //선택한 메뉴가 1~6 사이가 아닐경우 다시 입력을받음
	return ch1; //선택한 메뉴의 함수의 결과값으로 되돌림;

}
