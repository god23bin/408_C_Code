#define _CRT_SECURE_NO_WARNINGS 1

// 平衡二叉树

#include <stdio.h>
#include <stdlib.h>


// 平衡二叉树结点
typedef struct AVLNode {
	int key;			// 数据域
	int balance;		// 平衡因子
	struct AVLNode* lchild, * rchild;
}AVLNode, * AVLTree;

// 插入
// 插入后如何保持平衡?
// 从插入点往回找到第一个不平衡结点,调整以该结点为根的子树,"最小不平衡子树"

// 如何调整最小不平衡子树

// LL
// 右旋操作
// f是爹,p为左孩子,gf为f他爹
// f->lchild = p->rchild;
// p->rchild = f;
// gf->lchild/rchild = p;

// RR
// 左旋操作
// f->rchild = p->lchild;
// p->lchild = f;
// gf->lchild/rchild = p;

// LR
// 先左旋,后右旋

// RL
// 先右旋,后左旋