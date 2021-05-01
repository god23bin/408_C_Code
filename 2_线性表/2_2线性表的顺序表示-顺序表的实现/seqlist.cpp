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


