#include "stdio.h";
#include "stdlib.h";
#include "io.h";
#include "math.h";
#include "time.h";
#define OK 1;
#define ERROR 0;
#define TRUE 1;
#define FALSE 0;

typedef int Status;	  /*Status �Ǻ��������ͣ���ֵ�Ǻ������״̬*/
typedef int ElemType; /*ElemType���͸���ʵ���������*/

/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node *LinkList;

/*
	��ʼ���������Ա�L�Ѵ��� 1<=i<=ListLength(L)
	@return����e����L�е�i������Ԫ�ص�ֵ
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	/*����ָ��p*/
	LinkList p;
	/*��ָ��ָ������L�ĵ�һ���ڵ�*/
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		/*pָ����һ���ڵ�*/
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		/*��i��ָ�벻����*/
		return ERROR;
	}
	*e = p->data;
	return OK;
}
/*
�����ṹ������L�е�i���ڵ�λ��֮ǰ�����µ�Ԫ��e��L�ĳ��ȼ�1
*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	//Ѱ�ҵ�i-1�����
	while (p && j < i)
	{
		p = p->next;
		++j
	}
	if (!p || j > i)
		return ERROR;
	//�����½��
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//ɾ��������
Status ListDelete(LinkList *L, int i, ElemType e)
{
	int j;
	j = 1;
	LinkList p, q;
	p = *L;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
	{
		return OK;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data
			 free(q);
	return OK;
}

//�������������
//�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
//ͷ�巨
void CreateListHead(LinkList *L, int n)
{
	LinkList P;
	int i;
	//��ʼ�����������
	srand(time(0));
	//����һ����ͷ���ĵ�����
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		//�����ͷ
		(*L)->next = p;
	}
}

// β�巨
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0)); //��ʼ���������
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (int i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = null;
}

// �����������ɾ�� 
Status ClearList(LinkList *L){
	LinkList p,q;
	p=(*L)->next;
	while(p){
		q=p->next;
		free(p);
		p=q;

	}
	(*L)->next=NULL;
	return OK;
}