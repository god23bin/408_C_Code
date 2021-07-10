#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAXSIZE 10				// 定义栈中元素的最大个数

typedef int ElemType;			

typedef struct {		
	ElemType data[MAXSIZE];		// 静态数组存放栈中元素
	int top;					// 栈顶指针 - 指向的是数组的下标
}SeqStack;

void InitStack(SeqStack& S);
bool StackIsEmpty(SeqStack S);
bool Push(SeqStack& S, ElemType x);
bool Pop(SeqStack& S, ElemType& x);
bool GetTop(SeqStack S, ElemType& x);

void InitStack(SeqStack& S) {
	S.top = -1;		// 初始化栈顶指针
}

// 另一种方式，指向0，那么插入和删除有那么点不同
//void InitStack(SeqStack& S) {
//	S.top = 0;		// 初始化栈顶指针
//}

bool StackIsEmpty(SeqStack S) {
	if (S.top == -1)	// 栈空
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
	SeqStack S;		// 声明一个顺序栈（分配内存空间）
	InitStack(S);
}

int main() {
	testStack();
	return 0;
}