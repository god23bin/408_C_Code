#define _CRT_SECURE_NO_WARNINGS 1

// ���ӱ�ʾ����˳�� + ��ʽ�洢��

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30

typedef char ElemType;

struct CTNode {
	int child;			// ���ӽ���������е�λ��
	struct CTNode* next;// ��һ������
};

typedef struct {
	ElemType data;				// ������
	struct CTNode* firstChild;	// ��һ������
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;					// ������͸���λ��
}CTree;