#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10				// ���������Ԫ�ص�������

typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];		// �þ�̬�����Ŷ���Ԫ��
	int front, rear;			// ��ͷָ��Ͷ�βָ��
}SeqQueue;

void InitQueue(SeqQueue& Q);
bool QueueEmpty(SeqQueue Q);
bool QueueFull(SeqQueue Q);
bool EnQueue(SeqQueue& Q, ElemType x);
bool DeQueue(SeqQueue& Q, ElemType& x);
bool GetHead(SeqQueue Q, ElemType& x);

// ��ʼ������
void InitQueue(SeqQueue& Q) {
	// ��ʼ��ʱ����ͷ����βָ�붼ָ��0
	Q.rear = Q.front = 0;
}

// �ж϶ӿ�
bool QueueEmpty(SeqQueue Q) {
	if (Q.rear == Q.front)	// �ӿ�����
		return true;
	else
		return false;
}

// �ж϶���
bool QueueFull(SeqQueue Q) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return true;
	else
		return false;
}

// ���������ж϶�������/�ѿ�
// �ڽṹ���У����һ��size������¼���е�ǰ����
// ��ʼ����Ϊ0
// �ӿ�������size == 0;
// ����������size == MAXSIZE

// ��������
// �ڽṹ���У����һ��tag������¼������е���ɾ��/�������
// ɾ���ɹ�ʱ����tag=0;
// ����ɹ�ʱ����tag=1;
// ֻ��ɾ�����ſ��ܵ��¶ӿ�
// ֻ�в��룬�ſ��ܵ��¶���

// �ӿ�������(front == rear) && (tag ==0)
// ����������(front == rear) && (tag ==1)


// ���
bool EnQueue(SeqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)	// �ж϶���
		return false;	// �����򷵻�false
	Q.data[Q.rear] = x;	// ��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXSIZE;	// ��βָ���1ȡģ
	// ��ȡģ�ķ�ʽʹ�洢�ռ����߼��ϱ�ɻ�״
	return true;
}

// ����
bool DeQueue(SeqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

// ��ȡ��ͷԪ�ص�ֵ����x����
bool GetHead(SeqQueue Q, ElemType& x) {
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];
	return true;
}

// ����Ԫ�ظ���
// (rear + MAXSIZE - front) % MAXSIZE

void testQueue() {
	SeqQueue Q;
	InitQueue(Q);
}

int main() {
	testQueue();
	return 0;
}