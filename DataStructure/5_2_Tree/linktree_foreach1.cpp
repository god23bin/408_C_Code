#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树的层次遍历

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	int value;
};

typedef struct BiTNode {
	ElemType data;						// 数据域
	struct BiTNode* lchild, * rchild;	// 左右孩子指针
}BiTNode, * BiTree;

// 链式队列结点
typedef struct LinkNode {
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;	// 队头队尾指针
}LinkQueue;

void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, BiTNode TNode);

// 不带头结点
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// 不带头结点判空
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear == NULL)
		return true;
	else
		return false;
}

// 不带头结点入队
void EnQueue(LinkQueue& Q, BiTNode* TNode) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = TNode;
	s->next = NULL;
	if (Q.front == NULL) {	// 在空队列中插入第一个元素
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// 新结点插入到rear后面
		Q.rear = s;			// rear指向新结点
	}
}


// 不带头结点出队
bool DeQueue(LinkQueue& Q, BiTNode* x) {
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

void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);						// 初始化辅助队列
	BiTree p;
	EnQueue(Q, T);						// 将根结点入队
	while (!IsEmpty(Q)) {				// 队列不为空就循环
		DeQueue(Q, p);					// 队头结点出队
		visit(p);						//访问出队结点
		if (p->lchild != NULL)			
			EnQueue(Q, p->lchild);		// 左孩子入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);		// 右孩子入队
	}
}