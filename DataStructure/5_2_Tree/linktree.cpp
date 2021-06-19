#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树链式存储

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// 数据域
	struct BiTNode* lchild, * rchild;	// 左右孩子指针
}BiTNode, * BiTree;

// n  个结点的二叉链表共有   n+1个空链域 ！！！！！


//// 三叉链表-方便找父结点
//typedef struct BiTNode {
//	ElemType data;						// 数据域
//	struct BiTNode* lchild, * rchild;	// 左右孩子指针
//	struct BiTNode* parent;				// 父结点指针
//}BiTNode, * BiTree;

void InitTree(BiTree& root) {
	root = NULL;
}

bool InsertRoot(BiTree& root) {
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
	root->lchild = NULL;
	root->rchild = NULL;
}

bool InsertTNode(BiTree& root, ElemType e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { e };
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
}

