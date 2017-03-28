/* 串的链式存储结构 String by link */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 节点类型 */
typedef struct snode
{
	char data;
	struct snode * next;
}LiString;

/* 基本算法 */
/*1. StrAssign (s, cstr) ，将一个字符串常量 cstr赋给串s，即生成一个其值等于cstr的串s。尾插法： */
void StrAssign (LiString * &s, char cstr[])
{
	int i;
	LiString *r, *p;
	s = (LiString *)malloc(sizeof(LiString));
	r = s;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		p = (LiString *)malloc(sizeof(LiString));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

/*2. StrCopy(s, t) , 将串t复制给串s。采用尾插法建立复制后的链串s  */
void StrCopy (LiString * &s, LiString * t)
{
	LiString * p = t->next, * q, * r;
	s = (LiString *)malloc(sizeof(LiString));
	r = s;
	while (p != NULL)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
}

/* 3. StrEqual(s, t) 判断串相等：若两个串s与t相等则返回真；否则返回假 */
bool StrEqual(LiString *s, LiString *t)
{
	LiString * p = s->next,  * q = t->next;
	while (p != NULL && q != NULL && p->date == q->data)
	{
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL)
		return true;
	else
		return false;
}

/* 4. StrLength 求串长：返回s中字符个数 */
void StrLength (LiString * s)
{
	int count = 0;
	LiString * p = s->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

/* 5. Concat(s, t) 串连接：返回由两个串s和t连接在一起形成的新串。采用尾插法建立链串str并返回其地址 */
LiString * Concat (LiString *s, LiString *t)
{
	LiString * str, * p = s->next, *q, *r;
	str = (LiString *)malloc(sizeof(LiString));
	r = str;
	while (p != NULL)	// 将s的所有节点复制到str
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)	// 将t的所有节点复制到str
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

/* 6. SubStr(s, i, j) 求子串：返回串s从第i(1<=i<=StrLength(s))个字符开始的、由连续j个字符组成的子串 */
/* 参数不正确时返回一个空串。采用尾插法建立链串str并返回其地址 */
LiString * SubStr(LiString *s, int i, int j)
{
	int k;
	LiString * str, *p = s->next, *q, *r;
	str = (LiString *)malloc(sizeof(LiString));
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLength(s) || j < 0 || i+j-1 > StrLength(s))
		return str;
	for (k = 0; k < i-1; k++)
		p = p->next;
	for (k = 1; k <= j; k++)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

/* 7. InsStr(s1, i, s2) 将串s2插入到串s1的第i (1<=i<=StrLength(s)+1)个字符位置，即将s2的第1个字符作为 */
/* s1的第i个字符，s2的第2个字符作为s1的i+1个字符...返回产生的新串，参数不正确时返回空串。尾插法创建str，返回地址 */
LiString * InsStr (LiString * s, int i, LiString *t)
{
	int k;
	LiString * str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LiString *)malloc(sizeof(LiString));
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLength(s) + 1)
		return str;
	for (k = 1; k < i; k++)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r= q;
		p = p->next;
	}
	while (p1 != NULL)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{
		q= (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

/* 8. DelStr(s, i, j) 从串s中删去从第i (1<=i<=StrLength(s))个字符开始的长度为j的子串，并返回产生的新串 */
/* 参数不正确时返回一个空串。尾插法建立str并返回其地址 */
LiString * DelStr (LiString * s, int i, int j)
{
	int k;
	LiString * str, *p = s->next, *q, *r;
	str = (LiString *)malloc(sizeof(LiString));
	str->next = NULL;
	r = str;
	if (i <= 0 || i >StrLength(s) || j < 0 || i+j-1 > StrLength(s))
		return str;
	for (k = 0; k < i - 1; k++)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while (p != NULL)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

/* 9. RepStr(s, i, j, t) 在串s中，将第i （1<=i<=StrLength(s)) 个字符开始的j个字符构成的子串用串t替换 */
/* 并返回产生的新串，参数不正确时返回一个空串。采用尾插法建立str 返回其地址 */
LiString * RepStr (LiString * s, int i, int j, LiString * t)
{
	int k;
	LiString * str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LiString *)malloc(sizeof(LiString));
	str->next = NULL;
	r = str;
	if (i <= 0 || i >StrLength(s) || j < 0 || i+j-1 > StrLength(s))
		return str;
	for (k = 0; k < i-1; k++)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k<j; k++)
		p = p->next;
	while (p1 != NULL)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p1->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{
		q= (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

/* 10. DispStr(s) 输出串s的所有元素值 */
void DispStr (LiString * s)
{
	LiString * p = s->next;
	whiel (p != NULL)
	{
		printf ("%c", p->data);
		p = p->next;
	}
	printf ("\n");
}

/*3/28/2017 by bigcat22*/