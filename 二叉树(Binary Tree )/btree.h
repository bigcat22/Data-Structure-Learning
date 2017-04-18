/* 二叉树的的类型定义 */
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BTNode;