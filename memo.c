#include"common.h"
#include"schedulemenu.h"
//�����Էºκб���

//����ü ����

typedef struct schedule{ //�Ʒ� node ����ü ���� ������ �ϳ�
	char s_name[20];	//������ �̸�
	char s_memo[20];	//������ ����
}schedule;

typedef struct node //����ü�� ���� ���� �ڱ� ���� ����ü ����
{
	struct schedule data;			//�������̸�, ���� ������
	struct node *next;	//��ũ(����ünode�� �ּҸ� ������ ������ ����)
}node;

node *Createnode(void);	//node�ϳ��� ����� �Լ�. insert�Լ��� �ι�° ���ڷ� �����ϱ�����
void Insert(node **phead, node *newnode);	//���Ḯ��Ʈ�� ������ node�� newnode�� �����Ű�� �Լ�
node *search(node *phead);		//�Է��� �̸��� ���� node�� ã�� �Լ�
void Delete(node **phead, node *remove);	//remove��带 search�Լ��� ã�Ƽ� ���ڷ� �����Ѵ�
void Display(node *head);		//���Ḯ��Ʈ�� ��� ������ ����ϴ� �Լ�
void writefile(node *phead);	//���Ḯ��Ʈ�� ������ �����ϴ� �Լ� �����ȿ� Schedule.txt��� ���Ϸ� ������ �ǵ����ߴ�.
void Exit();

void memo_menu()
{	
	system("cls");
	today();
	calendar_p();

	node *head = NULL;	//��� ������ ����
	int num = 0;
	int in = 0;
	node *se;	   //switch ���� case 3: ���� ã�� ����� �ּҰ��� �ӽ÷� �����ϱ� ���ؼ�
	int i = 0;

	FILE *des = fopen("Schedule.txt", "rt");	//������ ������ ���ʷ� ���Ḯ��Ʈ ������ ���� �Է½�Ʈ�� ����

	if (des == NULL)	//�Է½�Ʈ���� ������ Ȯ��
	{
		printf("���� �б� ����!\n");
		return -1;	//���������� ���Ḧ �ǹ�
	}
	//������ ���θ޴���� �ҷ�����
	
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
					printf("������ : %s\n", se->data.s_name);
					printf("�������� : %s\n", se->data.s_memo);
				}
				 else
				 {
					 printf("�˻��� ������ �����ϴ� !\n");
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
			printf("Scedule.txt���Ϸ� ������ �Ϸ�Ǿ����ϴ�.\n"); 
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
	if (*phead == NULL)	//���Ḯ��Ʈ�� �ƹ� ������ ������
	{
		(*phead) = newnode;
		newnode->next = NULL;
	}
	else
	{
		while (ptr != NULL)	//������ ����� �ּҰ��� ã�� �ݺ���
		{
			p = ptr;
			ptr = ptr->next;
		}
		ptr = newnode;
		p->next = ptr;	//���Ḯ��Ʈ�� ���� newnode�� ����
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
		if (*phead == remove)		//ù��° ��带 �����Ҷ�
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
					p->next = remove->next;	//remove��带 ���Ḯ��Ʈ���� ����
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
	printf("������ �Է�:");	scanf("%s", el.s_name);
	while (ptr != NULL)
	{
		if (!strcmp(ptr->data.s_name, el.s_name))	//�� ����� ������ ���� �̸��� ã�� �̸��� ��
			return ptr;	//ã�� �̸��� ���� ����� �ּҰ��� ��ȯ
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
		printf("%d��°\n", i);
		printf("������:%s\n", (p->data).s_name);
		printf("��������:%s\n\n", (p->data).s_memo);
		p = p->next;
		i++;
	}
}

node *Createnode(void)
{
	node *newnode = (node*)malloc(sizeof(node));		//���ο� ��� ����
	printf("������ �Է�:");	scanf("%s", (newnode->data).s_name);	//������ �Է�
	printf("�������� �Է�:");	scanf("%s", (newnode->data).s_memo);	//�������� �Է�
	newnode->next = NULL;
	return newnode;	//newnode �� �ּҰ��� ��ȯ
}

void writefile(node *phead)
{
	node *ptr = phead;
	int i = '1';
	FILE *des = fopen("Schedule.txt", "wt");	//��� ��Ʈ�� ����

	if (ptr == NULL)
		return;
	else
	{
		while (ptr != NULL)
		{
			fputc(i, des); fputs("��°\n", des);
			fputs("������:", des); fputs(ptr->data.s_name, des); fputs("\n", des);
			fputs("��������:", des); fputs(ptr->data.s_memo, des); fputs("\n", des);
			ptr = ptr->next;
			i++;
		}
	}
	fclose(des);
	return;

}