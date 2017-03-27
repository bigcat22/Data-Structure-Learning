/* 队的顺序存储结构 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 20
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;	//对头和队尾指针
} SqQueue;

/* 基本算法实现 */
/* 初始化队 */
void InitQueue (SqQueue * &q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

/* 销毁队 */
void DestroyQueue (SqQueue * &q)
{
	free(q);
}

/* 判断队列是否为空 */
bool QueueEmpty (SqQueue * q)
{
	return (q->front == q->rear);
}

/* 进队列 */
bool enQueue (SqQueue * &q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->reat] = e;	
	return true;
}

/* 出队列 */
bool deQueue (SqQueue * &q, ElemType &e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

/* 3/22/2017 by bigcat22 */