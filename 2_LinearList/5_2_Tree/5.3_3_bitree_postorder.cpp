//#define _CRT_SECURE_NO_WARNINGS 1
//
//// 后序遍历非递归的实现
//// 同时还实现了先序/中序的非递归
//#include <stdio.h>
//#include <stdlib.h>
//
//// 辅助栈大小
//#define MAXSIZE 30
//
//struct ElemType {
//	char value;
//};
//
//
//typedef struct BiTNode {
//	ElemType data;
//	struct BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;
//
//// 辅助栈 - 顺序栈实现
//typedef struct {
//	BiTree data[MAXSIZE];
//	int top;
//}SeqStack;
//
//// --------------------------函数声明
//
//// 访问出队元素。
//void visit(BiTNode* p);
//
//void PostOrder(BiTree T);
//
//
//void InitTree(BiTree& root);
//BiTree CreateBiTree();
//
//// 先序递归创建树
//void CreateTree(BiTree& T);
//
//// 栈的相关声明
//void InitStack(SeqStack& S);
//bool IsEmpty(SeqStack S);
//bool IsFull(SeqStack S);
//bool Push(SeqStack& S, BiTree T);
//bool Pop(SeqStack& S, BiTree& T);
//bool GetTop(SeqStack& S, BiTree& T);
//
//// 非递归遍历
//
//// 前序非递归
//void PreOrderNonRecursive(BiTree T);
//// 中序非递归
//void InOrderNonRecursive(BiTree T);
//// 后序非递归
//void PostOrderNonRecursive(BiTree T);
//
//
//// --------------------------函数实现
//
//void visit(BiTNode* p) {
//	printf("%c ", p->data.value);
//}
//
//// 递归的方式实现后序遍历
//void PostOrder(BiTree T) {
//	if (T != NULL) {
//		PostOrder(T->lchild);
//		PostOrder(T->rchild);
//		visit(T);
//	}
//}
//
//// 非递归的方式实现后序遍历 - 使用栈
//
//
//void InitTree(BiTree& root) {
//	root = NULL;
//}
//
//
//BiTree CreateBiTree() {
//
//	/*
//	// 手工构造一个如下结构的二叉树。
//			   1
//			/     \
//		   2       3
//		  / \     /
//		 4   5   6
//		/ \ / \
//	   7  8 9  0
//	   前序：1 2 4 7 8 5 9 0 3 6
//	   中序：7 4 8 2 9 5 0 1 6 3
//	   后序：7 8 4 9 0 5 2 6 3 1
//	*/
//
//	BiTree root;
//	InitTree(root);
//	// 分配根结点
//	root = (BiTree)malloc(sizeof(BiTNode));
//	root->data.value = '1';
//	root->lchild = NULL;
//	root->rchild = NULL;
//
//	// 第二层第一个节点。
//	BiTNode* secondOne = (BiTNode*)malloc(sizeof(BiTNode));
//	root->lchild = secondOne;
//	secondOne->data.value = '2';
//	secondOne->lchild = NULL;
//	secondOne->rchild = NULL;
//
//	// 第二层第二个节点。
//	BiTNode* secondTow = (BiTNode*)malloc(sizeof(BiTNode));
//	root->rchild = secondTow;
//	secondTow->data.value = '3';
//	secondTow->lchild = NULL;
//	secondTow->rchild = NULL;
//
//	// 第三层第一个节点。
//	BiTNode* thirdOne = (BiTNode*)malloc(sizeof(BiTNode));
//	secondOne->lchild = thirdOne;
//	thirdOne->data.value = '4';
//	thirdOne->lchild = NULL;
//	thirdOne->rchild = NULL;
//
//	// 第三层第二个节点。
//	BiTNode* thirdTow = (BiTNode*)malloc(sizeof(BiTNode));
//	secondOne->rchild = thirdTow;
//	thirdTow->data.value = '5';
//	thirdTow->lchild = NULL;
//	thirdTow->rchild = NULL;
//
//	// 第三层第三个节点。
//	BiTNode* thirdThree = (BiTNode*)malloc(sizeof(BiTNode));
//	secondTow->lchild = thirdThree;
//	thirdThree->data.value = '6';
//	thirdThree->lchild = NULL;
//	thirdThree->rchild = NULL;
//
//	// 第四层第一个节点。
//	BiTNode* forthOne = (BiTNode*)malloc(sizeof(BiTNode));
//	thirdOne->lchild = forthOne;
//	forthOne->data.value = '7';
//	forthOne->lchild = NULL;
//	forthOne->rchild = NULL;
//
//	// 第四层第二个节点。
//	BiTNode* forthTow = (BiTNode*)malloc(sizeof(BiTNode));
//	thirdOne->rchild = forthTow;
//	forthTow->data.value = '8';
//	forthTow->lchild = NULL;
//	forthTow->rchild = NULL;
//
//	// 第四层第三个节点。
//	BiTNode* forthThree = (BiTNode*)malloc(sizeof(BiTNode));
//	thirdTow->lchild = forthThree;
//	forthThree->data.value = '9';
//	forthThree->lchild = NULL;
//	forthThree->rchild = NULL;
//
//	// 第四层第四个节点。
//	BiTNode* forthFour = (BiTNode*)malloc(sizeof(BiTNode));
//	thirdTow->rchild = forthFour;
//	forthFour->data.value = '0';
//	forthFour->lchild = NULL;
//	forthFour->rchild = NULL;
//	return root;
//}
//
//// 先序递归创建树，这里注意参数的类型，T的类型是 "*&" ,如果是 "**" 代码稍加改动就OK...
//void CreateTree(BiTree& T) {   
//	char ch;
//	scanf("%c", &ch);
//	if (ch == ' ') T = NULL;    //这里首先判断是不是空格，如果是，则为该节点赋NULL
//	else {
//		T = (BiTree)malloc(sizeof(BiTNode));
//		T->data.value = ch;
//		CreateTree(T->lchild);
//		CreateTree(T->rchild);
//	}
//}
//
//// 栈的相关操作实现
//
//void InitStack(SeqStack& S) {
//	S.top = -1;			// 初始化栈顶指针
//}
//
//bool IsEmpty(SeqStack S) {
//	if (S.top == -1)	// 栈空
//		return true;
//	else
//		return false;
//}
//
//bool IsFull(SeqStack S) {
//	if (S.top == MAXSIZE - 1)
//		return true;
//	else
//		return false;
//}
//
//bool Push(SeqStack& S, BiTree T) {
//	if (IsFull(S))
//		return false;
//
//	S.top++;
//	S.data[S.top] = T;
//
//	return true;
//}
//
//bool Pop(SeqStack& S, BiTree& T) {
//	if (IsEmpty(S))
//		return false;
//
//	T = S.data[S.top];
//	S.top--;
//
//	return true;
//}
//
//bool GetTop(SeqStack& S, BiTree& T) {
//	if (IsEmpty(S))
//		return false;
//	T = S.data[S.top];
//	return true;
//}
//
//// 前序非递归
//void PreOrderNonRecursive(BiTree T) {
//	SeqStack S;
//	InitStack(S);
//	BiTree p;
//	p = T;
//	while (p != NULL || !IsEmpty(S)) {
//		while (p) {
//			visit(p);
//			Push(S, p);
//			p = p->lchild;
//		}
//		if (!IsEmpty(S)) {
//			Pop(S, p);
//			p = p->rchild;
//		}
//	}
//}
//
//// 中序非递归
//void InOrderNonRecursive(BiTree T) {
//	SeqStack S;
//	InitStack(S);
//	BiTree p;
//	p = T;
//	while (p != NULL || !IsEmpty(S)) {
//		while (p) {
//			//visit(p);
//			Push(S, p);
//			p = p->lchild;
//		}
//		if (!IsEmpty(S)) {
//			Pop(S, p);
//			visit(p);
//			p = p->rchild;
//		}
//	}
//}
//
//// 后序非递归
//void PostOrderNonRecursive(BiTree T) {
//	SeqStack S;
//	InitStack(S);
//	BiTree p;
//	BiTree r;	// 辅助指针，指向最近访问的点
//	p = T;
//	r = NULL;
//	while (p != NULL || !IsEmpty(S)) {
//		if (p) {			// p 不为 NULL，那就一直入栈，走到最左边
//			Push(S, p);		
//			p = p->lchild;
//		}
//		else {
//			// 向右
//			// 最左边左子树为NULL，那么看看右子树了
//			GetTop(S, p);	// 读取栈顶结点
//			if (p->rchild && p->rchild != r) {	// 若右子树存在且未被访问过
//				p = p->rchild;		// 转向右
//				Push(S, p);			// 入栈
//				p = p->lchild;		// 再走到最左，进入下一循环
//			}
//			else {			// 否则，弹出结点并访问
//				Pop(S, p);
//				visit(p);
//				r = p;		// 记录最近访问过的结点
//				p = NULL;	// 结点访问完后，重置p指针
//			}
//		}
//	}
//}
//
//
//void test_pre() {
//	BiTree root = CreateBiTree();
//	printf("非递归的先序遍历->:\n");
//	PreOrderNonRecursive(root);
//}
//
//void test_in() {
//	BiTree root = CreateBiTree();
//	printf("非递归的中序遍历->:\n");
//	InOrderNonRecursive(root);
//}
//
//void test_post() {
//	BiTree root = CreateBiTree();
//	printf("非递归的后序遍历->:\n");
//	PostOrderNonRecursive(root);
//}
//
//int main() {
//	// 前序：1 2 4 7 8 5 9 0 3 6
//	// 中序：7 4 8 2 9 5 0 1 6 3
//	// 后序：7 8 4 9 0 5 2 6 3 1
//	test_pre();
//	printf("\n");
//
//	test_in();
//	printf("\n");
//
//	test_post();
//	printf("\n");
//	return 0;
//}