#define _CRT_SECURE_NO_WARNINGS 1

// �������Ĳ�α���

// ˼��
// 1. ��ʼ��һ����������
// 2. ��������
// 3. �����зǿգ����ͷ�����ӣ����ʸý�㣬���������Һ�����ӣ�����еĻ���
// 4. �ظ�3ֱ������Ϊ��

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	char value;
};

// ������
typedef struct BiTNode {
	ElemType data;						// ������
	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
}BiTNode, * BiTree;


// ���ʳ���Ԫ�ء�
void visit(BiTNode* p);
// ��������α���
void LevelOrder(BiTree T);

// �ֶ�����������
void InitTree(BiTree& root);
BiTree CreateBiTree();


// ��ʽ���н��
typedef struct LinkNode {
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;	// ��ͷ��βָ��
	int length;					// ��¼����
}LinkQueue;

// ���л������� - ��ʼ��/�п�/���/����

void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool EnQueue(LinkQueue& Q, BiTNode x);
BiTree DeQueue(LinkQueue& Q);

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = NULL;
	Q.length = 0;
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear && Q.rear == NULL)
	//if (Q.front == Q.rear == NULL) ����д������ȡ���пջ�ʧ�ܡ�
		return true;
	else
		return false;
}

bool EnQueue(LinkQueue& Q, BiTNode* x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// �ڿն����в����һ��Ԫ��
		Q.front = s;
		Q.rear = s;
		Q.length = 1;
	}
	else {
		Q.rear->next = s;	// �½����뵽rear����
		Q.rear = s;			// rearָ���½��
		Q.length++;
	}
	return true;
}


BiTree DeQueue(LinkQueue& Q) {
	if (Q.front == NULL)
		return NULL;		// �ն�
	LinkNode* p = Q.front;	// pָ��˴γ��ӵ�Ԫ��
	BiTree node = p->data;  // ��node���ض�ͷԪ��
	Q.front = p->next;		// �޸�frontָ��
	Q.length--;
	if (Q.rear == p) {		// �˴������һ�����
		Q.front = NULL;		// frontָ��NULL
		Q.rear = NULL;		// rearָ��NULL
		Q.length = 0;
	}
	free(p);				// �ͷŽ��ռ�
	return node;
}

// ���ʳ���Ԫ�ء�
void visit(BiTNode* p){
	printf("%c ", p->data.value);		// ���ʳ���Ԫ�ؾ��ǰ�ֵ�������OK��
}

void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);						// ��ʼ����������
	BiTree p;
	EnQueue(Q, T);						// ����������
	while (!IsEmpty(Q)) {				// ���в�Ϊ�վ�ѭ��
		p = DeQueue(Q);					// ��ͷ������
		visit(p);						// ���ʳ��ӽ��
		if (p->lchild != NULL)			
			EnQueue(Q, p->lchild);		// �������
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);		// �Һ������
	}
}


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


int main() {

	BiTree root = CreateBiTree();

	// ��������α�����
	printf("��α��������");
	LevelOrder(root); 
	printf("\n");
	return 0;
}