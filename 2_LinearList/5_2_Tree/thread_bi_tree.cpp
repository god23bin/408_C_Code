#define _CRT_SECURE_NO_WARNINGS 1

// 线索二叉树

#include <stdio.h>
#include <stdlib.h>

struct ElemType {
	char value;
};

 //普通二叉树
typedef struct BiTNode {
	ElemType data;						// 数据域
	struct BiTNode* lchild, * rchild;	// 左右孩子指针
}BiTNode, * BiTree;

// 线索二叉树
typedef struct ThreadNode {
	ElemType data;						// 数据域
	struct ThreadNode* lchild, * rchild;	// 左右孩子指针
	int ltag, rtag;						// 左右线索标志 ，tag==0表示指向孩子，tag==1表示指向线索
}ThreadNode, * ThreadTree;


// ------------------------普通二叉树------------------------
// 访问出队元素。
void visit(BiTNode* p);

// 先序、中序、后序遍历
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

// 普通查找前驱
// 找指定结点p的中序遍历的前驱
// 思路：从根结点出发，重新进行依次中序遍历，指针q记录当前访问的结点，指针pre记录上一个被访问的结点
// 当q==p时，pre为所找的前驱
// 当q!=p时，那么pre就指向当前q指向的结点，q指向下一个被访问的结点

// 辅助全局变量，用于查找结点p的前驱
BiTNode* p;
BiTNode* pre = NULL;
BiTNode* res = NULL;
void FindInOrderPriorOf(BiTNode* p);

void InitTree(BiTree& root);
BiTree CreateBiTree();

// ------------------------普通二叉树------------------------
// 
// ------------------------线索二叉树------------------------

// 与普通的pre区别开，这里写成preT
ThreadNode* preT = NULL;

void visitT(ThreadNode* p);

// 中序遍历二叉树，一遍遍历，一遍线索化
void InThread(ThreadTree T);
// 先序遍历二叉树，一遍遍历，一遍线索化
void PreThread(ThreadTree T);
// 后序遍历二叉树，一遍遍历，一遍线索化
void PostThread(ThreadTree T);

void VisitAndFindPre(ThreadNode* q);

// 中序线索化二叉树T
void CreateInThread(ThreadTree T);
// 先序线索化二叉树T
void CreatePreThread(ThreadTree T);
// 后序线索化二叉树T
void CreatePostThread(ThreadTree T);

// 找中序后继
// 1 - 找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode* FirstNode(ThreadNode* p);
// 2 - 在中序线索二叉树中找到结点p的后继结点
ThreadNode* NextNode(ThreadNode* p);

// 对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode* T);

// 找中序前驱
// 1 - 找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode* LastNode(ThreadNode* p);
// 2 - 在中序线索二叉树中找到结点p的前驱结点
ThreadNode* PreNode(ThreadNode* p);

// 对中序线索二叉树进行    逆向的   中序遍历（利用线索实现的非递归算法）
void RevInorder(ThreadNode* T);

// 找先序后继
// 1 - 找到以p为根的子树中，第一个被先序遍历的结点
ThreadNode* FirstNodeWithPre(ThreadNode* p);
// 2 - 在先序线索二叉树中找到结点p的后继结点
ThreadNode* NextNodeWithPre(ThreadNode* p);

// 找先序前驱


// 找后序后继



// 找后序前驱
ThreadNode* FirstNodeWithPost(ThreadNode* p);

ThreadNode* NextNodeWithPost(ThreadNode* p);


// 初步建成树，ltag、rtag = 0
void InitThreadTree(ThreadTree& root);
ThreadTree CreateThreadTree();

// ------------------------线索二叉树------------------------

// ------------------------普通二叉树函数实现------------------------

// 访问出队元素。
void visit(BiTNode* q) {
	printf("%c ", q->data.value);		// 访问出队元素就是把值输出来就OK了
}

void visitAndRecord(BiTNode* q) {
	if (q == p) {
		res = pre;						// 找到p的前驱
		printf("%c", res->data.value);
	}
	else {
		pre = q;						// pre指向当前访问的结点
	}
}

void PreOrder(BiTree T) {
	if (T != NULL) {
		visit(T);				// 访问根结点
		PreOrder(T->lchild);	// 递归遍历左子树
		PreOrder(T->rchild);	// 递归遍历右子树
	}
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);		// 递归遍历左子树
		visit(T);				// 访问根结点
		InOrder(T->rchild);		// 递归遍历右子树
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);	// 递归遍历左子树
		PostOrder(T->rchild);	// 递归遍历右子树
		visit(T);				// 访问根结点
	}
}

// 普通查找前驱
void FindInOrderPriorOf(BiTNode* p) {
	if (p != NULL) {
		InOrder(p->lchild);		// 递归遍历左子树
		visitAndRecord(p);				// 访问根结点
		InOrder(p->rchild);		// 递归遍历右子树
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

	   中序：7 4 8 2 9 5 0 1 6 3
	   6的中序前驱是1，就是根结点，那么返回个6这个结点的地址回去，好让我们操作
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

// ------------------------普通二叉树函数实现------------------------

// ------------------------线索二叉树函数实现------------------------

void visitT(ThreadNode* p) {
	printf("%c ", p->data.value);		// 访问出队元素就是把值输出来就OK了
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
		VisitAndFindPre(T);		// 先处理根结点
		//PreThread(T->lchild);	// 会陷入循环
		if (T->ltag == 0)		// lchild不是前驱线索，才继续线索化。因为这里左孩子是线索化的化，左孩子就指向前驱结点，那么执行左孩子线索化，就会去前驱结点，然后就进入循环了。
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
	if (q->lchild == NULL) {	// 左子树为空，建立前驱线索
		q->lchild = preT;
		q->ltag = 1;
	}
	if (preT != NULL && preT->rchild == NULL) {
		preT->rchild = q;		// 建立前驱结点的后继线索
		preT->rtag = 1;
	}
	preT = q;
}

void CreateInThread(ThreadTree T) {
	preT = NULL;					// preT 初始化为NULL
	if (T != NULL) {
		InThread(T);				// 中序线索化二叉树
		if (preT->rchild == NULL)
			preT->rtag = 1;			// 处理遍历的最后一个结点
	}
}

void CreatePreThread(ThreadTree T) {
	preT = NULL;					// preT 初始化为NULL
	if (T != NULL) {
		PreThread(T);				// 先序线索化二叉树
		if (preT->rchild == NULL)
			preT->rtag = 1;			// 处理遍历的最后一个结点
	}
}

void CreatePostThread(ThreadTree T) {
	preT = NULL;					// preT 初始化为NULL
	if (T != NULL) {
		PostThread(T);				// 先序线索化二叉树
		if (preT->rchild == NULL)
			preT->rtag = 1;			// 处理遍历的最后一个结点
	}
}

ThreadNode* FirstNode(ThreadNode* p) {
	// 循环找到最左下结点（不一定是叶子结点）
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

ThreadNode* NextNode(ThreadNode* p) {
	// 右子树中最左下的结点
	if (p->rtag == 0)
		return FirstNode(p->rchild);
	else
		return p->rchild;	// rtag == 1直接返回后继线索
}

// 对整个中序线索二叉树中序遍历，空间复杂度O(1)
void Inorder(ThreadNode* T) {
	for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
		visitT(p);
}

ThreadNode* LastNode(ThreadNode* p) {
	// 循环找到最右下的结点（不一定是叶子结点）
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

ThreadNode* PreNode(ThreadNode* p) {
	// 左子树中最右下结点
	if (p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;	// rtag == 1直接返回前驱线索
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
		return p->rchild;	// rtag == 1直接返回后继线索
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
	// 手工构造一个如下结构的二叉树。
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
	// 分配根结点
	root = (ThreadTree)malloc(sizeof(ThreadNode));
	root->data.value = 'A';
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;
	root->rtag = 0;

	// 第二层第一个节点。
	ThreadNode* secondOne = (ThreadNode*)malloc(sizeof(ThreadNode));
	root->lchild = secondOne;
	secondOne->data.value = 'B';
	secondOne->lchild = NULL;
	secondOne->rchild = NULL;
	secondOne->ltag = 0;
	secondOne->rtag = 0;

	// 第二层第二个节点。
	ThreadNode* secondTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	root->rchild = secondTow;
	secondTow->data.value = 'C';
	secondTow->lchild = NULL;
	secondTow->rchild = NULL;
	secondTow->ltag = 0;
	secondTow->rtag = 0;

	// 第三层第一个节点。
	ThreadNode* thirdOne = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondOne->lchild = thirdOne;
	thirdOne->data.value = 'D';
	thirdOne->lchild = NULL;
	thirdOne->rchild = NULL;
	thirdOne->ltag = 0;
	thirdOne->rtag = 0;

	// 第三层第二个节点。
	ThreadNode* thirdTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondOne->rchild = thirdTow;
	thirdTow->data.value = 'E';
	thirdTow->lchild = NULL;
	thirdTow->rchild = NULL;
	thirdTow->ltag = 0;
	thirdTow->rtag = 0;

	// 第三层第三个节点。
	ThreadNode* thirdThree = (ThreadNode*)malloc(sizeof(ThreadNode));
	secondTow->lchild = thirdThree;
	thirdThree->data.value = 'F';
	thirdThree->lchild = NULL;
	thirdThree->rchild = NULL;
	thirdThree->ltag = 0;
	thirdThree->rtag = 0;

	// 第四层第二个节点。
	ThreadNode* forthTow = (ThreadNode*)malloc(sizeof(ThreadNode));
	thirdOne->rchild = forthTow;
	forthTow->data.value = 'G';
	forthTow->lchild = NULL;
	forthTow->rchild = NULL;
	forthTow->ltag = 0;
	forthTow->rtag = 0;

	return root;
}

// ------------------------线索二叉树函数实现------------------------


void testNormal() {
	BiTNode x6;
	BiTree root = CreateBiTree();
	//printf("先序遍历->:\n");
	//PreOrder(root);
	//printf("\n");

	printf("中序遍历->:\n");
	InOrder(root);
	printf("\n");

	printf("中序遍历的6的中序前驱是->:\n");
	FindInOrderPriorOf(&x6);

	//printf("后序遍历->:\n");
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