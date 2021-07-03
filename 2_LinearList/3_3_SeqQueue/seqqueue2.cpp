#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// 定义队列中元素的最大个数

typedef int ElemType;

// 方案二：判断队列已满/已空
// 在结构体中，多加一个size，来记录队列当前长度
// 初始化都为0
// 队空条件：size == 0;
// 队满条件：size == MAXSIZE
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
	int size;
}SeqQueue;

void InitQueue(SeqQueue& Q);
bool QueueEmpty(SeqQueue Q);
bool QueueFull(SeqQueue Q);
bool EnQueue(SeqQueue& Q, ElemType x);
bool DeQueue(SeqQueue& Q, ElemType& x);
bool GetHead(SeqQueue Q, ElemType& x);

void InitQueue(SeqQueue& Q) {
	// 初始化时，队头、队尾指针都指向0，size也初始化为0
	Q.front = Q.rear = Q.size = 0;
}

bool QueueEmpty(SeqQueue Q) {
	if (Q.size == 0)
		return true;
	else
		return false;
}

bool QueueFull(SeqQueue Q) {
	if (Q.size == MAXSIZE)
		return true;
	else
		return false;
}

bool EnQueue(SeqQueue& Q, ElemType x) {
	if (Q.size == MAXSIZE)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;	// 队尾指针加1取模
	Q.size++;
	return true;
}

bool DeQueue(SeqQueue& Q, ElemType& x) {
	if (Q.size == 0)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}

bool GetHead(SeqQueue Q, ElemType& x) {
	if (Q.size == 0)
		return false;
	x = Q.data[Q.front];
	return true;
}