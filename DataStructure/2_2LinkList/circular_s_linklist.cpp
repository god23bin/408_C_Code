#define _CRT_SECURE_NO_WARNINGS 1

// ѭ���������ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

// ��ʼ��ѭ��������
bool InitList(LinkList& L);

// �п�
bool IsEmpty(LinkList L);

// �жϽ��p�Ƿ�Ϊ��β���
bool IsTail(LinkList L, LNode* p);



bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) return false;
	L->next = L;		// ͷ���nextָ��ͷ���
	return true;
}

bool IsEmpty(LinkList L) {
	if (L->next == L) 
		return true;	// ͷ���ָ���Լ���˵���ǿձ�
	else 
		return false;
}

bool IsTail(LinkList L, LNode* p) {
	// ���ж� p ������һ������Ƿ�Ϊͷ���
	if (p->next == L) return true;	// �ǵĻ���˵���Ǳ�β���
	else return false;
}