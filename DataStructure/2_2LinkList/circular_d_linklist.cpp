#define _CRT_SECURE_NO_WARNINGS 1

// 循环双链表的实现

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior, *next;
}DNode, * DLinkList;

// 初始化循环双链表
bool InitList(DLinkList& L);

// 判空
bool IsEmpty(DLinkList L);

// 判断结点p是否为表尾结点
bool IsTail(DLinkList L, DNode* p);

// 在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s);

// 删除操作 - 删除 p 结点的后继结点
bool DeleteNextDNode(DNode* p);


bool InitList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));	// 分配一个头结点
	if (L == NULL) return false;		// 内存不足，分配失败
	L->prior = L;	// 头结点的 prior 指向 头结点
	L->next = L;	// 头结点的 next 指向 头结点
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
	free(q);			// 释放 q
	q = NULL;
}