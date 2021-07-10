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

int SeqSearch(SSTable ST, ElemType key);

int SeqSearch(SSTable ST, ElemType key) {
	int i;
	for (i = 0; i < ST.length && ST.elem[i] != key; ++i);
	// ���ҳɹ����򷵻�Ԫ���±ꣻʧ�ܷ���-1
	return i == ST.length ? -1 : i;
	//for (int i = 0; i < ST.length; ++i) {
	//	if (ST.elem[i] == key)
	//		return i;
	// 	else
	// 	    return -1;
	//}
}

int SeqSearch(SSTable ST, ElemType key) {
	ST.elem[0] = key;		// �ڱ������ݵĻ����±�1��ʼ�洢
	int i;
	for (i = ST.length; ST.elem[i] != key; --i);
	return i;
}