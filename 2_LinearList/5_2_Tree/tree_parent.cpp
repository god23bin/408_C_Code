#define _CRT_SECURE_NO_WARNINGS 1

// 双亲表示法（顺序存储）

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30			// 树中最多结点数

typedef char ElemType;

typedef struct {					// 树的结点定义
	ElemType data;					// 数据元素
	int parent;						// 双亲位置域
}PTNode;

typedef struct {					// 树的类型定义
	PTNode nodes[MAX_TREE_SIZE];	// 双亲表示
	int n;							// 结点数
}PTree;

// 插入结点
bool InsertPTNode(PTNode& node);

// 删除结点
// 方法1 直接将某节点的双亲域置为-1
// 方法2 直接将最后一个覆盖该结点
// 如果删除的不是叶子结点呢？？
// 通通删除其下面的所有结点

// 所以需要查找的函数

// 查找某个结点的所有子节点
bool FindSonNode(PTree& T);