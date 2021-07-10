#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树链式存储

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	char value;
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


// 二叉树的手动创建

void InitTree(BiTree& root);
BiTree CreateBiTree();

void InitTree(BiTree& root) {
	root = NULL;
}


BiTree CreateBiTree() {

	/*
	// 手工构造一个如下结构的二叉树。
			   1
			/     \
		   2       3
		  / \     /
		 4   5   6
		/ \ / \
	   7  8 9  0
	*/

	BiTree root;
	InitTree(root);
	// 分配根结点
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data.value = '1';
	root->lchild = NULL;
	root->rchild = NULL;

	// 第二层第一个节点。
	BiTNode* secondOne = (BiTNode*)malloc(sizeof(BiTNode));
	root->lchild = secondOne;
	secondOne->data.value = '2';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;

	// 第二层第二个节点。
	BiTNode* secondTow = (BiTNode*)malloc(sizeof(BiTNode));
	root->rchild = secondTow;
	secondTow->data.value = '3';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;

	// 第三层第一个节点。
	BiTNode* thirdOne = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = '4';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;

	// 第三层第二个节点。
	BiTNode* thirdTow = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = '5'; 
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;

	// 第三层第三个节点。
	BiTNode* thirdThree = (BiTNode*)malloc(sizeof(BiTNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = '6';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;

	// 第四层第一个节点。
	BiTNode* forthOne = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->lchild = forthOne;
	forthOne->data.value = '7';
	forthOne->lchild = NULL;
	forthOne->rchild = NULL;

	// 第四层第二个节点。
	BiTNode* forthTow = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = '8'; 
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;

	// 第四层第三个节点。
	BiTNode* forthThree = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->lchild = forthThree;
	forthThree->data.value = '9'; 
	forthThree->lchild = NULL;
	forthThree->rchild = NULL;

	// 第四层第四个节点。
	BiTNode* forthFour = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->rchild = forthFour;
	forthFour->data.value = '0'; 
	forthFour->lchild = NULL;
	forthFour->rchild = NULL;
	return root;
}

int main() {
	BiTree root = CreateBiTree();
	return 0;
}

