#define _CRT_SECURE_NO_WARNINGS 1

// �������ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// ���嵥����������
typedef struct LNode {
	ElemType data;			// ������
	struct LNode* next;		// ָ����
}LNode, * LinkList;

// ��ʼ������(��ͷ���)
bool InitList(LinkList& L);

// �������
bool ListInsert(LinkList& L, int i, ElemType e);
bool ListInsertWithNoHead(LinkList& L, int i, ElemType e);
// ָ�����ĺ�����
bool InsertNextNode(LNode* p, ElemType e);
// ָ������ǰ�����
bool InsertPriorNode2(LNode* p, ElemType e);
bool InsertPriorNode3(LNode* p, LNode* s);

// ��λ��ɾ��
bool ListDelete(LinkList& L, int i, ElemType& e);
// ָ�����ɾ��
bool DeleteNode(LNode* p);

// ��λ����
LNode* GetElem(LinkList L, int i);
// ��ֵ����
LNode* LocateElem(LinkList L, ElemType e);
// ���ĳ���
int ListLength(LinkList L);

// ͷ�巨����������
LinkList ListHeadInsert(LinkList& L);
// β�巨����������
LinkList ListTailInsert(LinkList& L);

// ��ӡ����
void PrintList(LinkList& L);


// ��ʼ������(��ͷ���)
bool InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) return false;
	L->next = NULL;
	return true;
}

// ���������
// ˼·��ʲô�أ�
// ���ȣ���һ���½�㣬Ҫ���뵽iλ���ϣ���ô����Ҫ�ҵ�����ǰ��������i-1�����
// Ȼ�����������½��

// - ��ͷ���Ĳ���
bool ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1) return false;

	LNode* p;	// ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;	// ����j������¼��ǰpָ����ǵ�j�����
	p = L;		// ָ��L��Lָ��ͷ��㣬��ʱpҲָ����ͷ��㣬ͷ����ǵ�0�����

	while (p != NULL && j < i - 1) {	// ѭ���ҵ���i-1�����
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));	// �㶨�½��
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

// - ����ͷ���Ĳ���
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

// ָ�����ĺ�����
bool InsertNextNode(LNode* p, ElemType e) {
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
// ָ������ǰ�����
// ˼·���ǣ���ֱ�Ӻ�壬Ȼ�󽻻�ֵ���͵ȼ������ǽ�����ǰ����
bool InsertPriorNode2(LNode* p, ElemType e) {
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false;
	s->next = p->next;
	p->next = s;
	// ����ֵ�ĸо�
	s->data = p->data;	// ��p�����ݸ�s
	p->data = e;		// ��p�����ݸ�Ϊe
	return true;
}
// ���½�㣬Ҳ�ǣ�ֱ�Ӻ�壬Ȼ�󽻻�ֵ���͵ȼ���ǰ����
bool InsertPriorNode3(LNode* p, LNode* s) {
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	p->next = s;
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
}

// ��λ��ɾ��
// - ��ͷ��� 
bool ListDelete(LinkList& L, int i, ElemType& e) {
	if (i < 1) return false;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1) {	// �ҵ���i-1�����
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	if (p->next == NULL) return false;	// ��i-1������nextΪNULL�Ļ���˵����i�����ΪNULL��Ҳ����û�е�i����㣬����false
	LNode* q = p->next;			// ��i�����
	e = q->data;				// ��ֵ��e����Ϊ����ֵ
	p->next = q->next;			// ֱ���õ�i-1�����ָ���i������һ�����
	free(q);					// �ͷŵ�i����㣬��ɾ����������
	return true;
}


// ָ�����ɾ��
// ˼·����Ҫɾ������ǰ�����
// ���ǣ��Ҳ���ǰ������ô���ǻ��ǰ���ǰ���������������ֱ���Һ�̣���ֵ���������൱��ɾ����
bool DeleteNode(LNode* p) {		// Ҫɾ���Ľ�� p
	if (p == NULL) return false;
	LNode* q = p->next;			// q ָ�� p ����һ�����
	p->data = p->next->data;	// q �� data ��ֵ�� p
	p->next = q->next;			// p ָ�� q ����һ�����
	free(q);					// �ͷ�q
	return true;
}

// ��λ����
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

// ��ֵ����
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e) {		// ���ElemType�ǽṹ�壬�͵þ�����бȽ���
		p = p->next;
	}
	return p;
}

// ���ĳ���
int ListLength(LinkList& L) {
	int len = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

// ͷ�巨����������
LinkList ListHeadInsert(LinkList& L) {

	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));	// ����ͷ���
	if (L == NULL) return L;
	L->next = NULL;							// ��ʼ��Ϊ������
	scanf("%d", &x);						// �������ֵ
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));	// �����½��
		if (s == NULL) return L;
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

// β�巨����������
LinkList ListTailInsert(LinkList& L) {
	// ���ñ�βָ�� r��ֱ������������к�����
	int x;
	L = (LinkList)malloc(sizeof(LNode));	// ����ͷ���
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

// ��ӡ����
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

	//printf("ʹ��ͷ�巨����Ԫ���У�����������Ԫ��->��\n");
	//L = ListHeadInsert(L);

	printf("ʹ��β�巨����Ԫ���У�����������Ԫ��->��\n");
	L = ListTailInsert(L);

	PrintList(L);

	e = 23;
	i = 5;
	ListInsert(L, i, e);
	printf("�ڵ� %d ��λ�ò��룺%d\n", i, e);

	PrintList(L);

	i = 2;
	ListDelete(L, i, e);
	printf("ɾ���� %d ��λ�õ�Ԫ�� %d \n", i, e);

	PrintList(L);

	e = 3;
	LNode = LocateElem(L, e);
	printf("��ֵ����->ֵΪ%d��Ԫ�أ��Ѳ��ҵ���Ԫ��\n", LNode->data);

	i = 5;
	LNode = GetElem(L, i);
	printf("��λ����->��%dλԪ�أ��Ѳ��ҵ���Ԫ�أ�ֵΪ%d\n", i, LNode->data);

	ListDelete(L, i, e);
	printf("��λɾ��->��%dλԪ�أ���ɾ����Ԫ�أ�ֵΪ%d\n", i, e);
	PrintList(L);
}

// 1.���
void Del_X_3(LinkList& L, ElemType x) {
	// �ݹ�ʵ���ڵ�����L��ɾ��ֵΪx�Ľ��
	LNode* p;					// pָ���ɾ�����
	if (L == NULL) return;		// �ݹ����
	if (L->data == x) {			// ��L��ָ����ֵΪx
		p = L;					// ɾ��* L�� ����Lָ����һ���
		L = L->next;
		free(p);
		Del_X_3(L, x);			// �ݹ����
	}
	else {						// ��L��ָ����ֵ��Ϊx
		Del_X_3(L->next, x);	// �ݹ����
	}
}

// 2. ���
// ��p��ͷ��βɨ�赥����preָ��*p����ǰ������p��ָ�����ֵΪx����ɾ��������p������һ�����
// ������pre��pָ��ͬ������һ����㡣
void Del_X_1(LinkList& L, ElemType x) {
	// LΪ��ͷ���ĵ�����
	LNode* p = L->next, * pre = L, * q;	// ��p��pre�ĳ�ʼֵ
	while (p != NULL) {
		if (p->data == x) {
			q = p;			// q ָ��ý��
			p = p->next;
			pre->next = p;	// ɾ�� q ָ��Ľ��
			free(q);
		}
		else {
			// pָ��Ľ������ݲ�Ϊx���ͽ����ƶ����Ƶ���һλ
			pre = p;
			p = p->next;
		}
	}
}

// 3. ���
void R_Print(LinkList L) {
	// ��β��ͷ���������L�е�ÿ������ֵ
	if (L->next != NULL) {
		R_Print(L->next);		// �ݹ�
	}
	if (L != NULL) printf("%d ", L->data);
}

int main() {
	test();
	return 0;
}