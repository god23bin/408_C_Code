#define _CRT_SECURE_NO_WARNINGS 1

// 双链表的实现

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;					// 数据域
	struct DNode* prior, * next;	// 前驱结点指针，后继结点指针
}DNode, * DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList& L);

// 判断双链表是否为空
bool IsEmpty(DLinkList& L);

// 按值查找和按位查找和单链表一样
DNode* LocateElem(DLinkList& L, ElemType e);
DNode* GetElem(DLinkList& L, int i);

// 插入操作 - 后插 在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode* p, DNode* s);

// 按位序插入
bool ListInsert(DLinkList& L, int i, ElemType e);

// 前插操作 - 在 p 结点之前插入结点
bool InsertPrior1(DNode* p, ElemType e);
bool InsertPrior2(DNode* p, DNode* s);

// 表头插入
DLinkList ListHeadInsert(DLinkList& L);
// 表尾插入
DLinkList ListTailInsert(DLinkList& L);

// 删除操作
bool DeleteNextDNode(DNode* p);

bool ListDelete(DLinkList& L, int i, ElemType& e);

// 销毁双链表
void DestoryDLinkList(DLinkList& L);

// 双链表的遍历 - 后向遍历
void TravelToNext(DLinkList& L);
void TravelToPrior(DLinkList& L);

bool InitDLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));	// 分配一个头结点
	if (L == NULL) return false;		// 内存不足，分配失败
	L->prior = NULL;	// 头结点的 prior 永远指向 NULL 
	L->next = NULL;		// 头结点之后暂时还没有结点
	return true;
}

bool IsEmpty(DLinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}

// 按值查找
DNode* LocateElem(DLinkList& L, ElemType e) {
	DNode* p = L->next;
	while (p != NULL && p->data != e) {		// 还是一样，如果ElemType是结构体，就得具体比较
		p = p->next;
	}
	return p;
}

// 按位查找
DNode* GetElem(DLinkList& L, int i) {
	DNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// 在 p 结点之后插入 s 结点
//bool InsertNextDNode(DNode* p, DNode* s) {
//	s->next = p->next;
//	p->next->prior = s;		// 如果是最后一个结点插入，这里就会出错
//	s->prior = p;
//	p->next = s;
//}
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL) return false;	// 空指针判断
	s->next = p->next;
	if (p->next != NULL)		// 如果 p 结点有后继结点
		p->next->prior = s;
	s->prior = p;
	p->next = s;
}
// 实现了后插操作，那么其他操作都可以通过后插来实现，比如按位序插入/前插操作

// 按位序插入
bool ListInsert(DLinkList& L, int i, ElemType e) {
	DNode* p = GetElem(L, i - 1);
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL) return false;
	s->data = e;
	return InsertNextDNode(p, s);
}

// 前插操作 - 在 p 结点之前插入结点
bool InsertPrior1(DNode* p, ElemType e) {
	DNode* q = p->prior;	// q 指向 p 的前一个结点
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL)return false;
	s->data = e;
	return InsertNextDNode(q, s);
}

bool InsertPrior2(DNode* p, DNode* s) {
	DNode* q = p->prior;
	return InsertNextDNode(q, s);
}

// 表头插入
DLinkList ListHeadInsert(DLinkList& L) {
	DNode* s;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		if (s == NULL) return s;
		s->data = x;
		s->next = L->next;
		s->prior = L;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
// 表尾插入
DLinkList ListTailInsert(DLinkList& L) {
	DNode* s, * r = L;		// r 表尾指针，指向 L，头结点
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		if (s == NULL) return s;
		s->data = x;
		s->next = NULL;
		s->prior = r;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	return L;
}

// 删除操作 - 删除 p 结点的后继结点
bool DeleteNextDNode(DNode* p) {
	if (p == NULL) return false;
	DNode* q = p->next;
	if (q == NULL) return false;	// 说明 p 没有后继
	p->next = q->next;
	if (q->next != NULL)			// q 结点不是最后一个结点
		q->next->prior = p;
	free(q);						// 释放 q
	q = NULL;
}

bool ListDelete(DLinkList& L, int i, ElemType& e) {
	DNode* p = GetElem(L, i - 1);
	e = p->next->data;
	return DeleteNextDNode(p);
}

// 销毁双链表
void DestoryDLinkList(DLinkList& L) {
	// 循环释放各个数据结点
	while (L->next != NULL) {
		DeleteNextDNode(L);		// 删除头结点的后继结点
	}
	free(L);	// 释放头结点
	L = NULL;	// 头指针指向NULL
}

void TravelToNext(DLinkList& L) {
	DNode* p;
	p = L;
	while (p != NULL) {
		p = p->next;
	}
}

void TravelToPrior(DLinkList& L) {
	DNode* p;
	p = L;
	while (p != NULL) {
		p = p->prior;
	}
}

void PrintList(DLinkList& L) {
	DNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


void testDLinkList() {
	// 初始化双链表
	DLinkList L;
	InitDLinkList(L);

	ElemType e;
	DNode* p, * s;

	int i;

	printf("现在进行表头插入双向链表->:\n");
	ListHeadInsert(L);

	//printf("现在进行表尾插入双向链表->:\n");
	//ListTailInsert(L);

	PrintList(L);

	e = 3;
	p = LocateElem(L, e);
	printf("按值查找 值 %d ->:已找到，为 %d\n", e, p->data);

	i = 2;
	s = GetElem(L, i);
	printf("按位查找 位 %d ->:已找到，为 %d\n", i, s->data);

	i = 2;
	ListDelete(L, i, e);
	printf("删除操作->:已删除%d个位置的结点，值为%d\n", i, e);

	PrintList(L);
}


int main() {
	testDLinkList();
	return 0;
}