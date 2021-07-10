#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


typedef char ElemType;

// 以孩子兄弟表示法存储树
typedef struct TreeNode {
	ElemType data;
	struct TreeNode* firstChild, * nextSibling;
}TreeNode, *Tree;

// 树的先根遍历
// 若树非空，先访问根结点，再依次对每个子树进行先根遍历
//void PreOrder(TreeNode* R) {
//	if (R != NULL) {
//		visit(R);
//		while (R还有下一个子树T)
//			PreOrder(T);
//	}
//}

// 后根遍历
// 若树非空，先依次对每个子树进行后根遍历，最后再访问根结点
//void PostOrder(TreeNode* R) {
//	if (R != NULL) {
//		while (R还有下一个子树T)
//			PostOrder(T);
//		visit(R);
//	}
//}

// 树的后根遍历序列与这棵树相应二叉树的中序序列相同

// 层次遍历
// 基本上和二叉树的一样，需要使用辅助队列。


// 层次遍历，横向探索，可以称为对树的广度优先遍历

// 对于先根遍历，后根遍历，可以称为对树的深度优先遍历

// 森林的先序遍历
// 相当于依次对各个子树进行先根遍历，然后排出完整的序列
// 还相当于森林转成相对应的二叉树，其二叉树的先序遍历序列

// 森林的中序遍历
// 相当于依次对各个子树进行后根遍历
// 还相当于森林转成相对应的二叉树，其二叉树的中序遍历序列
