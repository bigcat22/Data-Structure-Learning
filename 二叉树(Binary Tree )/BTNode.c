#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#define MaxSize 20

void CreateBTNode(BTNode * &b, char * str)
{
	BTNode * St[MaxSize], *p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;	//二叉树一开始为空
	ch = str[j];
	while (ch != '\0')	//循环扫描str中每个字符
	{
		switch(ch)
		{
			case '(':		//开始处理左孩子节点
				top++;
				St[top] = p;
				k = 1;
				break;
			case ')':
				top--;
				break;
			case ',':		//开始处理右孩子节点
				k = 2;
				break;
			default:
				p = (BTNode *)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if ( b == NULL)	//若尚未建立根节点
					b = p;	//*p为二叉树的根节点
				else	//已建立二叉树根节点
				{
					switch(k)
					{
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
					}
				}
		}
		j++;
		ch = str[j];
	}
}

/* 查找节点FindNode的递归模型 */
BTNode * FindNode (BTNode *b, ElemType x)
{
	BTNode *p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}

/* 找孩子节点(左孩子和右孩子) */
BTNode* LchildNode (BTNode *p)
{
	return p->lchild;
}

BTNode* RchildNode (BTNode *p)
{
	return p->rchild;
}

/* 求二叉树的高度的递归模型 */
int BTNodeHeight (BTNode *b)
{
	int lchildh, rchildh;
	if (b == NULL)
		return (0);	//空树的高度为0
	else
	{
		lchildh = BTNodeHeight (b->lchild);	//求左子树的高度lchildh
		rchildh = BTNodeHeight (b->rchild);	//求右子树的高度rchildh
		return (lchildh>rchildh)?(lchildh+1):(rchildh+1);
	}
}

/* 输出二叉树的递归模型 */
void DispBTNode (BTNode *b)
{
	if (b != NULL)
	{
		printf ("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf ("(");
			DispBTNode (b->lchild);
			if (b->rchild != NULL)
				printf (",");
			DispBTNode (b->rchild);
			printf (")");
		}
	}
}

/* 递归遍历算法 */
//先序遍历
void PreOrder (BTNode *b)
{
	if (b != NULL)
	{
		printf ("%c", b->data);
		PreOrder (b->lchild);
		PreOrder (b->rchild);
	}
}
//中序遍历
void InOrder (BTNode *b)
{
	if (b != NULL)
	{
		PreOrder (b->lchild);
		printf ("%c", b->data);
		PreOrder (b->rchild);
	}
}
//后序遍历
void PostOrder (BTNode *b)
{
	if (b != NULL)
	{
		PreOrder (b->lchild);
		PreOrder (b->rchild);
		printf ("%c", b->data);
	}
}
