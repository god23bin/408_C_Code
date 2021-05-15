#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 10				// ����ջ��Ԫ�ص�������

typedef int ElemType;			

typedef struct {		
	ElemType data[MAXSIZE];		// ��̬������ջ��Ԫ��
	int top;					// ջ��ָ�� - ָ�����������±�
}SeqStack;

void InitStack(SeqStack& S);
bool StackIsEmpty(SeqStack S);
bool Push(SeqStack& S, ElemType x);
bool Pop(SeqStack& S, ElemType& x);
bool GetTop(SeqStack S, ElemType& x);

void InitStack(SeqStack& S) {
	S.top = -1;		// ��ʼ��ջ��ָ��
}

// ��һ�ַ�ʽ��ָ��0����ô�����ɾ������ô�㲻ͬ
//void InitStack(SeqStack& S) {
//	S.top = 0;		// ��ʼ��ջ��ָ��
//}

bool StackIsEmpty(SeqStack S) {
	if (S.top == -1)	// ջ��
		return true;
	else
		return false;
}

bool Push(SeqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1)
		return false;
	S.top++;
	S.data[S.top] = x;
	//S.data[++S.top] = x;
	return true;
}

bool Pop(SeqStack& S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top--;
	//x = S.data[S.top--];
}

bool GetTop(SeqStack S, ElemType& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

void testStack() {
	SeqStack S;		// ����һ��˳��ջ�������ڴ�ռ䣩
	InitStack(S);
}

int main() {
	testStack();
	return 0;
}