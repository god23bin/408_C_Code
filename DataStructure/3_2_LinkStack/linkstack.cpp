#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 栈的结构体基本和单链表没有区别，主要区别在于操作的实现
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}SNode, * LinkStack;

void InitStack(LinkStack& S);					// 初始化
bool StackIsEmpty(LinkStack S);					// 判空
bool Push(LinkStack& S, ElemType x);			// 入栈
bool Pop(LinkStack& S, ElemType& x);			// 出栈
bool GetTop(LinkStack S, ElemType& x);			// 获取栈顶元素
bool GetStackLength(LinkStack S, int& length);	// 获取栈的长度
void PrintStack(LinkStack S);					// 打印当前栈

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
	printf("打印当前栈的内容->:\n");
	if (S == NULL) {
		printf("栈空~~~~\n");
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
	printf("请输入要入栈（压栈）的元素，输入9999结束->:\n");
	scanf("%d", &x);
	while (x != 9999) {
		Push(S, x);
		scanf("%d", &x);
	}
	PrintStack(S);

	GetTop(S, x);
	printf("获取当前栈顶元素->: %d \n", x);

	GetStackLength(S, length);
	printf("获取当前栈的长度->: %d \n", length);

	while (S != NULL) {
		printf("开始出栈操作->:\n\n");
		Pop(S, x);
		printf("完成 %d 出栈操作。\n\n", x);
	}
	PrintStack(S);


	GetStackLength(S, length);
	printf("获取当前栈的长度->: %d \n", length);

}

int main() {
	testLinkStack();
	return 0;
}