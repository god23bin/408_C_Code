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

// 访问出队元素。
void visit(BiTNode* p);

// 先序、中序、后序遍历
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

void InitTree(BiTree& root);
BiTree CreateBiTree();


// 访问出队元素。
void visit(BiTNode* p) {
	printf("%c ", p->data.value);		// 访问出队元素就是把值输出来就OK了
}

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
	printf("先序遍历->:\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历->:\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历->:\n");
	PostOrder(root);
	printf("\n");
	return 0;
}