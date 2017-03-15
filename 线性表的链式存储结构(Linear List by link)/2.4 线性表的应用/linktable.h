#define MaxCol 10 					//最大列数
typedef int ElemType;

/* 单链表的数据节点类型定义 */
typedef struct Node1				//定义数据节点类型
{
	ElemType data[MaxCol];		//存放一行的数据
	struct Node1 * next;				//指向后继数据节点
} DList;										//行节点类型

/* 每个表的行数和列数 */
typedef struct Node2
{
	int Row, Col;							//行数和列数
	DList * next;							//指向第一个数据节点
} HList;										//头结点类型

/* 函数声明 */
/* 建表 */
void CreateTable (HList * &h);		

/* 销毁单链表 */
void DestoryTable (HList * &h);

/* 输出单链表 */
void DispTable (HList *h);

/* 表示连接运算 */
void LinkTable (HList *h1, HList *h2, HList * &h);