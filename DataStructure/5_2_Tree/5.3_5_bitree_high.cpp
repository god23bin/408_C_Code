#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// ����ջ��С
#define MAXSIZE 30

struct ElemType {
	char value;
};


typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

// ����ջ - ˳��ջʵ��
typedef struct {
	BiTree data[MAXSIZE];
	int top;
}SeqStack;

// --------------------------��������

// ���ʳ���Ԫ�ء�
void visit(BiTNode* p);

void PostOrder(BiTree T);


void InitTree(BiTree& root);
BiTree CreateBiTree();

// ջ���������
void InitStack(SeqStack& S);
bool IsEmpty(SeqStack S);
bool IsFull(SeqStack S);
bool Push(SeqStack& S, BiTree T);
bool Pop(SeqStack& S, BiTree& T);
bool GetTop(SeqStack& S, BiTree& T);

// ����ǵݹ��ȡ�߶�
void GetHighByPostOrder(BiTree T, int& maxh);

// --------------------------����ʵ��{

void visit(BiTNode* p) {
	printf("%c ", p->data.value);
}

// �ǵݹ�ķ�ʽʵ�ֺ������ - ʹ��ջ


void InitTree(BiTree& root) {
	root = NULL;
}


BiTree CreateBiTree() {

	/*
	// �ֹ�����һ�����½ṹ�Ķ�������
			   1
			/     \
		   2       3
		  / \     /
		 4   5   6
		/ \ / \
	   7  8 9  0
	   ǰ��1 2 4 7 8 5 9 0 3 6
	   ����7 4 8 2 9 5 0 1 6 3
	   ����7 8 4 9 0 5 2 6 3 1
	*/

	BiTree root;
	InitTree(root);
	// ��������
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data.value = '1';
	root->lchild = NULL;
	root->rchild = NULL;

	// �ڶ����һ���ڵ㡣
	BiTNode* secondOne = (BiTNode*)malloc(sizeof(BiTNode));
	root->lchild = secondOne;
	secondOne->data.value = '2';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;

	// �ڶ���ڶ����ڵ㡣
	BiTNode* secondTow = (BiTNode*)malloc(sizeof(BiTNode));
	root->rchild = secondTow;
	secondTow->data.value = '3';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;

	// �������һ���ڵ㡣
	BiTNode* thirdOne = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = '4';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;

	// ������ڶ����ڵ㡣
	BiTNode* thirdTow = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = '5';
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;

	// ������������ڵ㡣
	BiTNode* thirdThree = (BiTNode*)malloc(sizeof(BiTNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = '6';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;

	// ���Ĳ��һ���ڵ㡣
	BiTNode* forthOne = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->lchild = forthOne;
	forthOne->data.value = '7';
	forthOne->lchild = NULL;
	forthOne->rchild = NULL;

	// ���Ĳ�ڶ����ڵ㡣
	BiTNode* forthTow = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = '8';
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;

	// ���Ĳ�������ڵ㡣
	BiTNode* forthThree = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->lchild = forthThree;
	forthThree->data.value = '9';
	forthThree->lchild = NULL;
	forthThree->rchild = NULL;

	// ���Ĳ���ĸ��ڵ㡣
	BiTNode* forthFour = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->rchild = forthFour;
	forthFour->data.value = '0';
	forthFour->lchild = NULL;
	forthFour->rchild = NULL;
	return root;
}

// ջ����ز���ʵ��

void InitStack(SeqStack& S) {
	S.top = -1;			// ��ʼ��ջ��ָ��
}

bool IsEmpty(SeqStack S) {
	if (S.top == -1)	// ջ��
		return true;
	else
		return false;
}

bool IsFull(SeqStack S) {
	if (S.top == MAXSIZE - 1)
		return true;
	else
		return false;
}

bool Push(SeqStack& S, BiTree T) {
	if (IsFull(S))
		return false;

	S.top++;
	S.data[S.top] = T;

	return true;
}

bool Pop(SeqStack& S, BiTree& T) {
	if (IsEmpty(S))
		return false;

	T = S.data[S.top];
	S.top--;

	return true;
}

bool GetTop(SeqStack& S, BiTree& T) {
	if (IsEmpty(S))
		return false;
	T = S.data[S.top];
	return true;
}

// ����ǵݹ��ȡ�߶�
void GetHighByPostOrder(BiTree T, int& maxh) {
	SeqStack S;
	InitStack(S);
	BiTree p;
	BiTree r;	// ����ָ�룬ָ��������ʵĵ�
	p = T;
	r = NULL;
	maxh = 0;// ���߶�
	while (p != NULL || !IsEmpty(S)) {
		if (p) {			// p ��Ϊ NULL���Ǿ�һֱ��ջ���ߵ������
			Push(S, p);
			p = p->lchild;
		}
		else {
			// ����
			// �����������ΪNULL����ô������������
			GetTop(S, p);	// ��ȡջ�����
			if (p->rchild && p->rchild != r) {	// ��������������δ�����ʹ�
				p = p->rchild;		// ת����
				Push(S, p);			// ��ջ
				p = p->lchild;		// ���ߵ����󣬽�����һѭ��
			}
			else {			// ���򣬵�����㲢����
				if (S.top + 1 > maxh)	
					maxh = S.top + 1;//����μ�Ϊ�߶ȣ�top��ʼ����-1�����Ե�һ��Ԫ���Ǵ�0��ʼ����������Ҫ+1
				Pop(S, p);
				visit(p);
				r = p;		// ��¼������ʹ��Ľ��
				p = NULL;	// �������������pָ��
			}
		}
	}
}


void test_post() {
	BiTree root = CreateBiTree();
	int maxh = 0;
	printf("�ǵݹ�ĺ������->:\n");
	GetHighByPostOrder(root, maxh);
	printf("\n");
	printf("%d", maxh);
}

int main() {
	// ����7 8 4 9 0 5 2 6 3 1
	test_post();
	printf("\n");
	return 0;
}