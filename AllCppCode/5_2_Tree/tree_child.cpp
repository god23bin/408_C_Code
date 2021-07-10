#define _CRT_SECURE_NO_WARNINGS 1

// 孩子表示法（顺序 + 链式存储）

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30

typedef char ElemType;

struct CTNode {
	int child;			// 孩子结点在数组中的位置
	struct CTNode* next;// 下一个孩子
};

typedef struct {
	ElemType data;				// 数据域
	struct CTNode* firstChild;	// 第一个孩子
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;					// 结点数和根的位置
}CTree;