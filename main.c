#include "common.h"
#include "menu.h"

void calendar();
void Exit();


void main()
{
	//콘솔창 크기 설정 cols = 가로 , lines = 세로
	system("mode con:cols=86 lines=30");

	//구현한 메인메뉴헤더 불러오기
		while (1)
	{
		char ch = main_select_menu();
		switch (ch)
		{
		case'1': calendar();	break;
		case'2': Exit();	exit(0);
		}
	}
}
