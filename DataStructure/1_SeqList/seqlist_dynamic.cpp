#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE 20
#define EXTSIZE 5

typedef int ElemType;

typedef struct {
	ElemType* data;
	int maxsize;
	int length;
}SeqList;

bool InitList(SeqList& L);
bool DestoryList(SeqList& L);
bool ExtendList(SeqList& L);
bool ListInsert(SeqList& L, int i, ElemType e);
bool InsertFront(SeqList& L, ElemType e);
bool InsertBack(SeqList& L, ElemType e);
int ListLength(SeqList& L);
bool GetElem(SeqList L, int i, ElemType& e);
bool ClearList(SeqList& L);
bool IsEmpty(SeqList L);
void PrintList(SeqList L);
void PrintAll(SeqList L);
int LocateElem(SeqList L, ElemType e);
bool ListDelete(SeqList& L, int i, ElemType& e);
bool DeleteFront(SeqList& L, ElemType& e);
bool DeleteBack(SeqList& L, ElemType& e);

// ˳���L�ĳ�ʼ��������
bool InitList(SeqList& L) {
	L.data = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	if (L.data == NULL) {
		return false;
	}
	L.maxsize = INITSIZE;
	memset(L.data, 0, sizeof(ElemType) * L.maxsize);
	L.length = 0;
	return true;
}

// ����˳���L��
bool DestoryList(SeqList& L) {
	free(L.data);
	L.maxsize = 0;
	L.length = 0;
	return true;
}

// ��չ˳�����ڴ�ռ䣬����ֵ��0-ʧ�ܣ�1-�ɹ���
bool ExtendList(SeqList& L) {
	ElemType* newdata = (ElemType*)malloc(sizeof(ElemType) * (L.maxsize + EXTSIZE));
	if (newdata == NULL) {
		return false;
	}
	else {
		memset(newdata, 0, sizeof(ElemType) * (L.maxsize + EXTSIZE));
		memcpy(newdata, L.data, sizeof(ElemType) * L.maxsize);
		free(L.data);
		L.data = newdata;
		L.maxsize = L.maxsize + EXTSIZE;
		return true;
	}
}

// ��˳���L�ĵ�i��λ�ò���Ԫ��e������ֵ��0-ʧ�ܣ�1-�ɹ���
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= INITSIZE) {
		ExtendList(L);
	}
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// ��˳���L��ͷ������Ԫ��e������ֵ��0-ʧ�ܣ�1-�ɹ���
bool InsertFront(SeqList& L, ElemType e) {
	return ListInsert(L, 1, e);
}

// ��˳���L��β������Ԫ��e������ֵ��0-ʧ�ܣ�1-�ɹ���
bool InsertBack(SeqList& L, ElemType e) {
	return ListInsert(L, L.length + 1, e);
}

// ��˳���ĳ��ȣ�����ֵ��>=0-��LԪ�صĸ�����
int ListLength(SeqList& L) {
	return L.length;
}

// ��ȡ˳����е�i��Ԫ�ص�ֵ�������e�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
bool GetElem(SeqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) return false;
	if (L.length == 0) return false;
	e = L.data[i - 1];
	return true;
}

// ���˳���
bool ClearList(SeqList& L) {
	memset(L.data, 0, sizeof(ElemType) * L.maxsize);
	return true;
}

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
bool IsEmpty(SeqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}

// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(SeqList L) {
	printf("\n");
	if (L.length == 0) return;
	for (int i = 0; i < L.length; i++) {
		printf("%3d ", L.data[i]);
	}
	printf("\n");
}

// ��ӡ����˳���
void PrintAll(SeqList L) {
	printf("\n");
	for (int i = 0; i < L.maxsize; i++) {
		printf("%3d ", L.data[i]);
	}
	printf("\n");
}

// ����e��˳���L�е�λ�ã�����ֵ��0-Ԫ��e�ڱ�L�в����ڣ�>0Ԫ��e�ڱ�L�е�λ�á�
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (e == L.data[i]) return i + 1;
	}
	return 0;
}

// ɾ��˳���L�еĵ�i��Ԫ�أ�����ֵ��0-λ��i���Ϸ���1-�ɹ���
bool ListDelete(SeqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length) return false;
	if (L.length == 0) return false;

	e = L.data[i - 1];
	for (int j = i; j <= L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

// ɾ��˳���L��ͷԪ�أ�����ֵ��0-λ��i���Ϸ���1-�ɹ���
bool DeleteFront(SeqList& L, ElemType& e) {
	return ListDelete(L, 1, e);
}

// ɾ��˳���L��βԪ�أ�����ֵ��0-λ��i���Ϸ���1-�ɹ���
bool DeleteBack(SeqList& L, ElemType& e) {
	return ListDelete(L, L.length, e);
}


void test() {
	SeqList L;
	InitList(L);
	ElemType e;

	PrintList(L);

	// ����Ԫ��
	for (int i = 11; i > 0; i--) {
		e = i;
		InsertFront(L, e);
	}

	PrintList(L);

	// ɾ����βԪ��
	DeleteBack(L, e);

	PrintList(L);

	// ��ȡĳ��λ���ϵ�Ԫ��
	int x = 3;
	GetElem(L, x, e);

	printf("\n��ȡ��%d��λ�õ�Ԫ�أ�Ϊ��%d \n", x, e);

	// ��ȡĳԪ��λ��

	LocateElem(L, e);
	printf("\nԪ�� %d ��λ��Ϊ��%d \n", e, x);

	// ��������Ԫ�أ����Զ���չ
	for (int i = 11; i <= 22; i++) {
		e = i;
		InsertBack(L, e);
	}
	PrintAll(L);

}


int main() {
	test();
	return 0;
}