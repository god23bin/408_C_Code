#define _CRT_SECURE_NO_WARNINGS 1

// 单链表的实现

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 定义单链表结点类型
typedef struct LNode {
	ElemType data;			// 数据域
	struct LNode* next;		// 指针域
}LNode, * LinkList;

// 初始化链表(带头结点)
bool InitList(LinkList& L);

// 插入操作
bool ListInsert(LinkList& L, int i, ElemType e);
bool ListInsertWithNoHead(LinkList& L, int i, ElemType e);
// 指定结点的后插操作
bool InsertNextNode(LNode* p, ElemType e);
// 指定结点的前插操作
bool InsertPriorNode2(LNode* p, ElemType e);
bool InsertPriorNode3(LNode* p, LNode* s);

// 按位序删除
bool ListDelete(LinkList& L, int i, ElemType& e);
// 指定结点删除
bool DeleteNode(LNode* p);

// 按位查找
LNode* GetElem(LinkList L, int i);
// 按值查找
LNode* LocateElem(LinkList L, ElemType e);
// 求表的长度
int ListLength(LinkList L);

// 头插法建立单链表
LinkList ListHeadInsert(LinkList& L);
// 尾插法建立单链表
LinkList ListTailInsert(LinkList& L);

// 打印链表
void PrintList(LinkList& L);


// 初始化链表(带头结点)
bool InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) return false;
	L->next = NULL;
	return true;
}

// 插入结点操作
// 思路是什么呢？
// 首先，你一个新结点，要插入到i位置上，那么就需要找到它的前驱，即第i-1个结点
// 然后，在其后插入新结点

// - 带头结点的插入
bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1) return false;

	LNode* p;	// 指针p指向当前扫描到的结点
	int j = 0;	// 变量j用来记录当前p指向的是第j个结点
	p = L;		// 指向L，L指向头结点，此时p也指向了头结点，头结点是第0个结点

	while (p != NULL && j < i - 1) {	// 循环找到第i-1个结点
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));	// 搞定新结点
	if (s == NULL) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//bool ListInsert(LinkList& L, int i, ElemType e) {
//	LNode*p = GetElem(L, i - 1);
//	return InsertNextNode(p, e);
//}

// - 不带头结点的插入
bool ListInsertWithNoHead(LinkList& L, int i, ElemType e) {
	if (i < 1) return false;

	if (i == 1) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL) return false;
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//bool ListInsertWithNoHead(LinkList& L, int i, ElemType e) {
//	if (i < 1) return false;
//
//	if (i == 1) {
//		LNode* s = (LNode*)malloc(sizeof(LNode));
//		if (s == NULL) return false;
//		s->data = e;
//		s->next = L;
//		L = s;
//		return true;
//	}
//	LNode* p = GetElem(L, i - 1);
//	return InsertNextNode(p, e);
//}

// 指定结点的后插操作
bool InsertNextNode(LNode* p, ElemType e) {
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
// 指定结点的前插操作
// 思路就是，先直接后插，然后交换值，就等价于我们进行了前插了
bool InsertPriorNode2(LNode* p, ElemType e) {
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;
	s->next = p->next;
	p->next = s;
	// 交换值的感觉
	s->data = p->data;	// 将p中数据给s
	p->data = e;		// 将p中数据改为e
	return true;
}
// 给新结点，也是，直接后插，然后交换值，就等价于前插了
bool InsertPriorNode3(LNode* p, LNode* s) {
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	p->next = s;
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
}

// 按位序删除
// - 带头结点 
bool ListDelete(LinkList& L, int i, ElemType& e) {
	if (i < 1) return false;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1) {	// 找到第i-1个结点
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	if (p->next == NULL) return false;	// 第i-1个结点的next为NULL的话，说明第i个结点为NULL，也就是没有第i个结点，返回false
	LNode* q = p->next;			// 第i个结点
	e = q->data;				// 赋值给e，作为返回值
	p->next = q->next;			// 直接让第i-1个结点指向第i结点的下一个结点
	free(q);					// 释放第i个结点，即删除掉这个结点
	return true;
}


// 指定结点删除
// 思路：找要删除结点的前驱结点
// 但是，找不到前驱，那么我们还是按照前插操作的那种来，直接找后继，赋值过来，就相当于删除了
bool DeleteNode(LNode* p) {		// 要删除的结点 p
	if (p == NULL) return false;
	LNode* q = p->next;			// q 指向 p 的下一个结点
	p->data = p->next->data;	// q 的 data 赋值给 p
	p->next = q->next;			// p 指向 q 的下一个结点
	free(q);					// 释放q
	return true;
}

// 按位查找
LNode* GetElem(LinkList L, int i) {
	if (i < 0) return NULL;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// 按值查找
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {		// 如果ElemType是结构体，就得具体进行比较了
		p = p->next;
	}
	return p;
}

// 求表的长度
int ListLength(LinkList& L) {
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

// 头插法建立单链表
LinkList ListHeadInsert(LinkList& L) {

	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));	// 创建头结点
	if (L == NULL) return L;
	L->next = NULL;							// 初始化为空链表
	scanf("%d", &x);						// 输入结点的值
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));	// 创建新结点
		if (s == NULL) return L;
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

// 尾插法建立单链表
LinkList ListTailInsert(LinkList& L) {
	// 设置表尾指针 r，直接在它后面进行后插操作
	int x;
	L = (LinkList)malloc(sizeof(LNode));	// 创建头结点
	if (L == NULL) return L;
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL) return L;
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 打印链表
void PrintList(LinkList& L) {
	LNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void test() {
	LinkList L;
	LNode* LNode;
	ElemType e;
	int i = 0;
	InitList(L);

	//printf("使用头插法插入元素中，请输入插入的元素->：\n");
	//L = ListHeadInsert(L);

	printf("使用尾插法插入元素中，请输入插入的元素->：\n");
	L = ListTailInsert(L);

	PrintList(L);

	e = 23;
	i = 5;
	ListInsert(L, i, e);
	printf("在第 %d 个位置插入：%d\n", i, e);

	PrintList(L);

	i = 2;
	ListDelete(L, i, e);
	printf("删除第 %d 个位置的元素 %d \n", i, e);

	PrintList(L);

	e = 3;
	LNode = LocateElem(L, e);
	printf("按值查找->值为%d的元素，已查找到该元素\n", LNode->data);

	i = 5;
	LNode = GetElem(L, i);
	printf("按位查找->第%d位元素，已查找到该元素，值为%d\n", i, LNode->data);

	ListDelete(L, i, e);
	printf("按位删除->第%d位元素，已删除该元素，值为%d\n", i, e);
	PrintList(L);
}

// 1.解答
void Del_X_3(LinkList& L, ElemType x) {
	// 递归实现在单链表L中删除值为x的结点
	LNode* p;					// p指向待删除结点
	if (L == NULL) return;		// 递归出口
	if (L->data == x) {			// 若L所指结点的值为x
		p = L;					// 删除* L， 并让L指向下一结点
		L = L->next;
		free(p);
		Del_X_3(L, x);			// 递归调用
	}
	else {						// 若L所指结点的值不为x
		Del_X_3(L->next, x);	// 递归调用
	}
}

// 2. 解答
// 用p从头至尾扫描单链表，pre指向*p结点的前驱。若p所指向结点的值为x，则删除，并让p移向下一个结点
// 否则让pre、p指针同步后移一个结点。
void Del_X_1(LinkList& L, ElemType x) {
	// L为带头结点的单链表
	LNode* p = L->next, * pre = L, * q;	// 置p和pre的初始值
	while (p != NULL) {
		if (p->data == x) {
			q = p;			// q 指向该结点
			p = p->next;
			pre->next = p;	// 删除 q 指向的结点
			free(q);
		}
		else {
			// p指向的结点的数据不为x，就进行移动，移到下一位
			pre = p;
			p = p->next;
		}
	}
}

// 3. 解答
void R_Print(LinkList L) {
	// 从尾到头输出单链表L中的每个结点的值
	if (L->next != NULL) {
		R_Print(L->next);		// 递归
	}
	if (L != NULL) printf("%d ", L->data);
}

int main() {
	test();
	return 0;
}