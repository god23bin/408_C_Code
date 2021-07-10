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

// ��Ŀ��ʼ
// 1. ���
//ElemType DeleteListMinData(SeqList& L) {
//	if (L.length == 0) {
//		printf("˳���Ϊ��");
//	}
//	ElemType min = L.data[0];
//	int j;
//	for (int i = 1; i < L.length; i++) {
//		if (min > L.data[i]) {
//			min = L.data[i];
//			j = i + 1;	// ��¼��Сֵ���ڵ�λ��
//		}
//	}
//	ListDelete(L, j, min);
//	ListInsert(L, j, L.data[L.length - 1]);
//	return min;
//}



bool Del_Min(SeqList& L, ElemType& min) {
	if (L.length == 0) {
		return false;
	}
	min = L.data[0];		// ����0��Ԫ�ص�ֵ��С
	int position = 0;		// ��¼��Сֵλ��
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] < min) {
			min = L.data[i];
			position = i;
		}
	}
	L.data[position] = L.data[L.length - 1];
	L.length--;
	return true;
}

// 2. ���
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

void Reverse(SeqList& L) {
	ElemType temp;				// ��������
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];		// ͷβ���м俿�����н���
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

// 3.���
bool DeleteListValueWithAllSame(SeqList& L, ElemType e) {
	if (L.length == 0) return false;
	int k = 0;
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
	}
	L.length = L.length - k;
	return true;
}

// ��k��¼˳����в�����x��Ԫ�ظ���������Ҫ�����Ԫ�ظ���������ɨ��L��ͳ��k������������x��Ԫ����ǰ�ƶ�k��λ�ã�����޸�L�ĳ���
void del_x_1(SeqList& L, ElemType x) {
	int k = 0;							// k��¼ ֵ������ x ��Ԫ�ظ���
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;						// ������ x ��Ԫ�ظ�����1
		}
	}
	L.length = k;
}

// ��k��¼˳���L�е���x��Ԫ�ظ�������ɨ��L��ͳ��k������������x��Ԫ��ǰ��k��λ�ã�����޸�L�ĳ���
void del_x_2(SeqList& L, ElemType x) {
	int k = 0, i = 0;					// k��¼ ֵ���� x ��Ԫ�ظ���
	while (i < L.length) {
		if (L.data[i] == x) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];	// ��ǰԪ��ǰ��k��λ��
		}
		i++;
	}
	L.length = L.length - k;
}

// 4.���

bool DeleteValueBetweenST(SeqList& L, int s, int t) {
	if (s >= t) {
		printf("s���ڵ���t��������\n");
		return false;
	}
	if (L.length == 0) {
		printf("˳���Ϊ��\n");
		return false;
	}
	if (t < L.data[0] || s > L.data[L.length - 1]) {
		return true;
	}
	if (s < L.data[0] && t > L.data[L.length - 1]) {
		L.length = 0;
		return true;
	}
	int k = 0;
	for (int position = 0; position < L.length; position++) {
		if (L.data[position] > s && L.data[position] < t) {
			k++;
		}
		else {
			L.data[position - k] = L.data[position];
		}
	}
	L.length = L.length - k;
	return true;
}

// 5. ���
bool DeleteValueBetweenST2(SeqList& L, int s, int t) {
	if (s >= t) {
		printf("s���ڵ���t��������\n");
		return false;
	}
	if (L.length == 0) {
		printf("˳���Ϊ��\n");
		return false;
	}
	int k = 0;
	for (int position = 0; position < L.length; position++) {
		if (L.data[position] > s && L.data[position] < t) {
			k++;
		}
		else {
			L.data[position - k] = L.data[position];
		}
	}
	L.length = L.length - k;
	return true;
}

// 6. ���
//bool DeleteAllDuplicate(SeqList& L) {
//	if (L.length == 0) {
//		return false;
//	}
//	int k = 0;	// ͳ����ͬ����
//	int i = 0;	// ��¼��Ҫ�滻��λ��
//	for (int j = 1; j < L.length; j++) {
//		if (L.data[j - 1] == L.data[j]) {
//			k++;
//		}
//		else {
//			if(L.data[j] == L.data[j + 1])
//			if (k == 0) {
//				i++;
//			}
//			else {
//				L.data[i] = L.data[j];
//				i++;
//			}
//		}
//	}
//	L.length = i;
//	return true;
//}

bool DeleteS(SeqList& L) {
	if (L.length == 0) {
		return false;
	}

	int k = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] == L.data[i - 1]) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];
		}
	}
	L.length = L.length - k;
	return true;
}

bool Delete_Same(SeqList& L) {
	if (L.length == 0) {
		return false;
	}

	int i, j;
	for (i = 0, j = 1; j < L.length; j++) {
		if (L.data[i] != L.data[j]) {
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
	return true;
}

// 7. ���
bool MergeNewList(SeqList& L1, SeqList& L2, SeqList& L3) {
	if ((L1.length + L2.length) > MAXSIZE) return false;

	int i = 0, j = 0, k = 0;
	// 
	while ((i < L1.length) && (j < L2.length)) {
		if (L1.data[i] < L2.data[j]) {
			L3.data[k] = L1.data[i];
			i++;
			k++;
		}
		else if (L1.data[i] > L2.data[j]) {
			L3.data[k] = L2.data[j];
			j++;
			k++;
		}
	}

	while (i < L1.length) {
		L3.data[k] = L1.data[i];
		i++;
		k++;
	}

	while (j < L2.length) {
		L3.data[k] = L2.data[j];
		j++;
		k++;
	}

	L3.length = k;

	return true;
}

bool Merge(SeqList A, SeqList B, SeqList& C) {
	if (A.length + B.length > MAXSIZE) return false;

	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length) {
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length)
		C.data[k++] = A.data[i++];
	while (j < B.length)
		C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}

// 8. ���
//bool Reverse2List(SeqList& L1, SeqList& L2) {}

void Reverse(ElemType A[], int left, int right, int arraySize) {
	// ��ת(aleft, aleft + 1, ..., aright)Ϊ(aright, arigth - 1, ..., aleft)
	if (left >= right || right >= arraySize) return;

	int mid = (left + right) / 2;
	for (int i = 0; i <= mid - left; i++) {
		ElemType temp = A[left + i];
		A[left + i] = A[right - i];
		A[right - i] = temp;
	}
}

void Exchange(ElemType A[], int m, int n, int arraySize) {
	// ����A[m+n]�У���0��m-1���˳���(a1,a2,...,am)����m��m+n-1���˳���(b1,...,bn)
	// �㷨����������λ�û���
	Reverse(A, 0, m + n - 1, arraySize);
	Reverse(A, 0, n - 1, arraySize);
	Reverse(A, n, m + n - 1, arraySize);
}



//void test() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		e = i;
//		InsertFront(L, e);
//	}
//
//	PrintList(L);
//
//	//e = 11;
//	//InsertBack(L, e);
//
//	PrintList(L);
//
//	InvertListWithOnePoint(L);
//
//	PrintList(L);
//
//	InvertListWithTwoPoint(L);
//
//	PrintList(L);
//}

//void test1() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		e = i;
//		InsertFront(L, e);
//	}
//
//	PrintList(L);
//
//	ElemType min = 0;
//	Del_Min(L, min);
//
//	PrintList(L);
//}

//void test3() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		e = i;
//		InsertFront(L, e);
//	}
//
//	e = 10;
//	InsertFront(L, e);
//
//	PrintList(L);
//
//	DeleteListValueWithAllSame(L, e);
//
//	PrintList(L);
//}

//void test4() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		e = i;
//		InsertFront(L, e);
//	}
//
//
//	PrintList(L);
//
//	//DeleteValueBetweenST(L, 2,5);
//	//DeleteValueBetweenST(L, 5,15);
//	DeleteValueBetweenST(L, -1,15);
//	//DeleteValueBetweenST(L, -1,5);
//
//	PrintList(L);
//}

//void test5() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		e = i;
//		InsertFront(L, e);
//	}
//
//	e = 23;
//	InsertFront(L, e);
//	e = 25;
//	InsertFront(L, e);
//	e = 22;
//	InsertFront(L, e);
//
//	PrintList(L);
//
//	//DeleteValueBetweenST(L, 2,5);
//	//DeleteValueBetweenST(L, 5,15);
//	//DeleteValueBetweenST2(L, -1, 15);
//	DeleteValueBetweenST2(L, 5, 23);
//	//DeleteValueBetweenST(L, -1,5);
//
//	PrintList(L);
//}

//void test6() {
//	SeqList L;
//	InitList(L);
//	ElemType e;
//
//	PrintList(L);
//
//	for (int i = 10; i > 0; i--) {
//		scanf("%d", &e);
//		InsertBack(L, e);
//	}
//
//	PrintList(L);
//
//	//DeleteAllDuplicate(L);
//	DeleteS(L);
//
//	PrintList(L);
//}

void test7() {
	SeqList L1;
	SeqList L2;
	SeqList L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	ElemType e1;
	ElemType e2;

	for (int i = 10; i > 0; i -= 2) {
		e1 = i;
		InsertFront(L1, e1);
	}

	PrintList(L1);

	for (int j = 9; j > 0; j -= 2) {
		e2 = j;
		InsertFront(L2, e2);
	}

	PrintList(L2);

	MergeNewList(L1, L2, L3);

	PrintList(L3);
}

int main()
{
	//test();
	//test1();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}