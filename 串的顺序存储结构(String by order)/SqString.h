/* 串的顺序存储结构 SqString */
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 20

/* 非紧缩格式的顺序串类型定义 */
typedef struct
{
	char data[MaxSize];	//存放字符串
	int length;	//存放串长
}SqString;	//顺序串类型

/* 基本算法 */
/* 串赋值 */
void StrAssign (SqString &s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

/* 串复制 */
void StrCopy (SqString &s, SqString t)
{
	int i;
	for (i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

/* 判断串相等 */
bool StrEqual (SqString s, SqString t)
{
	bool same = true;
	int i;
	if (s.length != t.length)
		same = false;
	else
		for (i = 0; i < s.length; i++)
			if (s.data[i] != t.data[i])
			{
				same = false;
				break;
			}
	return same;
}

/* 求串长 */
int StrLength (SqString s)
{
	return s.length;
}

/* 串连接 */
SqString Concat (SqString s, SqString t)
{
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
		str.data[i] = s.data[i];
	for (i = 0; i < t.length; i++)
		str.data[s.length+i] = t.data[i];
}

/* 求子串 */
SqString SubStr (SqString s, int i, int j)
{
	SqString str;
	int k;
	str.length = 0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;
	for (k=i-1; k<i+j-1; k++)
		str.data[k-i+1] = s[k];
	str.length = j;
	return str;
}

/* 串插入 */
SqString InsStr (SqString s1, int i ,SqString s2)
{
	int j;
	SqString str;
	str.length = 0;
	if (i<=0 || i>s1.length+1)
		return str;
	for (j=0; j<i-1; j++)
		str.data[j] = s1.data[j];
	for (j=0; j<s2.length; j++)
		str.data[i+j-1] = s2.data[j];
	for (j=i-1; j<s1.length; j++)
		str.data[s2.legth+j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

/* 串删除 */
SqString DelStr (SqString s, int i, int j)
{
	int k;
	SqString str;
	if (i <= 0 || i > s.length || i+j > s.length+1)
		return str;
	for (k = 0; k < i-1; k++)
		str.data[k] = s.data[k];
	for (k = i+j-1; k < s.length; k++)
		str.data[k-j] = s.data[k];
	str.length = s.length - j;
	return str;
}

/* 串替换 */
SqString RepStr (SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i+j > s.length +1)
		return str;
	for (k = 0; k<i-1; k++)
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++)
		str.data[i+k-1] = t.data[k];
	for (k = i+j-1; k < s.length; k++)
		str.data[t.length+k-j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}

/* 串输出 */
void DispStr (SqString s)
{
	int i;
	if (s.lengt > 0)
	{
		for (i = 0; i < s.length; i++)
			printf ("%c", s.data[i]);
		printf ("\n");
	}
}

/* 3/28/2017 by bigcat22 */
