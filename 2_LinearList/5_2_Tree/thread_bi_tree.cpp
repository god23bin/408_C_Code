#define _CRT_SECURE_NO_WARNINGS 1

// ����������

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	char value;
};

 //��ͨ������
typedef struct BiTNode {
	ElemType data;						// ������
	struct BiTNode* lchild, * rchild;	// ���Һ���ָ��
}BiTNode, * BiTree;

// ����������
typedef struct ThreadNode {
	ElemType data;						// ������
	struct ThreadNode* lchild, * rchild;	// ���Һ���ָ��
	int ltag, rtag;						// ����������־ ��tag==0��ʾָ���ӣ�tag==1��ʾָ������
}ThreadNode, * ThreadTree;


// ------------------------��ͨ������------------------------
// ���ʳ���Ԫ�ء�
void visit(BiTNode* p);

// �������򡢺������
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

// ��ͨ����ǰ��
// ��ָ�����p�����������ǰ��
// ˼·���Ӹ������������½����������������ָ��q��¼��ǰ���ʵĽ�㣬ָ��pre��¼��һ�������ʵĽ��
// ��q==pʱ��preΪ���ҵ�ǰ��
// ��q!=pʱ����ôpre��ָ��ǰqָ��Ľ�㣬qָ����һ�������ʵĽ��

// ����ȫ�ֱ��������ڲ��ҽ��p��ǰ��
BiTNode* p;
BiTNode* pre = NULL;
BiTNode* res = NULL;
void FindInOrderPriorOf(BiTNode* p);

void InitTree(BiTree& root);
BiTree CreateBiTree();

// ------------------------��ͨ������------------------------
// 
// ------------------------����������------------------------

// ����ͨ��pre���𿪣�����д��preT
ThreadNode* preT = NULL;

void visitT(ThreadNode* p);

// ���������������һ�������һ��������
void InThread(ThreadTree T);
// ���������������һ�������һ��������
void PreThread(ThreadTree T);
// ���������������һ�������һ��������
void PostThread(ThreadTree T);

void VisitAndFindPre(ThreadNode* q);

// ����������������T
void CreateInThread(ThreadTree T);
// ����������������T
void CreatePreThread(ThreadTree T);
// ����������������T
void CreatePostThread(ThreadTree T);

// ��������
// 1 - �ҵ���pΪ���������У���һ������������Ľ��
ThreadNode* FirstNode(ThreadNode* p);
// 2 - �������������������ҵ����p�ĺ�̽��
ThreadNode* NextNode(ThreadNode* p);

// �������������������������������������ʵ�ֵķǵݹ��㷨��
void Inorder(ThreadNode* T);

// ������ǰ��
// 1 - �ҵ���pΪ���������У����һ������������Ľ��
ThreadNode* LastNode(ThreadNode* p);
// 2 - �������������������ҵ����p��ǰ�����
ThreadNode* PreNode(ThreadNode* p);

// ��������������������    �����   �����������������ʵ�ֵķǵݹ��㷨��
void RevInorder(ThreadNode* T);

// ��������
// 1 - �ҵ���pΪ���������У���һ������������Ľ��
ThreadNode* FirstNodeWithPre(ThreadNode* p);
// 2 - �������������������ҵ����p�ĺ�̽��
ThreadNode* NextNodeWithPre(ThreadNode* p);

// ������ǰ��


// �Һ�����



// �Һ���ǰ��
ThreadNode* FirstNodeWithPost(ThreadNode* p);

ThreadNode* NextNodeWithPost(ThreadNode* p);


// ������������ltag��rtag = 0
void InitThreadTree(ThreadTree& root);
ThreadTree CreateThreadTree();

// ------------------------����������------------------------

// ------------------------��ͨ����������ʵ��------------------------

// ���ʳ���Ԫ�ء�
void visit(BiTNode* q) {
	printf("%c ", q->data.value);		// ���ʳ���Ԫ�ؾ��ǰ�ֵ�������OK��
}

void visitAndRecord(BiTNode* q) {
	if (q == p) {
		res = pre;						// �ҵ�p��ǰ��
		printf("%c", res->data.value);
	}
	else {
		pre = q;						// preָ��ǰ���ʵĽ��
	}
}

void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);				// ���ʸ����
		PreOrder(T->lchild);	// �ݹ����������
		PreOrder(T->rchild);	// �ݹ����������
	}
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);		// �ݹ����������
		visit(T);				// ���ʸ����
		InOrder(T->rchild);		// �ݹ����������
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);	// �ݹ����������
		PostOrder(T->rchild);	// �ݹ����������
		visit(T);				// ���ʸ����
	}
}

// ��ͨ����ǰ��
void FindInOrderPriorOf(BiTNode* p) {
	if (p != NULL) {
		InOrder(p->lchild);		// �ݹ����������
		visitAndRecord(p);				// ���ʸ����
		InOrder(p->rchild);		// �ݹ����������
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

	   ����7 4 8 2 9 5 0 1 6 3
	   6������ǰ����1�����Ǹ���㣬��ô���ظ�6������ĵ�ַ��ȥ���������ǲ���
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

// ------------------------��ͨ����������ʵ��------------------------

// ------------------------��������������ʵ��------------------------

void visitT(ThreadNode* p) {
	printf("%c ", p->data.value);		// ���ʳ���Ԫ�ؾ��ǰ�ֵ�������OK��
}

void InThread(ThreadTree T) {
	if (T != NULL) {
		InThread(T->lchild);
		VisitAndFindPre(T);
		InThread(T->rchild);
	}
}

void PreThread(ThreadTree T) {
	if (T != NULL) {
		VisitAndFindPre(T);		// �ȴ�������
		//PreThread(T->lchild);	// ������ѭ��
		if (T->ltag == 0)		// lchild����ǰ���������ż�������������Ϊ�����������������Ļ������Ӿ�ָ��ǰ����㣬��ôִ���������������ͻ�ȥǰ����㣬Ȼ��ͽ���ѭ���ˡ�
			PreThread(T->lchild);
		PreThread(T->rchild);
	}
}

void PostThread(ThreadTree T) {
	if (T != NULL) {
		PostThread(T->lchild);
		PostThread(T->rchild);
		VisitAndFindPre(T);
	}
}

void VisitAndFindPre(ThreadNode* q) {
	if (q->lchild == NULL) {	// ������Ϊ�գ�����ǰ������
		q->lchild = preT;
		q->ltag = 1;
	}
	if (preT != NULL && preT->rchild == NULL) {
		preT->rchild = q;		// ����ǰ�����ĺ������
		preT->rtag = 1;
	}
	preT = q;
}

void CreateInThread(ThreadTree T) {
	preT = NULL;					// preT ��ʼ��ΪNULL
	if (T != NULL) {
		InThread(T);				// ����������������
		if (preT->rchild == NULL)
			preT->rtag = 1;			// ������������һ�����
	}
}

void CreatePreThread(ThreadTree T) {
	preT = NULL;					// preT ��ʼ��ΪNULL
	if (T != NULL) {
		PreThread(T);				// ����������������
		if (preT->rchild == NULL)
			preT->rtag = 1;			// ������������һ�����
	}
}

void CreatePostThread(ThreadTree T) {
	preT = NULL;					// preT ��ʼ��ΪNULL
	if (T != NULL) {
		PostThread(T);				// ����������������
		if (preT->rchild == NULL)
			preT->rtag = 1;			// ������������һ�����
	}
}

ThreadNode* FirstNode(ThreadNode* p) {
	// ѭ���ҵ������½�㣨��һ����Ҷ�ӽ�㣩
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadNode* NextNode(ThreadNode* p) {
	// �������������µĽ��
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;	// rtag == 1ֱ�ӷ��غ������
}

// ������������������������������ռ临�Ӷ�O(1)
void Inorder(ThreadNode* T) {
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visitT(p);
}

ThreadNode* LastNode(ThreadNode* p) {
	// ѭ���ҵ������µĽ�㣨��һ����Ҷ�ӽ�㣩
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

ThreadNode* PreNode(ThreadNode* p) {
	// �������������½��
	if (p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;	// rtag == 1ֱ�ӷ���ǰ������
}

void RevInorder(ThreadNode* T) {
	for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
		visitT(p);
}

ThreadNode* FirstNodeWithPre(ThreadNode* p) {
	return p->lchild;
}

ThreadNode* NextNodeWithPre(ThreadNode* p) {
	if (p->ltag == 0)
		return FirstNodeWithPre(p);
	else
		return p->rchild;	// rtag == 1ֱ�ӷ��غ������
}


ThreadNode* FirstNodeWithPost(ThreadNode* p) {
	return p->rchild;
}

ThreadNode* NextNodeWithPost(ThreadNode* p) {
	if (p->rtag == 0)
		return FirstNodeWithPost(p);
	else
		return p->lchild;
}



void InitThreadTree(ThreadTree& root) {
	root = NULL;
}

ThreadTree CreateThreadTree() {

	/*
	// �ֹ�����һ�����½ṹ�Ķ�������
			   A
			/     \
		   B       C
		  / \     / \
		 D   E   F
		/ \ / \ / \
	      G  
		 / \

	*/

	ThreadTree root;
	InitThreadTree(root);
	// ��������
	root = (ThreadTree)malloc(sizeof(ThreadNode));
	root->data.value = 'A';
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;
	root->rtag = 0;

	// �ڶ����һ���ڵ㡣
	ThreadNode* secondOne = (ThreadNode*)malloc(sizeof(ThreadNode));
	root->lchild = secondOne;
	secondOne->data.value = 'B';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;
	secondOne->ltag = 0;
	secondOne->rtag = 0;

	// �ڶ���ڶ����ڵ㡣
	ThreadNode* secondTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	root->rchild = secondTow;
	secondTow->data.value = 'C';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;
	secondTow->ltag = 0;
	secondTow->rtag = 0;

	// �������һ���ڵ㡣
	ThreadNode* thirdOne = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = 'D';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;
	thirdOne->ltag = 0;
	thirdOne->rtag = 0;

	// ������ڶ����ڵ㡣
	ThreadNode* thirdTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = 'E';
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;
	thirdTow->ltag = 0;
	thirdTow->rtag = 0;

	// ������������ڵ㡣
	ThreadNode* thirdThree = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = 'F';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;
	thirdThree->ltag = 0;
	thirdThree->rtag = 0;

	// ���Ĳ�ڶ����ڵ㡣
	ThreadNode* forthTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = 'G';
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;
	forthTow->ltag = 0;
	forthTow->rtag = 0;

	return root;
}

// ------------------------��������������ʵ��------------------------


void testNormal() {
	BiTNode x6;
	BiTree root = CreateBiTree();
	//printf("�������->:\n");
	//PreOrder(root);
	//printf("\n");

	printf("�������->:\n");
	InOrder(root);
	printf("\n");

	printf("���������6������ǰ����->:\n");
	FindInOrderPriorOf(&x6);

	//printf("�������->:\n");
	//PostOrder(root);
	//printf("\n");
}

void testThreed() {
	ThreadTree root = CreateThreadTree();
	CreateInThread(root);
	CreatePreThread(root);
	CreatePostThread(root);
}

int main() {
	//testNormal();

	return 0;
}