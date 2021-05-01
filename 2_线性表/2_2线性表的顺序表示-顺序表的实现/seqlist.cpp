#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// �����Ǿ�̬ʵ��
#define MAXSIZE 20			// �������Ա����󳤶�

typedef int ElemType;

// ���Ա��е�Ԫ�ص�λ���Ǵ�1��ʼ�ģ��������Ԫ���±��Ǵ�0��ʼ��
typedef struct {
	ElemType data[MAXSIZE];	// ˳����Ԫ��
	int length;				// ˳���ĵ�ǰ����
}SeqList;

void InitList(SeqList& L) {
	for (int i = 0; i < MAXSIZE; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}


// ������� - ʹ��for�㶨
bool ListInsert(SeqList& L, int i, ElemType e) {
	// �жϲ���λ��i�ĺϷ���
	if (i<1 || i>L.length + 1) {
		return false;
	}
	// ��ǰ�洢�ռ����������ܲ���
	if (L.length >= MAXSIZE) {
		return false;
	}

	// ����i��Ԫ�ؼ�֮���Ԫ�غ���
	for (int j = L.length; j >= i; j--) {	// �Ӻ���ǰ������һ��һ������
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;	// ��˳����i��λ�÷���e
	L.length++;			// ���Ա��ȼ�1
	return true;
}

// ɾ������ - ʹ��for�㶨
bool ListDelete(SeqList& L, int i, ElemType& e) {
	// �ж�ɾ��λ��i�ĺϷ���
	if (i<1 || i>L.length + 1) {
		return false;
	}
	e = L.data[i];	// ����ɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j <= L.length; j++) {	// ��ǰ���������һ��һ����ǰ��
		L.data[j - 1] = L.data[j];
	}
	L.length--;		// ���Ա��ȼ�1
	return true;
}


// ��ֵ���� - ʹ��for�㶨
int LocateElem(SeqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) return i + 1;
	}
	return 0;
}

bool InsertFront(SeqList& L, ElemType e) {
	return ListInsert(L, 1, e);
}

bool InsertBack(SeqList& L, ElemType e) {
	return ListInsert(L, L.length + 1, e);
}

void PrintAll(SeqList L) {
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

void PrintList(SeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

// ԭλ�ý�������-����1
void InvertListWithOnePoint(SeqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}

// ԭλ�ý�������-����2
void InvertListWithTwoPoint(SeqList& L) {
	int i = 0;
	int j = L.length - 1;

	while (i < j) {
		int temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;

		i++;
		j--;
	}

	//for (; i < j; i++, j--) {
	//	int temp = L.data[i];
	//	L.data[i] = L.data[j];
	//	L.data[j] = temp;
	//}
}


void test() {
	SeqList L;
	InitList(L);
	ElemType e;

	PrintList(L);

	for (int i = 10; i > 0; i--) {
		e = i;
		InsertFront(L, e);
	}

	PrintList(L);

	//e = 11;
	//InsertBack(L, e);

	PrintList(L);

	InvertListWithOnePoint(L);

	PrintList(L);

	InvertListWithTwoPoint(L);

	PrintList(L);
}

int main() 
{
	test();
	return 0;
}


