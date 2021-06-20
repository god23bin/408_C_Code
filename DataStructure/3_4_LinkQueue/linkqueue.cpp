#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct LinkNode {		// 链式队列结点
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {				// 链式队列
	LinkNode* front, * rear;	// 队列的队头、队尾指针
	// int length;				// 可以加多变量，记录长度
}LinkQueue;

// 队列基本操作 - 初始化/判空/入队/出队

// 带头结点的基本操作
void InitQueueWithHead(LinkQueue& Q);
bool IsEmptyWithHead(LinkQueue Q);
bool EnQueueWithHead(LinkQueue& Q, ElemType x);
bool DeQueueWithHead(LinkQueue& Q, ElemType& x);

// 不带头结点的基本操作
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

// 带头结点
void InitQueueWithHead(LinkQueue& Q) {
	// 初始时，front、rear都指向头结点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

// 带头结点的判空
bool IsEmptyWithHead(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

// 带头结点入队
bool EnQueueWithHead(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;	// 新结点插入到rear后面
	Q.rear = s;			// 修改表尾指针指向新结点
	return true;
}

// 带头结点出队
bool DeQueueWithHead(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear)
		return false;				// 空队列
	LinkNode* p = Q.front->next;
	x = p->data;					// 用x返回队头元素
	Q.front->next = p->next;		// 修改头结点的next指针
	if (Q.rear == p)				// 此次是最后一个结点出队的话
		Q.rear = Q.front;			// 修改rear指针
	free(p);						// 释放结点空间
	return true;
}


// 不带头结点
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// 不带头结点判空
bool IsEmpty(LinkQueue Q) {
	//if (Q.front == Q.rear == NULL) 判空会失败
	if (Q.front == Q.rear && Q.rear == NULL)
		return true;
	else
		return false;
}

// 不带头结点入队
bool EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// 在空队列中插入第一个元素
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// 新结点插入到rear后面
		Q.rear = s;			// rear指向新结点
	}
	return true;
}

// 不带头结点出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == NULL)
		return false;		// 空队
	LinkNode* p = Q.front;	// p指向此次出队的元素
	x = p->data;			// 用x返回队头元素
	Q.front = p->next;		// 修改front指针
	if (Q.rear == p) {		// 此次是最后一个结点
		Q.front = NULL;		// front指向NULL
		Q.rear = NULL;		// rear指向NULL
	}
	free(p);				// 释放结点空间
	return true;
}


void testLinkQueue() {
	LinkQueue Q;	// 声明一个队列
	InitQueue(Q);	// 初始化队列
	// 
}

int main() {
	return 0;
}