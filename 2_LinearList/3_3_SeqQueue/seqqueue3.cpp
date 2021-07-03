#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// ���������Ԫ�ص�������

typedef int ElemType;
// ��������
// �ڽṹ���У����һ��tag������¼������е���ɾ��/�������
// ɾ���ɹ�ʱ����tag=0;
// ����ɹ�ʱ����tag=1;
// ֻ��ɾ�����ſ��ܵ��¶ӿ�
// ֻ�в��룬�ſ��ܵ��¶���

// �ӿ�������(front == rear) && (tag ==0)
// ����������(front == rear) && (tag ==1)

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