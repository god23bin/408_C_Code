#define _CRT_SECURE_NO_WARNINGS 1

// �������Ĳ�α���

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// ������
	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
}BiTNode, * BiTree;

// ��ʽ���н��
typedef struct LinkNode {
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;	// ��ͷ��βָ��
}LinkQueue;

void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, BiTNode TNode);

// ����ͷ���
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// ����ͷ����п�
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear == NULL)
		return true;
	else
		return false;
}

// ����ͷ������
void EnQueue(LinkQueue& Q, BiTNode* TNode) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = TNode;
	s->next = NULL;
	if (Q.front == NULL) {	// �ڿն����в����һ��Ԫ��
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// �½����뵽rear����
		Q.rear = s;			// rearָ���½��
	}
}


// ����ͷ������
bool DeQueue(LinkQueue& Q, BiTNode* x) {
	if (Q.front == NULL)
		return false;		// �ն�
	LinkNode* p = Q.front;	// pָ��˴γ��ӵ�Ԫ��
	x = p->data;			// ��x���ض�ͷԪ��
	Q.front = p->next;		// �޸�frontָ��
	if (Q.rear == p) {		// �˴������һ�����
		Q.front = NULL;		// frontָ��NULL
		Q.rear = NULL;		// rearָ��NULL
	}
	free(p);				// �ͷŽ��ռ�
	return true;
}

void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);						// ��ʼ����������
	BiTree p;
	EnQueue(Q, T);						// ����������
	while (!IsEmpty(Q)) {				// ���в�Ϊ�վ�ѭ��
		DeQueue(Q, p);					// ��ͷ������
		visit(p);						//���ʳ��ӽ��
		if (p->lchild != NULL)			
			EnQueue(Q, p->lchild);		// �������
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);		// �Һ������
	}
}