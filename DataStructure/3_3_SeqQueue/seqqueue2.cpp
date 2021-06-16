#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// ���������Ԫ�ص�������

typedef int ElemType;

// ���������ж϶�������/�ѿ�
// �ڽṹ���У����һ��size������¼���е�ǰ����
// ��ʼ����Ϊ0
// �ӿ�������size == 0;
// ����������size == MAXSIZE
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
	// ��ʼ��ʱ����ͷ����βָ�붼ָ��0��sizeҲ��ʼ��Ϊ0
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
	Q.rear = (Q.rear + 1) % MAXSIZE;	// ��βָ���1ȡģ
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