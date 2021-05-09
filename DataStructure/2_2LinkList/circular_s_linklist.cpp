#define _CRT_SECURE_NO_WARNINGS 1

// 循环单链表的实现

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

// 初始化循环单链表
bool InitList(LinkList& L);

// 判空
bool IsEmpty(LinkList L);

// 判断结点p是否为表尾结点
bool IsTail(LinkList L, LNode* p);



bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) return false;
	L->next = L;		// 头结点next指向头结点
	return true;
}

bool IsEmpty(LinkList L) {
	if (L->next == L) 
		return true;	// 头结点指向自己，说明是空表
	else 
		return false;
}

bool IsTail(LinkList L, LNode* p) {
	// 就判断 p 结点的下一个结点是否为头结点
	if (p->next == L) return true;	// 是的话，说明是表尾结点
	else return false;
}