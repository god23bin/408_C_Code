#define _CRT_SECURE_NO_WARNINGS 1


// ��������˳��洢��ֻ������ȫ������
// һ�������˳��洢

#include <stdio.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct {
	ElemType value;	// ����е�����Ԫ��
	bool isEmpty;	// ����Ƿ�Ϊ��
}TreeNode;

typedef struct {
	TreeNode t[MAXSIZE];
}Tree;

bool InitTree(Tree& tree);

bool InitTree(Tree& tree) {
	for (int i = 0; i < MAXSIZE; i++) {
		tree.t[i].isEmpty = true;
	}
	return true;
}