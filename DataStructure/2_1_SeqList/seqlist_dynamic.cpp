#define _CRT_SECURE_NO_WARNINGS 1

// 顺序表的动态实现

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

// 顺序表L的初始化操作。
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

// 销毁顺序表L。
bool DestoryList(SeqList& L) {
	free(L.data);
	L.maxsize = 0;
	L.length = 0;
	return true;
}

// 扩展顺序表的内存空间，返回值：0-失败；1-成功。
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

// 在顺序表L的第i个位置插入元素e，返回值：0-失败；1-成功。
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

// 在顺序表L的头结点插入元素e，返回值：0-失败；1-成功。
bool InsertFront(SeqList& L, ElemType e) {
	return ListInsert(L, 1, e);
}

// 在顺序表L的尾结点插入元素e，返回值：0-失败；1-成功。
bool InsertBack(SeqList& L, ElemType e) {
	return ListInsert(L, L.length + 1, e);
}

// 求顺序表的长度，返回值：>=0-表L元素的个数。
int ListLength(SeqList& L) {
	return L.length;
}

// 获取顺序表中第i个元素的值，存放在e中，返回值：0-失败；1-成功。
bool GetElem(SeqList L, int i, ElemType& e) {
	if (i<1 || i>L.length) return false;
	if (L.length == 0) return false;
	e = L.data[i - 1];
	return true;
}

// 清空顺序表。
bool ClearList(SeqList& L) {
	memset(L.data, 0, sizeof(ElemType) * L.maxsize);
	return true;
}

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
bool IsEmpty(SeqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}

// 打印顺序表中全部的元素。
void PrintList(SeqList L) {
	printf("\n");
	if (L.length == 0) return;
	for (int i = 0; i < L.length; i++) {
		printf("%3d ", L.data[i]);
	}
	printf("\n");
}

// 打印整张顺序表
void PrintAll(SeqList L) {
	printf("\n");
	for (int i = 0; i < L.maxsize; i++) {
		printf("%3d ", L.data[i]);
	}
	printf("\n");
}

// 查找e在顺序表L中的位置，返回值：0-元素e在表L中不存在，>0元素e在表L中的位置。
int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (e == L.data[i]) return i + 1;
	}
	return 0;
}

// 删除顺序表L中的第i个元素，返回值：0-位置i不合法；1-成功。
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

// 删除顺序表L中头元素，返回值：0-位置i不合法；1-成功。
bool DeleteFront(SeqList& L, ElemType& e) {
	return ListDelete(L, 1, e);
}

// 删除顺序表L中尾元素，返回值：0-位置i不合法；1-成功。
bool DeleteBack(SeqList& L, ElemType& e) {
	return ListDelete(L, L.length, e);
}


void test() {
	SeqList L;
	InitList(L);
	ElemType e;

	PrintList(L);

	// 插入元素
	for (int i = 11; i > 0; i--) {
		e = i;
		InsertFront(L, e);
	}

	PrintList(L);

	// 删除表尾元素
	DeleteBack(L, e);

	PrintList(L);

	// 获取某个位置上的元素
	int x = 3;
	GetElem(L, x, e);

	printf("\n获取第%d个位置的元素，为：%d \n", x, e);

	// 获取某元素位置

	LocateElem(L, e);
	printf("\n元素 %d 的位置为：%d \n", e, x);

	// 继续插入元素，看自动扩展
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