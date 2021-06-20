#define _CRT_SECURE_NO_WARNINGS 1

// 二叉树的层次遍历

// 思想
// 1. 初始化一个辅助队列
// 2. 根结点入队
// 3. 若队列非空，则队头结点出队，访问该结点，并将其左右孩子入队（如果有的话）
// 4. 重复3直到队列为空

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	char value;
};

// 二叉树
typedef struct BiTNode {
	ElemType data;						// 数据域
	struct BiTNode* lchild, * rchild;	// 左右孩子指针
}BiTNode, * BiTree;


// 访问出队元素。
void visit(BiTNode* p);
// 二叉树层次遍历
void LevelOrder(BiTree T);

// 手动创建二叉树
void InitTree(BiTree& root);
BiTree CreateBiTree();


// 链式队列结点
typedef struct LinkNode {
	BiTNode* data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;	// 队头队尾指针
	int length;					// 记录长度
}LinkQueue;

// 队列基本操作 - 初始化/判空/入队/出队

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
	//if (Q.front == Q.rear == NULL) 这种写法不可取，判空会失败。
		return true;
	else
		return false;
}

bool EnQueue(LinkQueue& Q, BiTNode* x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) return false;
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) {	// 在空队列中插入第一个元素
		Q.front = s;
		Q.rear = s;
		Q.length = 1;
	}
	else {
		Q.rear->next = s;	// 新结点插入到rear后面
		Q.rear = s;			// rear指向新结点
		Q.length++;
	}
	return true;
}


BiTree DeQueue(LinkQueue& Q) {
	if (Q.front == NULL)
		return NULL;		// 空队
	LinkNode* p = Q.front;	// p指向此次出队的元素
	BiTree node = p->data;  // 用node返回队头元素
	Q.front = p->next;		// 修改front指针
	Q.length--;
	if (Q.rear == p) {		// 此次是最后一个结点
		Q.front = NULL;		// front指向NULL
		Q.rear = NULL;		// rear指向NULL
		Q.length = 0;
	}
	free(p);				// 释放结点空间
	return node;
}

// 访问出队元素。
void visit(BiTNode* p){
	printf("%c ", p->data.value);		// 访问出队元素就是把值输出来就OK了
}

void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);						// 初始化辅助队列
	BiTree p;
	EnQueue(Q, T);						// 将根结点入队
	while (!IsEmpty(Q)) {				// 队列不为空就循环
		p = DeQueue(Q);					// 队头结点出队
		visit(p);						// 访问出队结点
		if (p->lchild != NULL)			
			EnQueue(Q, p->lchild);		// 左孩子入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);		// 右孩子入队
	}
}


void InitTree(BiTree& root) {
	root = NULL;
}


BiTree CreateBiTree() {

	/*
	// 手工构造一个如下结构的二叉树。
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
	// 分配根结点
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data.value = '1';
	root->lchild = NULL;
	root->rchild = NULL;

	// 第二层第一个节点。
	BiTNode* secondOne = (BiTNode*)malloc(sizeof(BiTNode));
	root->lchild = secondOne;
	secondOne->data.value = '2';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;

	// 第二层第二个节点。
	BiTNode* secondTow = (BiTNode*)malloc(sizeof(BiTNode));
	root->rchild = secondTow;
	secondTow->data.value = '3';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;

	// 第三层第一个节点。
	BiTNode* thirdOne = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = '4';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;

	// 第三层第二个节点。
	BiTNode* thirdTow = (BiTNode*)malloc(sizeof(BiTNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = '5';
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;

	// 第三层第三个节点。
	BiTNode* thirdThree = (BiTNode*)malloc(sizeof(BiTNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = '6';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;

	// 第四层第一个节点。
	BiTNode* forthOne = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->lchild = forthOne;
	forthOne->data.value = '7';
	forthOne->lchild = NULL;
	forthOne->rchild = NULL;

	// 第四层第二个节点。
	BiTNode* forthTow = (BiTNode*)malloc(sizeof(BiTNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = '8';
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;

	// 第四层第三个节点。
	BiTNode* forthThree = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->lchild = forthThree;
	forthThree->data.value = '9';
	forthThree->lchild = NULL;
	forthThree->rchild = NULL;

	// 第四层第四个节点。
	BiTNode* forthFour = (BiTNode*)malloc(sizeof(BiTNode));
	thirdTow->rchild = forthFour;
	forthFour->data.value = '0';
	forthFour->lchild = NULL;
	forthFour->rchild = NULL;

	return root;
}


int main() {

	BiTree root = CreateBiTree();

	// 二叉树层次遍历。
	printf("层次遍历结果：");
	LevelOrder(root); 
	printf("\n");
	return 0;
}