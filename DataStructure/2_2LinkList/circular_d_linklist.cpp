#define _CRT_SECURE_NO_WARNINGS 1

// ѭ��˫�����ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior, *next;
}DNode, * DLinkList;

// ��ʼ��ѭ��˫����
bool InitList(DLinkList& L);

// �п�
bool IsEmpty(DLinkList L);

// �жϽ��p�Ƿ�Ϊ��β���
bool IsTail(DLinkList L, DNode* p);

// ��p���֮�����s���
bool InsertNextDNode(DNode* p, DNode* s);

// ɾ������ - ɾ�� p ���ĺ�̽��
bool DeleteNextDNode(DNode* p);


bool InitList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));	// ����һ��ͷ���
	if (L == NULL) return false;		// �ڴ治�㣬����ʧ��
	L->prior = L;	// ͷ���� prior ָ�� ͷ���
	L->next = L;	// ͷ���� next ָ�� ͷ���
	return true;
}

bool IsEmpty(DLinkList L) {
	if (L->next == L)
		return true;
	else
		return false;
}

bool IsTail(DLinkList L, DNode* p) {
	if (p->next == L)
		return true;
	else
		return false;
}

bool InsertNextDNode(DNode* p, DNode* s) {
	s ->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}

bool DeleteNextDNode(DNode* p) {
	DNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);			// �ͷ� q
	q = NULL;
}