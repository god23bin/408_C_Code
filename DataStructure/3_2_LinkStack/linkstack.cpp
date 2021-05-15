#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// ջ�Ľṹ������͵�����û��������Ҫ�������ڲ�����ʵ��
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}SNode, * LinkStack;

void InitStack(LinkStack& S);					// ��ʼ��
bool StackIsEmpty(LinkStack S);					// �п�
bool Push(LinkStack& S, ElemType x);			// ��ջ
bool Pop(LinkStack& S, ElemType& x);			// ��ջ
bool GetTop(LinkStack S, ElemType& x);			// ��ȡջ��Ԫ��
bool GetStackLength(LinkStack S, int& length);	// ��ȡջ�ĳ���
void PrintStack(LinkStack S);					// ��ӡ��ǰջ

void InitStack(LinkStack& S) {
	S = NULL;
}

bool StackIsEmpty(LinkStack S) {
	if (S == NULL)
		return true;
	else
		return false;
}

bool Push(LinkStack& S, ElemType x) {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL) return false;
	p->data = x;
	p->next = S;
	S = p;
	return true;
}

bool Pop(LinkStack& S, ElemType& x) {
	SNode* p = S;
	if (StackIsEmpty(S)) return false;
	x = S->data;
	S = S->next;
	p = NULL;
	free(p);
	return true;
}

bool GetTop(LinkStack S, ElemType& x) {
	if (StackIsEmpty(S)) return false;
	x = S->data;
	return true;
}

bool GetStackLength(LinkStack S, int& length) {
	if (S == NULL) {
		length = 0;
	}
	LinkNode* p = S;
	length = 0;
	while (p != NULL) {
		p = p->next;
		length++;
	}
	return true;
}

void PrintStack(LinkStack S) {
	printf("��ӡ��ǰջ������->:\n");
	if (S == NULL) {
		printf("ջ��~~~~\n");
		return;
	}
	LinkNode* p = S;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void testLinkStack() {
	LinkStack S;
	InitStack(S);
	int x, length;
	printf("������Ҫ��ջ��ѹջ����Ԫ�أ�����9999����->:\n");
	scanf("%d", &x);
	while (x != 9999) {
		Push(S, x);
		scanf("%d", &x);
	}
	PrintStack(S);

	GetTop(S, x);
	printf("��ȡ��ǰջ��Ԫ��->: %d \n", x);

	GetStackLength(S, length);
	printf("��ȡ��ǰջ�ĳ���->: %d \n", length);

	while (S != NULL) {
		printf("��ʼ��ջ����->:\n\n");
		Pop(S, x);
		printf("��� %d ��ջ������\n\n", x);
	}
	PrintStack(S);


	GetStackLength(S, length);
	printf("��ȡ��ǰջ�ĳ���->: %d \n", length);

}

int main() {
	testLinkStack();
	return 0;
}