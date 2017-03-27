/* 环形队列 Cycle SqQueue */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 20
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front;
	int rear;
}cSqQueue;

/* 初始化队列 */
void InitQueue (cSqQueue * &q)
{
	q = (cSqQueue *)malloc(sizeof(cSqQueue));
	q->front = q->rear = 0;
}

/* 销毁队列 */
void DestroyQueue (cSqQueue * &q)
{
	free (q);
}

/* 判断队列是否为空 */
bool QueueEmpty (cSqQueue * q)
{
	return (q->front == q->rear);
}

/* 进队列 */
bool enQueue (cSqQueue * &q, ElemType e)
{
	if ((q->rear +1) % MaxSize == q->front)
		return false;
	q->rear = (q->rear +1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

/* 出队列 */
bool deQueue (cSqQueue * &q, ElemType &e)
{
	if (q->front == q->rear)
		return false;
	q->front = (q->rear+1) % MaxSize;
	e = q->data[q->front];
	return true;
}

/* 3/27/2017 by bigcat22 */