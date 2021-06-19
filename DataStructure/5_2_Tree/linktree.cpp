#define _CRT_SECURE_NO_WARNINGS 1

// ��������ʽ�洢

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// ������
	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
}BiTNode, * BiTree;

// n  �����Ķ���������   n+1�������� ����������


//// ��������-�����Ҹ����
//typedef struct BiTNode {
//	ElemType data;						// ������
//	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
//	struct BiTNode* parent;				// �����ָ��
//}BiTNode, * BiTree;

void InitTree(BiTree& root) {
	root = NULL;
}

bool InsertRoot(BiTree& root) {
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
	root->lchild = NULL;
	root->rchild = NULL;
}

bool InsertTNode(BiTree& root, ElemType e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { e };
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
}

