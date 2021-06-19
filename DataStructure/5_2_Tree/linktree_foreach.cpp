#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树的先序、中序、后序遍历

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// 数据域
	struct BiTNode* lchild, * rchild;	// 左右孩子指针
}BiTNode, * BiTree;


void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);				// 访问根结点
		PreOrder(T->lchild);	// 递归遍历左子树
		PreOrder(T->rchild);	// 递归遍历右子树
	}
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);		// 递归遍历左子树
		visit(T);				// 访问根结点
		InOrder(T->rchild);		// 递归遍历右子树
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);	// 递归遍历左子树
		PostOrder(T->rchild);	// 递归遍历右子树
		visit(T);				// 访问根结点
	}
}