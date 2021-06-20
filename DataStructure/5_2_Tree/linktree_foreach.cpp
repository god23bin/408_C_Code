#define _CRT_SECURE_NO_WARNINGS 1

// ���������������򡢺������

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// ������
	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
}BiTNode, * BiTree;

// ���ʳ���Ԫ�ء�
void visit(BiTNode* p);

// �������򡢺������
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

void InitTree(BiTree& root);
BiTree CreateBiTree();


// ���ʳ���Ԫ�ء�
void visit(BiTNode* p) {
	printf("%c ", p->data.value);		// ���ʳ���Ԫ�ؾ��ǰ�ֵ�������OK��
}

void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);				// ���ʸ����
		PreOrder(T->lchild);	// �ݹ����������
		PreOrder(T->rchild);	// �ݹ����������
	}
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);		// �ݹ����������
		visit(T);				// ���ʸ����
		InOrder(T->rchild);		// �ݹ����������
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);	// �ݹ����������
		PostOrder(T->rchild);	// �ݹ����������
		visit(T);				// ���ʸ����
	}
}


void InitTree(BiTree& root) {
	root = NULL;
}


BiTree CreateBiTree() {

	/*
	// �ֹ�����һ�����½ṹ�Ķ�������
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
	// ��������
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data.value = '1';
	root->lchild = NULL;
	root->rchild = NULL;

	// �ڶ����һ���ڵ㡣
	BiTNode* secondOne = (BiTNode*)malloc(sizeof(BiTNode));
	root->lchild = secondOne;
	secondOne->data.value = '2';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;

	// �ڶ���ڶ����ڵ㡣
	BiTNode* secondTow = (BiTNode*)malloc(sizeof(BiTNode));
	root->rchild = secondTow;
	secondTow->data.value = '3';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;

	// �������һ���ڵ㡣
	BiTNode* thirdOne = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = '4';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;

	// ������ڶ����ڵ㡣
	BiTNode* thirdTow = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = '5';
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;

	// ������������ڵ㡣
	BiTNode* thirdThree = (BiTNode*)malloc(sizeof(BiTNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = '6';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;

	// ���Ĳ��һ���ڵ㡣
	BiTNode* forthOne = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->lchild = forthOne;
	forthOne->data.value = '7';
	forthOne->lchild = NULL;
	forthOne->rchild = NULL;

	// ���Ĳ�ڶ����ڵ㡣
	BiTNode* forthTow = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = '8';
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;

	// ���Ĳ�������ڵ㡣
	BiTNode* forthThree = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->lchild = forthThree;
	forthThree->data.value = '9';
	forthThree->lchild = NULL;
	forthThree->rchild = NULL;

	// ���Ĳ���ĸ��ڵ㡣
	BiTNode* forthFour = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->rchild = forthFour;
	forthFour->data.value = '0';
	forthFour->lchild = NULL;
	forthFour->rchild = NULL;
	return root;
}


int main() {
	BiTree root = CreateBiTree();
	printf("�������->:\n");
	PreOrder(root);
	printf("\n");

	printf("�������->:\n");
	InOrder(root);
	printf("\n");

	printf("�������->:\n");
	PostOrder(root);
	printf("\n");
	return 0;
}