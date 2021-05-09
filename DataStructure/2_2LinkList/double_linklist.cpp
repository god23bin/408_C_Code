#define _CRT_SECURE_NO_WARNINGS 1

// ˫�����ʵ��

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;					// ������
	struct DNode* prior, * next;	// ǰ�����ָ�룬��̽��ָ��
}DNode, * DLinkList;

// ��ʼ��˫����
bool InitDLinkList(DLinkList& L);

// �ж�˫�����Ƿ�Ϊ��
bool IsEmpty(DLinkList& L);

// ��ֵ���ҺͰ�λ���Һ͵�����һ��
DNode* LocateElem(DLinkList& L, ElemType e);
DNode* GetElem(DLinkList& L, int i);

// ������� - ��� �� p ���֮����� s ���
bool InsertNextDNode(DNode* p, DNode* s);

// ��λ�����
bool ListInsert(DLinkList& L, int i, ElemType e);

// ǰ����� - �� p ���֮ǰ������
bool InsertPrior1(DNode* p, ElemType e);
bool InsertPrior2(DNode* p, DNode* s);

// ��ͷ����
DLinkList ListHeadInsert(DLinkList& L);
// ��β����
DLinkList ListTailInsert(DLinkList& L);

// ɾ������
bool DeleteNextDNode(DNode* p);

bool ListDelete(DLinkList& L, int i, ElemType& e);

// ����˫����
void DestoryDLinkList(DLinkList& L);

// ˫����ı��� - �������
void TravelToNext(DLinkList& L);
void TravelToPrior(DLinkList& L);

bool InitDLinkList(DLinkList& L) {
	L = (DNode*)malloc(sizeof(DNode));	// ����һ��ͷ���
	if (L == NULL) return false;		// �ڴ治�㣬����ʧ��
	L->prior = NULL;	// ͷ���� prior ��Զָ�� NULL 
	L->next = NULL;		// ͷ���֮����ʱ��û�н��
	return true;
}

bool IsEmpty(DLinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}

// ��ֵ����
DNode* LocateElem(DLinkList& L, ElemType e) {
	DNode* p = L->next;
	while (p != NULL && p->data != e) {		// ����һ�������ElemType�ǽṹ�壬�͵þ���Ƚ�
		p = p->next;
	}
	return p;
}

// ��λ����
DNode* GetElem(DLinkList& L, int i) {
	DNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// �� p ���֮����� s ���
//bool InsertNextDNode(DNode* p, DNode* s) {
//	s->next = p->next;
//	p->next->prior = s;		// ��������һ�������룬����ͻ����
//	s->prior = p;
//	p->next = s;
//}
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL) return false;	// ��ָ���ж�
	s->next = p->next;
	if (p->next != NULL)		// ��� p ����к�̽��
		p->next->prior = s;
	s->prior = p;
	p->next = s;
}
// ʵ���˺���������ô��������������ͨ�������ʵ�֣����簴λ�����/ǰ�����

// ��λ�����
bool ListInsert(DLinkList& L, int i, ElemType e) {
	DNode* p = GetElem(L, i - 1);
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL) return false;
	s->data = e;
	return InsertNextDNode(p, s);
}

// ǰ����� - �� p ���֮ǰ������
bool InsertPrior1(DNode* p, ElemType e) {
	DNode* q = p->prior;	// q ָ�� p ��ǰһ�����
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL)return false;
	s->data = e;
	return InsertNextDNode(q, s);
}

bool InsertPrior2(DNode* p, DNode* s) {
	DNode* q = p->prior;
	return InsertNextDNode(q, s);
}

// ��ͷ����
DLinkList ListHeadInsert(DLinkList& L) {
	DNode* s;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		if (s == NULL) return s;
		s->data = x;
		s->next = L->next;
		s->prior = L;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
// ��β����
DLinkList ListTailInsert(DLinkList& L) {
	DNode* s, * r = L;		// r ��βָ�룬ָ�� L��ͷ���
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		if (s == NULL) return s;
		s->data = x;
		s->next = NULL;
		s->prior = r;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	return L;
}

// ɾ������ - ɾ�� p ���ĺ�̽��
bool DeleteNextDNode(DNode* p) {
	if (p == NULL) return false;
	DNode* q = p->next;
	if (q == NULL) return false;	// ˵�� p û�к��
	p->next = q->next;
	if (q->next != NULL)			// q ��㲻�����һ�����
		q->next->prior = p;
	free(q);						// �ͷ� q
	q = NULL;
}

bool ListDelete(DLinkList& L, int i, ElemType& e) {
	DNode* p = GetElem(L, i - 1);
	e = p->next->data;
	return DeleteNextDNode(p);
}

// ����˫����
void DestoryDLinkList(DLinkList& L) {
	// ѭ���ͷŸ������ݽ��
	while (L->next != NULL) {
		DeleteNextDNode(L);		// ɾ��ͷ���ĺ�̽��
	}
	free(L);	// �ͷ�ͷ���
	L = NULL;	// ͷָ��ָ��NULL
}

void TravelToNext(DLinkList& L) {
	DNode* p;
	p = L;
	while (p != NULL) {
		p = p->next;
	}
}

void TravelToPrior(DLinkList& L) {
	DNode* p;
	p = L;
	while (p != NULL) {
		p = p->prior;
	}
}

void PrintList(DLinkList& L) {
	DNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


void testDLinkList() {
	// ��ʼ��˫����
	DLinkList L;
	InitDLinkList(L);

	ElemType e;
	DNode* p, * s;

	int i;

	printf("���ڽ��б�ͷ����˫������->:\n");
	ListHeadInsert(L);

	//printf("���ڽ��б�β����˫������->:\n");
	//ListTailInsert(L);

	PrintList(L);

	e = 3;
	p = LocateElem(L, e);
	printf("��ֵ���� ֵ %d ->:���ҵ���Ϊ %d\n", e, p->data);

	i = 2;
	s = GetElem(L, i);
	printf("��λ���� λ %d ->:���ҵ���Ϊ %d\n", i, s->data);

	i = 2;
	ListDelete(L, i, e);
	printf("ɾ������->:��ɾ��%d��λ�õĽ�㣬ֵΪ%d\n", i, e);

	PrintList(L);
}


int main() {
	testDLinkList();
	return 0;
}