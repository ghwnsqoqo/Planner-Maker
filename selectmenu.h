#pragma once
char *select_smenu[] = { "\t\t\t\t\t1.일정", "\t\t\t\t\t2.D-Day", "\t\t\t\t\t3.나가기"};
void textcolor(int color_number);

char function_select_menu(void)
{
	char ch2; //키보드에서 입력받은 문자열을 저장할 변수 선언.
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

		printf("\n\n\t%s", select_smenu[i]);	//메뉴출력
		Sleep(200);
	}
	printf("\n\n\t\t\t\t\t메뉴를 선택해주세요 : ");
	do
	{
		ch2 = getchar();	//원하는 메뉴 선택
		fflush(stdin); //엔터를누르면 버퍼를 읽어옴
	} while (ch2<'1' || ch2>'3'); //선택한 메뉴가 1~2 사이가 아닐경우 다시 입력을받음
	return ch2; //선택한 메뉴의 함수의 결과값으로 되돌림;

}
