#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// 定义队列中元素的最大个数

typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];		// 用静态数组存放队列元素
	int front, rear;			// 队头指针和队尾指针
}SeqQueue;

void InitQueue(SeqQueue& Q);
bool QueueEmpty(SeqQueue Q);
bool QueueFull(SeqQueue Q);
bool EnQueue(SeqQueue& Q, ElemType x);
bool DeQueue(SeqQueue& Q, ElemType& x);
bool GetHead(SeqQueue Q, ElemType& x);

// 初始化队列
void InitQueue(SeqQueue& Q) {
	// 初始化时，队头、队尾指针都指向0
	Q.rear = Q.front = 0;
}

// 判断队空
bool QueueEmpty(SeqQueue Q) {
	if (Q.rear == Q.front)	// 队空条件
		return true;
	else
		return false;
}

// 判断队满
bool QueueFull(SeqQueue Q) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return true;
	else
		return false;
}

// 方案二：判断队列已满/已空
// 在结构体中，多加一个size，来记录队列当前长度
// 初始化都为0
// 队空条件：size == 0;
// 队满条件：size == MAXSIZE

// 方案三：
// 在结构体中，多加一个tag，来记录最近进行的是删除/插入操作
// 删除成功时，令tag=0;
// 插入成功时，令tag=1;
// 只有删除，才可能导致队空
// 只有插入，才可能导致队满

// 队空条件：(front == rear) && (tag ==0)
// 队满条件：(front == rear) && (tag ==1)


// 入队
bool EnQueue(SeqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)	// 判断队满
		return false;	// 队满则返回false
	Q.data[Q.rear] = x;	// 新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXSIZE;	// 队尾指针加1取模
	// 用取模的方式使存储空间在逻辑上变成环状
	return true;
}

// 出队
bool DeQueue(SeqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

// 获取队头元素的值，用x返回
bool GetHead(SeqQueue Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	return true;
}

// 队列元素个数
// (rear + MAXSIZE - front) % MAXSIZE

void testQueue() {
	SeqQueue Q;
	InitQueue(Q);
}

int main() {
	testQueue();
	return 0;
}