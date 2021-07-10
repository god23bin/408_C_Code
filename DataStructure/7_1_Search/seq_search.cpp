#define _CRT_SECURE_NO_WARNINGS 1

// 顺序查找
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 查找表的数据结构（顺序表）
typedef struct {
	ElemType* elem;
	int length;
}SSTable;

int SeqSearch(SSTable ST, ElemType key);

int SeqSearch(SSTable ST, ElemType key) {
	int i;
	for (i = 0; i < ST.length && ST.elem[i] != key; ++i);
	// 查找成功，则返回元素下标；失败返回-1
	return i == ST.length ? -1 : i;
	//for (int i = 0; i < ST.length; ++i) {
	//	if (ST.elem[i] == key)
	//		return i;
	// 	else
	// 	    return -1;
	//}
}

int SeqSearch(SSTable ST, ElemType key) {
	ST.elem[0] = key;		// 哨兵，数据的话从下标1开始存储
	int i;
	for (i = ST.length; ST.elem[i] != key; --i);
	return i;
}