#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 10

typedef char ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack& S);
bool StackIsEmpty(SeqStack S);
bool StackIsFull(SeqStack S);
bool Push(SeqStack& S, ElemType e);
bool Pop(SeqStack& S, ElemType& e);

void InitStack(SeqStack& S) {
	S.top = -1;			// ��ʼ��ջ��ָ��
}

bool StackIsEmpty(SeqStack S) {
	if (S.top == -1)	// ջ��
		return true;
	else
		return false;
}

bool StackIsFull(SeqStack S) {
	if (S.top == MAXSIZE - 1)	// ջ��
		return true;
	else
		return false;
}

// ��ջ
bool Push(SeqStack& S, ElemType e) {
	if (StackIsFull(S))
		return false;
	S.top++;
	S.data[S.top] = e;
	// S.data[++S.top] = e;
	return true;
}
bool Pop(SeqStack& S, ElemType& e) 
// ��ջ
{
	if (StackIsEmpty(S))
		return false;
	e = S.data[S.top];
	S.top--;
	// e = S.data[S.top--];
	return true;
}

// ����ƥ���㷨
bool BracketCheck(char str[], int length) {
	SeqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			Push(S, str[i]);		// ɨ�赽�����ţ���ջ
		}
		else {
			if (StackIsEmpty(S))
				return false;
			char topElem;
			Pop(S, topElem);		// ջ��Ԫ�س�ջ
			if (str[i] == ')' && topElem != '(')
				return false;
			if (str[i] == ']' && topElem != '[')
				return false;
			if (str[i] == '}' && topElem != '{')
				return false;
		}
	}
	return StackIsEmpty(S);	// �����ȫ�����ź�ջ��˵��ƥ��ɹ�
}

bool BracketCheck(char str[], int length) {
	SeqStack S;
	//InitStack(S);
	S.top = -1;			// ��ʼ��ջ��ָ��
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			S.data[++S.top] = str[i];
			//Push(S, str[i]);		// ɨ�赽�����ţ���ջ
		}
		else {
			//if (StackIsEmpty(S))
			if (S.top == -1)		// ջ��
				return false;
			char topElem;
			//Pop(S, topElem);		// ջ��Ԫ�س�ջ
			topElem = S.data[S.top--];
			if (str[i] == ')' && topElem != '(')
				return false;
			if (str[i] == ']' && topElem != '[')
				return false;
			if (str[i] == '}' && topElem != '{')
				return false;
		}
	}
	//return StackIsEmpty(S);	// �����ȫ�����ź�ջ��˵��ƥ��ɹ�
	if (S.top == -1)
		return true;
	else
		return false;
}
