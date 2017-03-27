/* 队的链式存储结构 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;

/* 链队结构 */
typedef struct qnode
{
	ElemType data;
	struct qnode * next;
}QNode;

/* 链队节点类型 */
typedef struct
{
	QNode * front;
	QNode * rear;
}LiQueue;

/* 基本算法 */
/* 初始化队列 */
void InitQueue (LiQueue * &q)
{
	q = (LiQueue *)malloc(sizeof(LiQueue));
	q->front = q->rear = NULL;
}

/* 销毁队列 */
void DestoryQueue (LiQueue * &q)
{
	QNode * p = q->front, *r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);
}

/* 判断队列是否为空 */
bool QueueEmpty (LiQueue * q)
{
	return (q->rear == NULL):
}

/* 进队列 */
void enQueue (LiQueue * &q, ElemType e)
{
	QNode * p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)	//若链队为空，则新节点既是队首又是队尾
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;	//将 *p 节点链到队尾，并将rear指向它
		q->rear = p;
	}
}

/* 出队列 */
bool deQueue (LiQueue * &q, ElemType &e)
{
	QNode * t;
	if (q->rear == NULL)	//队列为空
		return false;
	t = q->front;	//t指向第一个数据节点
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}

/* 3/27/2017 by bigcat22 */