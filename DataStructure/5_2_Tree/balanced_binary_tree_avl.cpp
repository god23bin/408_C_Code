#define _CRT_SECURE_NO_WARNINGS 1

// ƽ�������

#include <stdio.h>
#include <stdlib.h>


// ƽ����������
typedef struct AVLNode {
	int key;			// ������
	int balance;		// ƽ������
	struct AVLNode* lchild, * rchild;
}AVLNode, * AVLTree;

// ����
// �������α���ƽ��?
// �Ӳ���������ҵ���һ����ƽ����,�����Ըý��Ϊ��������,"��С��ƽ������"

// ��ε�����С��ƽ������

// LL
// ��������
// f�ǵ�,pΪ����,gfΪf����
// f->lchild = p->rchild;
// p->rchild = f;
// gf->lchild/rchild = p;

// RR
// ��������
// f->rchild = p->lchild;
// p->lchild = f;
// gf->lchild/rchild = p;

// LR
// ������,������

// RL
// ������,������