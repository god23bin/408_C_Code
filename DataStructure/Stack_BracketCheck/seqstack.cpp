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
	S.top = -1;			// 初始化栈顶指针
}

bool StackIsEmpty(SeqStack S) {
	if (S.top == -1)	// 栈空
		return true;
	else
		return false;
}

bool StackIsFull(SeqStack S) {
	if (S.top == MAXSIZE - 1)	// 栈满
		return true;
	else
		return false;
}

// 入栈
bool Push(SeqStack& S, ElemType e) {
	if (StackIsFull(S))
		return false;
	S.top++;
	S.data[S.top] = e;
	// S.data[++S.top] = e;
	return true;
}
bool Pop(SeqStack& S, ElemType& e) 
// 出栈
{
	if (StackIsEmpty(S))
		return false;
	e = S.data[S.top];
	S.top--;
	// e = S.data[S.top--];
	return true;
}

// 括号匹配算法
bool BracketCheck(char str[], int length) {
	SeqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			Push(S, str[i]);		// 扫描到左括号，入栈
		}
		else {
			if (StackIsEmpty(S))
				return false;
			char topElem;
			Pop(S, topElem);		// 栈顶元素出栈
			if (str[i] == ')' && topElem != '(')
				return false;
			if (str[i] == ']' && topElem != '[')
				return false;
			if (str[i] == '}' && topElem != '{')
				return false;
		}
	}
	return StackIsEmpty(S);	// 检查完全部括号后，栈空说明匹配成功
}

bool BracketCheck(char str[], int length) {
	SeqStack S;
	//InitStack(S);
	S.top = -1;			// 初始化栈顶指针
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			S.data[++S.top] = str[i];
			//Push(S, str[i]);		// 扫描到左括号，入栈
		}
		else {
			//if (StackIsEmpty(S))
			if (S.top == -1)		// 栈空
				return false;
			char topElem;
			//Pop(S, topElem);		// 栈顶元素出栈
			topElem = S.data[S.top--];
			if (str[i] == ')' && topElem != '(')
				return false;
			if (str[i] == ']' && topElem != '[')
				return false;
			if (str[i] == '}' && topElem != '{')
				return false;
		}
	}
	//return StackIsEmpty(S);	// 检查完全部括号后，栈空说明匹配成功
	if (S.top == -1)
		return true;
	else
		return false;
}
