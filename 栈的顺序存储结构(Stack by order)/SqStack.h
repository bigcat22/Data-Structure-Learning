/* 栈的顺序存储结构 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 栈的最大空间，预设为20 */
#define MaxSize 20
/* 自定义数据类型和栈结构 */
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;	//栈顶指针
}SqStack;

/* 初始化栈 */
void InitStack (SqStack * &s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;	//栈顶指针置为-1
}

/* 销毁栈 */
void DestoryStack (SqStack * &s)
{
	free (s);
}

/* 判断栈是否为空 */
bool StackEmpty (SqStack * s)
{
	return (s->top == -1);
}

/* 进栈 */
bool Push (SqList * &s, ElemType e)
{
	if (s->top == MaxSize-1)	//栈上溢出
		return false
	s->top++;	//栈顶指针+1
	s->data[s->top] = e;	//元素e放在栈顶指针处
	return true;
}

/* 出栈 */
bool Pop (SqList * &s, ElemType &e)
{
	if (s->top == -1)	//栈下溢出	
	return false;
	e = s->data[s->top];	//取栈顶元素	
	s->top--;		//栈顶指针减1
	return ture;
}

/* 取栈顶元素 */
bool GetTop (SqStack * s, ElemType &e)
{
	if (s->top == -1)	//栈下溢出
		return false;
	e = s->data[s->top];	//取栈顶元素
	return ture;
}

/* 3/20/2017 by bigcat22 */
