#define _CRT_SECURE_NO_WARNINGS 1

// �����ֵܱ�ʾ����˳�� + ��ʽ�洢��

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 30

typedef char ElemType;

typedef struct CSNode {
	ElemType data;
	// ��һ�����Ӻ����ֵ�ָ��
	struct CSNode* firstChild, * nextSibling;
}CSNode, *CSTree;

// ���Ͷ�����ת��������