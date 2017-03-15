/* fun.c -- 支持连接的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

#ifndef MaxCol
	#define MaxCol 10 				//最大列数
#endif

/* 创建单链表，采用尾插法。用户先输入表的行数和列数，然后输入各行的数据 */
void CreateTable (HList * &h)
{
	int i, j;
	DList *r, *s;
	h = (HList *)malloc(sizeof(HList));		//创建头结点
	printf ("表的行数，列数：");
	scanf ("%d %d", &h->Row, &h->Col);		//输入表的行数和列数
	for (i = 0; i < h->Row; i++)			//输入所有行的数据
	{
		printf ("第 %d 行:", i+1);
		s = (DList *)malloc(sizeof(DList));	//创建数据节点
		for (j = 0; j < h->Col; j++)		//输入一行的数据
			scanf ("%d", &s->Col; j++);
		if (h->next == NULL)			//插入第一个数据节点
			h->next = s;										
		else					//插入其他数据节点
			r->next = s;			//将*s插入到*r节点之后
		r = s;					//r始终指向尾节点
	}
	r->next = NULL;					//尾节点的next域置空
}
