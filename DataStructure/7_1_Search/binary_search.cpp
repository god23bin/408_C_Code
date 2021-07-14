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

int BinarySearch(SSTable L, ElemType key);

int BinarySearch(SSTable L, ElemType key) {
	int low = 0, high = L.length - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;			// 取中间位置
		if (L.elem[mid] == key)
			return mid;					// 查找成功则返回所在位置
		else if (L.elem[mid] > key)
			high = mid - 1;				// 从前半部分继续查找
		else
			low = mid + 1;				// 从后半部分继续查找
	}
	return -1;
}



// 折半查找练习
int BS1(SSTable L, int key) {
	int low = 0, high = L.length, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.elem[mid] == key) {
			return mid;
		}
		else if (L.elem[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}



// 立马能写出来
int BS1(SSTable L, int key) {
	int low = 0, high = L.length, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;
		else if (L.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


int BS2(int arr[], int len, int key) {
	int low = 0, high = len - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


int BS3(int arr[], int len, int key) {
	int low = 0, high = len - 1, mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key) {
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}
