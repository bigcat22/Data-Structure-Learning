#include <stdio.h>
#include <stdlib.h>
// 线性表的链式存储结构
typedef int ElemType;

/*单链表结构*/
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkList;

/*双链表结构*/
/*
typedef struct DNode
{
	ElemType data;
	struct DNode * prior;
	struct DNode * next;
}DLinkList;
*/

//建立表结构
/* 头插法 */
/*
	void CreateListF (LinkList * &L, ElemType a[], int n)
	{
		LinkList *s;
		int i;
		L = (LinkList)malloc(sizeof(LinkList));
		L->next = NULL;
		for (i = 0; i < n; i++)
		{
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = a[i];
			s->next = L->next;
			L->next = s;
		}
	}
*/

/* 尾插法 */
void CreateListR (LinkList * &L, ElemType a[], int n)
{
	LinkList *s, *r;
	int i;
	L = (LinkList *)malloc(sizeof(LinkList));
	r = L;
	for (i = 0; i < n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = s;
		r = s;
	}
	r->next = NULL;
}
