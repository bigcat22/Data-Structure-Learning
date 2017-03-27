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

/* 求串长 */

/* 串连接 */

/* 求子串 */

/* 串插入 */

/* 串删除 */

/* 串替换 */

/* 串输出 */

