#define _CRT_SECURE_NO_WARNINGS 1


// 二叉树的顺序存储，只适用完全二叉树
// 一般很少用顺序存储

#include <stdio.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct {
	ElemType value;	// 结点中的数据元素
	bool isEmpty;	// 结点是否为空
}TreeNode;

typedef struct {
	TreeNode t[MAXSIZE];
}Tree;

bool InitTree(Tree& tree);

bool InitTree(Tree& tree) {
	for (int i = 0; i < MAXSIZE; i++) {
		tree.t[i].isEmpty = true;
	}
	return true;
}