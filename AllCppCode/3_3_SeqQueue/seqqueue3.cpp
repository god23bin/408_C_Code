#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// 定义队列中元素的最大个数

typedef int ElemType;
// 方案三：
// 在结构体中，多加一个tag，来记录最近进行的是删除/插入操作
// 删除成功时，令tag=0;
// 插入成功时，令tag=1;
// 只有删除，才可能导致队空
// 只有插入，才可能导致队满

// 队空条件：(front == rear) && (tag ==0)
// 队满条件：(front == rear) && (tag ==1)

typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
	int tag;
}SeqQueue;

void InitQueue(SeqQueue& Q);
bool QueueEmpty(SeqQueue Q);
bool QueueFull(SeqQueue Q);
bool EnQueue(SeqQueue& Q, ElemType x);
bool DeQueue(SeqQueue& Q, ElemType& x);
bool GetHead(SeqQueue Q, ElemType& x);

void InitQueue(SeqQueue& Q) {
	Q.front = Q.rear = Q.tag = 0;
}


bool QueueEmpty(SeqQueue Q) {
	if ((Q.front == Q.rear) && (Q.tag == 0))
		return true;
	else
		return false;
}

bool QueueFull(SeqQueue Q) {
	if ((Q.front == Q.rear) && (Q.tag == 1))
		return true;
	else
		return false;
}

bool EnQueue(SeqQueue& Q, ElemType x) {
	if ((Q.front == Q.rear) && (Q.tag == 1))
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;
	return true;
}

bool DeQueue(SeqQueue& Q, ElemType& x) {
	if ((Q.front == Q.rear) && (Q.tag == 0))
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.tag = 0;
	return true;
}

bool GetHead(SeqQueue Q, ElemType& x) {
	if ((Q.front == Q.rear) && (Q.tag == 0))
		return false;
	x = Q.data[Q.front];
	return true;
}