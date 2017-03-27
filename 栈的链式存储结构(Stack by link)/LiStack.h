#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct linknode
{
	ElemType data;	//数据域
	struct linknode * next;	//指针域
}LiStack;	//定义链栈类型

/* 具体算法 */
/* 初始化栈 InitStack */
void InitStack (LiStack * &s)
{
	s = (LiStack *)malloc(sizeof(LiStack));
	s->next = NULL;
}

/* 销毁栈 DestroyStack */
void DestroyStack (LiStack * &s)
{
	LiStack * p = s, *q = s->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

/* 判断栈是否为空 StackEmpty */
bool StackEmpty (LiStack * s)
{
	return (s->next == NULL);
}

/* 进栈 Push */
void Push (LiStack * &s, ElemType e)
{
	LiStack * p;
	p = (LiStack *)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;	//插入p节点作为开始节点
	s-next = p;
}

/* 出栈 Pop */
bool Pop (LiStack * &s, ElemType &e)
{
	LiStack * p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;	//删除p节点
	free(p);	//释放p节点
	return ture;
}

/* 取栈顶元素 GetTop */
bool GetTop (LiStack *s, ElemType &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

/* 3/21/2017 by bigcat22 */