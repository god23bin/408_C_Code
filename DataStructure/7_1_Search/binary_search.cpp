#define _CRT_SECURE_NO_WARNINGS 1

// ˳�����
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// ���ұ�����ݽṹ��˳���
typedef struct {
	ElemType* elem;
	int length;
}SSTable;

int BinarySearch(SSTable L, ElemType key);

int BinarySearch(SSTable L, ElemType key) {
	int low = 0, high = L.length - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;			// ȡ�м�λ��
		if (L.elem[mid] == key)
			return mid;					// ���ҳɹ��򷵻�����λ��
		else if (L.elem[mid] > key)
			high = mid - 1;				// ��ǰ�벿�ּ�������
		else
			low = mid + 1;				// �Ӻ�벿�ּ�������
	}
	return -1;
}



// �۰������ϰ
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



// ������д����
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
