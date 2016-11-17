#pragma once
char *smenu[] = { "1.menuname", "2.menuname ", "3.menuname" };

char select_menu(void)
{
	char ch; //키보드에서 입력받은 문자열을 저장할 변수 선언.
	int i;
	printf("\nTITlE 작성");
	printf("\n-------------");
	for (i = 0; i < sizeof(smenu) / sizeof(smenu[0]); i++)
	{
		printf("\n%s", smenu[i]);	//메뉴출력
	}
	printf("\n\n 메뉴를 선택해주세요 : ");
	do 
	{
		ch = getchar();	//원하는 메뉴 선택
		fflush(stdin); //엔터를누르면 버퍼를 읽어옴
	} while (ch<'1' || ch>'3'); //선택한 메뉴가 1~3 사이가 아닐경우 다시 입력을받음
		return ch; //선택한 ㅔ뉴의 함수의 결과값으로 되돌림;

}
