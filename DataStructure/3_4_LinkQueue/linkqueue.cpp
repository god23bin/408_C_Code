#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct LinkNode {		// ��ʽ���н��
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct {				// ��ʽ����
	LinkNode* front, * rear;	// ���еĶ�ͷ����βָ��
	// int length;				// ���ԼӶ��������¼����
}LinkQueue;

// ���л������� - ��ʼ��/�п�/���/����

// ��ͷ���Ļ�������
void InitQueueWithHead(LinkQueue& Q);
bool IsEmptyWithHead(LinkQueue Q);
bool EnQueueWithHead(LinkQueue& Q, ElemType x);
bool DeQueueWithHead(LinkQueue& Q, ElemType& x);

// ����ͷ���Ļ�������
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

// ��ͷ���
void InitQueueWithHead(LinkQueue& Q) {
	// ��ʼʱ��front��rear��ָ��ͷ���
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

// ��ͷ�����п�
bool IsEmptyWithHead(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

// ��ͷ������
bool EnQueueWithHead(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;	// �½����뵽rear����
	Q.rear = s;			// �޸ı�βָ��ָ���½��
	return true;
}

// ��ͷ������
bool DeQueueWithHead(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear)
		return false;				// �ն���
	LinkNode* p = Q.front->next;
	x = p->data;					// ��x���ض�ͷԪ��
	Q.front->next = p->next;		// �޸�ͷ����nextָ��
	if (Q.rear == p)				// �˴������һ�������ӵĻ�
		Q.rear = Q.front;			// �޸�rearָ��
	free(p);						// �ͷŽ��ռ�
	return true;
}


// ����ͷ���
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
}

// ����ͷ����п�
bool IsEmpty(LinkQueue Q) {
	//if (Q.front == Q.rear == NULL) �пջ�ʧ��
	if (Q.front == Q.rear && Q.rear == NULL)
		return true;
	else
		return false;
}

// ����ͷ������
bool EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// �ڿն����в����һ��Ԫ��
		Q.front = s;
		Q.rear = s;
	}
	else {
		Q.rear->next = s;	// �½����뵽rear����
		Q.rear = s;			// rearָ���½��
	}
	return true;
}

// ����ͷ������
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == NULL)
		return false;		// �ն�
	LinkNode* p = Q.front;	// pָ��˴γ��ӵ�Ԫ��
	x = p->data;			// ��x���ض�ͷԪ��
	Q.front = p->next;		// �޸�frontָ��
	if (Q.rear == p) {		// �˴������һ�����
		Q.front = NULL;		// frontָ��NULL
		Q.rear = NULL;		// rearָ��NULL
	}
	free(p);				// �ͷŽ��ռ�
	return true;
}


void testLinkQueue() {
	LinkQueue Q;	// ����һ������
	InitQueue(Q);	// ��ʼ������
	// 
}

int main() {
	return 0;
}