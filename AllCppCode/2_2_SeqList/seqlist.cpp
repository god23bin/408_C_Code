#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// 这里是静态实现
#define MAXSIZE 20			// 定义线性表的最大长度

typedef int ElemType;

// 线性表中的元素的位序是从1开始的，而数组的元素下标是从0开始的
typedef struct {
	ElemType data[MAXSIZE];	// 顺序表的元素
	int length;				// 顺序表的当前长度
}SeqList;

void InitList(SeqList& L) {
	for (int i = 0; i < MAXSIZE; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}


// 插入操作 - 使用for搞定
bool ListInsert(SeqList& L, int i, ElemType e) {
	// 判断插入位置i的合法性
	if (i<1 || i>L.length + 1) {
		return false;
	}
	// 当前存储空间已满，不能插入
	if (L.length >= MAXSIZE) {
		return false;
	}

	// 将第i个元素及之后的元素后移
	for (int j = L.length; j >= i; j--) {	// 从后往前操作，一个一个后移
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;	// 在顺序表第i个位置放入e
	L.length++;			// 线性表长度加1
	return true;
}

// 删除操作 - 使用for搞定
bool ListDelete(SeqList& L, int i, ElemType& e) {
	// 判断删除位置i的合法性
	if (i<1 || i>L.length + 1) {
		return false;
	}
	e = L.data[i];	// 将被删除的元素赋值给e
	for (int j = i; j <= L.length; j++) {	// 从前往后操作，一个一个往前移
		L.data[j - 1] = L.data[j];
	}
	L.length--;		// 线性表长度减1
	return true;
}


// 按值查找 - 使用for搞定
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

// 题目开始
// 1. 解答
//ElemType DeleteListMinData(SeqList& L) {
//	if (L.length == 0) {
//		printf("顺序表为空");
//	}
//	ElemType min = L.data[0];
//	int j;
//	for (int i = 1; i < L.length; i++) {
//		if (min > L.data[i]) {
//			min = L.data[i];
//			j = i + 1;	// 记录最小值所在的位置
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
	min = L.data[0];		// 假设0号元素的值最小
	int position = 0;		// 记录最小值位置
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

// 2. 解答
// 原位置进行逆置-方法1
void InvertListWithOnePoint(SeqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}

// 原位置进行逆置-方法2
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
	ElemType temp;				// 辅助变量
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];		// 头尾往中间靠，进行交换
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

// 3.解答
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

// 用k记录顺序表中不等于x的元素个数（即需要保存的元素个数），边扫描L边统计k，并将不等于x的元素向前移动k个位置，最后修改L的长度
void del_x_1(SeqList& L, ElemType x) {
	int k = 0;							// k记录 值不等于 x 的元素个数
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k] = L.data[i];
			k++;						// 不等于 x 的元素个数加1
		}
	}
	L.length = k;
}

// 用k记录顺序表L中等于x的元素个数，边扫描L边统计k，并将不等于x的元素前移k个位置，最后修改L的长度
void del_x_2(SeqList& L, ElemType x) {
	int k = 0, i = 0;					// k记录 值等于 x 的元素个数
	while (i < L.length) {
		if (L.data[i] == x) {
			k++;
		}
		else {
			L.data[i - k] = L.data[i];	// 当前元素前移k个位置
		}
		i++;
	}
	L.length = L.length - k;
}

// 4.解答

bool DeleteValueBetweenST(SeqList& L, int s, int t) {
	if (s >= t) {
		printf("s大于等于t，不合理\n");
		return false;
	}
	if (L.length == 0) {
		printf("顺序表为空\n");
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

// 5. 解答
bool DeleteValueBetweenST2(SeqList& L, int s, int t) {
	if (s >= t) {
		printf("s大于等于t，不合理\n");
		return false;
	}
	if (L.length == 0) {
		printf("顺序表为空\n");
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

// 6. 解答
//bool DeleteAllDuplicate(SeqList& L) {
//	if (L.length == 0) {
//		return false;
//	}
//	int k = 0;	// 统计相同个数
//	int i = 0;	// 记录需要替换的位置
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

// 7. 解答
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

// 8. 解答
//bool Reverse2List(SeqList& L1, SeqList& L2) {}

void Reverse(ElemType A[], int left, int right, int arraySize) {
	// 逆转(aleft, aleft + 1, ..., aright)为(aright, arigth - 1, ..., aleft)
	if (left >= right || right >= arraySize) return;

	int mid = (left + right) / 2;
	for (int i = 0; i <= mid - left; i++) {
		ElemType temp = A[left + i];
		A[left + i] = A[right - i];
		A[right - i] = temp;
	}
}

void Exchange(ElemType A[], int m, int n, int arraySize) {
	// 数组A[m+n]中，从0到m-1存放顺序表(a1,a2,...,am)，从m到m+n-1存放顺序表(b1,...,bn)
	// 算法将这两个表位置互换
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