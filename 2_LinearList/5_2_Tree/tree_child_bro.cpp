#define _CRT_SECURE_NO_WARNINGS 1

// 孩子兄弟表示法（顺序 + 链式存储）

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30

typedef char ElemType;

typedef struct CSNode {
	ElemType data;
	// 第一个孩子和右兄弟指针
	struct CSNode* firstChild, * nextSibling;
}CSNode, *CSTree;

// 树和二叉树转换的问题