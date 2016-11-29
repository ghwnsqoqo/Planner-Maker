#include"common.h"
#include"schedulemenu.h"
//일정입력부분구현

//구조체 정의

typedef struct schedule{ //아래 node 구조체 내의 변수중 하나
	char s_name[20];	//스케줄 이름
	char s_memo[20];	//스케줄 내용
}schedule;

typedef struct node //구조체를 노드로 갖는 자기 참조 구조체 선언
{
	struct schedule data;			//스케줄이름, 내용 데이터
	struct node *next;	//링크(구조체node의 주소를 저장할 포인터 변수)
}node;

node *Createnode(void);	//node하나를 만드는 함수. insert함수의 두번째 인자로 전달하기위해
void Insert(node **phead, node *newnode);	//연결리스트의 마지막 node에 newnode를 연결시키는 함수
node *search(node *phead);		//입력한 이름을 가진 node를 찾는 함수
void Delete(node **phead, node *remove);	//remove노드를 search함수로 찾아서 인자로 전달한다
void Display(node *head);		//연결리스트의 모든 내용을 출력하는 함수
void writefile(node *phead);	//연결리스트의 내용을 저장하는 함수 폴더안에 Schedule.txt라는 파일로 저장이 되도록했다.
void Exit();

void memo_menu()
{	
	system("cls");
	today();
	calendar_p();

	node *head = NULL;	//헤드 포인터 선언
	int num = 0;
	int in = 0;
	node *se;	   //switch 문의 case 3: 에서 찾은 노드의 주소값을 임시로 저장하기 위해서
	int i = 0;

	FILE *des = fopen("Schedule.txt", "rt");	//파일의 내용을 기초로 연결리스트 구성을 위해 입력스트림 생성

	if (des == NULL)	//입력스트림의 생성을 확인
	{
		printf("파일 읽기 실패!\n");
		return -1;	//비정상적인 종료를 의미
	}
	//구현한 메인메뉴헤더 불러오기
	
	while (1)
	{
		char ch1 = schedule_select_menu();
		switch (ch1)
		{
		case'1': Insert(&head, Createnode());
				 Sleep(1000); 
				 system("cls");
				 today();
				 calendar_p();
				 break;
		case'2': Delete(&head, search(head));
				 Sleep(1000);
				 system("cls");
				 today();
				 calendar_p();
				 break;
		case'3': se = search(head);
			if (se != NULL)
				{
					printf("일정명 : %s\n", se->data.s_name);
					printf("일정내용 : %s\n", se->data.s_memo);
				}
				 else
				 {
					 printf("검색할 내용이 없습니다 !\n");
				 }
					Sleep(1000);
					system("cls");
					today();
					calendar_p();
		case'4': Display(head);	
				 Sleep(1000);
				 system("cls");
				 today();
				 calendar_p();
				 break;
		case'5': writefile(head);
			printf("Scedule.txt파일로 저장이 완료되었습니다.\n"); 
			Sleep(1000);
			system("cls");
			today();
			calendar_p();
			continue;
		case'6': Exit();	exit(0);
		}
	}
}

void Insert(node **phead, node *newnode)
{
	node *ptr = *phead;
	node *p;
	if (*phead == NULL)	//연결리스트에 아무 내용이 없을때
	{
		(*phead) = newnode;
		newnode->next = NULL;
	}
	else
	{
		while (ptr != NULL)	//마지막 노드의 주소값을 찾는 반복문
		{
			p = ptr;
			ptr = ptr->next;
		}
		ptr = newnode;
		p->next = ptr;	//연결리스트의 끝에 newnode를 연결
	}
}
void Delete(node **phead, node*remove)
{
	node *ptr = *phead;
	node *p;
	if (ptr == NULL)
		return;
	else
	{
		if (*phead == remove)		//첫번째 노드를 삭제할때
		{
			*phead = (*phead)->next;
			free(remove);
		}
		else
		{
			while (ptr != NULL)
			{
				if (ptr == remove)
				{
					p->next = remove->next;	//remove노드를 연결리스트에서 제외
					free(remove);
					return;
				}
				p = ptr;
				ptr = ptr->next;
			}
		}
	}
}

node * search(node*phead)
{
	node *ptr = phead;
	schedule el;
	printf("일정명 입력:");	scanf("%s", el.s_name);
	while (ptr != NULL)
	{
		if (!strcmp(ptr->data.s_name, el.s_name))	//각 노드의 데이터 내의 이름과 찾을 이름을 비교
			return ptr;	//찾을 이름을 가진 노드의 주소값을 반환
		ptr = ptr->next;
	}
	return NULL;
}
void Display(node*head)
{
	int i = 1;
	node *p = head;
	while (p != NULL)
	{
		printf("%d번째\n", i);
		printf("일정명:%s\n", (p->data).s_name);
		printf("일정내용:%s\n\n", (p->data).s_memo);
		p = p->next;
		i++;
	}
}

node *Createnode(void)
{
	node *newnode = (node*)malloc(sizeof(node));		//새로운 노드 생성
	printf("일정명 입력:");	scanf("%s", (newnode->data).s_name);	//일정명 입력
	printf("일정내용 입력:");	scanf("%s", (newnode->data).s_memo);	//일정내용 입력
	newnode->next = NULL;
	return newnode;	//newnode 의 주소값을 반환
}

void writefile(node *phead)
{
	node *ptr = phead;
	int i = '1';
	FILE *des = fopen("Schedule.txt", "wt");	//출력 스트림 형성

	if (ptr == NULL)
		return;
	else
	{
		while (ptr != NULL)
		{
			fputc(i, des); fputs("번째\n", des);
			fputs("일정명:", des); fputs(ptr->data.s_name, des); fputs("\n", des);
			fputs("일정내용:", des); fputs(ptr->data.s_memo, des); fputs("\n", des);
			ptr = ptr->next;
			i++;
		}
	}
	fclose(des);
	return;

}