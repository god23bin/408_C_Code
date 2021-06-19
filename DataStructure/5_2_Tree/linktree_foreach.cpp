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