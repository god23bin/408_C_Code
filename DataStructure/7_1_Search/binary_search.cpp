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